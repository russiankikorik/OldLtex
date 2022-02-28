sources := $(wildcard *.c)
objects := $(patsubst %.c, %.o, $(sources))
target_static := libmy_darray.a
target_dynamic := libmy_darray.so

.PHONEY: static dynamic clean 

all: static dynamic

static:
	$(foreach src, $(sources), gcc -c $(src);)
	ar rc $(target_static) $(objects)
	rm -rf *.o

dynamic:
	$(foreach src, $(sources), gcc -fPIC -c $(src);)
	gcc -shared $(objects) -o $(target_dynamic) 
	rm -rf *.o
clean:
	rm -rf $(target_static) $(target_dynamic)


