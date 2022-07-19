#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void main() {
    pid_t ch1pid = fork();
    pid_t ch2pid = fork();
    pid_t chpid = -2;
    int wstatus;
    if ((0 == ch1pid && 0 != ch2pid) || (0 != ch1pid && 0 == ch2pid)) {
        chpid = fork();
    }
    pid_t pid = getpid();
    pid_t ppid = getppid();
    if (0 == ch1pid && 0 == ch2pid || 0 == chpid) {
        printf("pid = %d, ppid = %d\n", pid, ppid);
        exit(0);
    }
    if (chpid > 0) {
        waitpid(chpid, &wstatus, 0);
    }
    if (ch1pid > 0) {
        waitpid(ch1pid, &wstatus, 0);
    }
    if (ch2pid > 0) {
        waitpid(ch2pid, &wstatus, 0);
    }
    printf("pid = %d, ppid = %d\n", pid, ppid);
    exit(0);
}
