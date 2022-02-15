sources0 := password.c
target0 := password

.PHONEY := clean

$(target0) : $(sources)
	gcc -o $(target0) $(sources0) -fno-stack-protector -g
clean:
	rm -rf $(target0)
