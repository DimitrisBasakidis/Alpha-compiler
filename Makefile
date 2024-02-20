all: scanner

flex:
	flex --outfile=scanner.c scanner.l 

scanner: flex
	gcc utilities/token_list.c -c
	gcc scanner.c  token_list.o -o alphac
	./alphac ../test.txt   
