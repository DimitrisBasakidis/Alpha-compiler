all: scanner

flex:
	flex --outfile=scanner.c scanner.l 

scanner: flex
	gcc utilities/token_list.c -c
	gcc utilities/comment_stack.c -c
	gcc scanner.c  token_list.o comment_stack.o -o alphac
	./alphac ../test.txt   

clean:
	rm -f scanner.c token_list.o alphac
