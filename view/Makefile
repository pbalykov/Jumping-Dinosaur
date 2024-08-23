all: all, clear

all: view.o roadView.o
	@printf "Creating view object files"

%.o: %.c
	gcc -c $< -o $*.o 


clear: 
	rm *.o
