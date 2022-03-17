sources := $(shell ls ./source/my_*.c)
objects := $(sources:.c=.o)
plg := $(patsubst ./source/my_%.o,./plugins/libmy_%.so,$(objects))
target := calculator



.PHONEY: use_static use_dynamic clean plugs

all: use_static

plugs:
	$(foreach src, $(sources), gcc -fPIC -c $(src) -o $(src:.c=.o);)
	$(foreach obj, $(objects), gcc -shared $(obj) \
	-o $(patsubst ./source/my_%.o,./plugins/libmy_%.so,$(obj)) -lm;)
	rm -rf $(objects)

use_static:
	gcc -o $(target) ./source/main.c -L../my_darray -l:libmy_darray.a -ldl -g

use_dynamic:
	gcc -o $(target) ./source/main.c -L../my_darray -l:libmy_darray.so -ldl
clean:
	rm -rf $(target)
	rm -rf $(plg)


