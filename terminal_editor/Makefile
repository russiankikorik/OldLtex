source := $(wildcard *.c)
target := my_editor

.PHONY: editor

editor:
	gcc -o $(target) $(source) -lncurses

clean:
	rm -rf $(target)
