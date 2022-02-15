source1 := struct_union_enum.c
target1 := struct_union_enum

source2 := phonebook.c
target2 := phonebook

.PHONEY := clean

all: $(target1) $(target2) 

$(target1) : $(source1)
	gcc -o $(target1) $(source1) -g
$(target2) : $(source2)
	gcc -o $(target2) $(source2) -g
clean:
	rm -rf $(target1) $(target2) 
