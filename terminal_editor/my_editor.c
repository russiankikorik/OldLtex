#include <stdlib.h>
#include <ncurses.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
	printf("No input specified\n");
	exit(1);
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
	printf("Cannot open file %s\n", argv[1]);
	exit(1);
    }
    char buf[7001];
    int count = read(fd, buf, 7000);
    close(fd);
    if (count == -1) {
	printf("Error while reading file %s\n", argv[0]);
	exit(1);
    }
    buf[ count < 7000 ? count : 7000 ] = '\0';
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    attron(A_BOLD);
    printw("F1 - Exit | F3 - Save");
    attroff(A_BOLD);
    int y, x;
    y = 1;
    x = 0;
    mvaddstr(y, x, buf);
    move(y, x);
    refresh();
    int ch;
    int row, col;
    char save_fname[100];
    char strbuf[500];
    getmaxyx(stdscr, row, col);
    mvprintw(row - 1, 0, "kuku yopta");
    move(y, x);
    while ( (ch = getch()) != KEY_F(1)) {
	getmaxyx(stdscr, row, col);
	move(y, x);
	switch(ch) {
	    case KEY_F(3):
		echo();
		move(row - 1, 0);
		clrtobot();
		mvprintw(row - 1, 0, "Output file name: ");
		//refresh();
		getstr(save_fname);
		noecho();
		if (strcmp(argv[1], save_fname) == 0) {
		    move(row - 1, 0);
		    clrtobot();
		    mvprintw(row - 1, 0, "WARNING: trying to save to the same file, \
do it AT YOUR OWN RISK! F4 - continue, else - any key");
		    //refresh();
		    int f4 = getch();
		    if (!(f4 == KEY_F(4))) {
			break;
		    }
		}
		int fd = open(save_fname, O_WRONLY | O_CREAT, S_IRWXU);
		if (fd == -1) {
		    move(row - 1, 0);
		    clrtobot();
		    mvprintw(row - 1, 0, "Cannot open file %s", save_fname);
		    //refresh();
		    break;
		}
		getmaxyx(stdscr, row, col);
		int i;
		for (i = 1; i < row - 1; i++) {
		    int j;
		    int all_spaces = 1;
		    int trailing_spaces = 0;
		    for (j = 0; j < col - 1; j++) {
			strbuf[j] = mvinch(i, j) & A_CHARTEXT;
			if (strbuf[j] != ' ') {
			    all_spaces = 0;
			    trailing_spaces = 0;
			}
			else {
			    trailing_spaces++;
			}
		    }
		    if (all_spaces) {
			break;
		    }
		    int chek = write(fd, strbuf, j - trailing_spaces);
		    if (chek == -1) {
			move(row - 1, 0);
			clrtobot();
			mvprintw(row - 1, 0, "Error on write");
			//refresh();
			break;
		    }
		    chek = write(fd, "\n", 1);
		}
		int chek;
		chek = fsync(fd);
		move(row - 1, 0);
		clrtobot();
		if (chek == -1) {
		    mvprintw(row - 1, 0, "Error on fsync call");
		}
		else {
		    mvprintw(row - 1, 0, "%d lines printed", i - 1);
		}
		chek = close(fd);
		if (chek == - 1) {
		    move(row - 1, 0);
		    clrtobot();
		    mvprintw(row - 1, 0, "Failure to close");
		    refresh();
		}
		move(y, x);
		break;

	    case KEY_LEFT:
		if (x > 0) {
		    x--;
		    move(y, x);
		}
		break;
	    case KEY_RIGHT:
		if (x < col - 1) {
		    x++;
		    move(y, x);
		}
		break;
	    case KEY_UP:
		if (y > 1) {
		    y--;
		    move(y, x);
		}
		break;
	    case KEY_DOWN:
		if (y < row - 2) {
		    y++;
		    move(y, x);
		}
		break;
	    default:
		if (!iscntrl(ch)) {
		addch(ch);
		if (x < col - 1) {
		    x++;
		    move(y, x);
		}
		break;
		refresh();
		}
	}
    }
    endwin();
    return 0;
}

