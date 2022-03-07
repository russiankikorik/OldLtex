sources := $(wildcard *.c)
objects := $(patsubst %.c, %.o, $(sources))
target := phonebook

.PHONEY: use_static use_dynamic clean 

all: use_static

use_static:
	gcc -o $(target) $(sources) -L../my_darray -l:libmy_darray.a

use_dynamic:
	gcc -o $(target) $(sources) -L../my_darray -l:libmy_darray.so
clean:
	rm -rf $(target)


