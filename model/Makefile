all: all, clear

all: view.o roadView.o
	@printf "Creating Model object files"

%.o: %.c
	gcc -c $< -o $*.o 


clear: 
	rm *.o
