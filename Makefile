all: scanner

flex:
	flex --outfile=scanner.c scanner.l 

scanner: flex yacc
	gcc utilities/token_list.c -c 
	gcc grammatical_rules/grammar_functions.c -c 
	gcc utilities/comment_stack.c utilities/symbol_table.c utilities/quads.c utilities/elist.c utilities/scopes.c utilities/scope_stack.c -c
	gcc scanner.c parser.c token_list.o comment_stack.o symbol_table.o grammar_functions.o quads.o elist.o scopes.o scope_stack.o -o alphac -g
	 ./alphac ../test.txt

yacc:
	bison --yacc --defines --output=parser.c parser.y -v

clean:
	rm -f scanner.c *.o alphac
