source1 := task1.c
target1 := task1

source2 := task2.c
target2 := task2

source3 := task3.c
target3 := task3

source4 := task4.c
target4 := task4

.PHONEY := clean

all: $(target1) $(target2) $(target3) $(target4)

$(target1) : $(source1)
	gcc -o $(target1) $(source1) -g
$(target2) : $(source2)
	gcc -o $(target2) $(source2) -g
$(target3) : $(source3)
	gcc -o $(target3) $(source3) -g
$(target4) : $(source4)
	gcc -o $(target4) $(source4) -g
clean:
	rm -rf $(target1) $(target2) $(target3) $(target4)
