sources := $(shell ls *.c)
target := libmy_darray.a

.PHONEY: objects library clean

all: objects library

library:
	ar rc $(target) $(shell ls *.o)
	rm -rf *.o

objects:
	$(foreach src, $(sources), gcc -c $(src);)

clean:
	rm -rf $(target)
	rm -rf *.o


