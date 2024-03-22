all: scanner

flex:
	flex --outfile=scanner.c scanner.l 

scanner: flex yacc
	gcc utilities/token_list.c -c
	gcc utilities/comment_stack.c -c
	gcc scanner.c parser.c token_list.o comment_stack.o -o alphac 
	./alphac ../test.txt   

yacc:
	bison --yacc --defines --output=parser.c parser.y

clean:
	rm -f scanner.c *.o alphac
