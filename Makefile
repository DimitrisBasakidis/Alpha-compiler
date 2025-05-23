all: compiler vm
	@echo "\nto create the quads and produce a binary output file:\n ./alphac [file.txt] [quads.txt]"
	@echo "to execute the binary file into code:\n./vm \"binary.abc\" "

vm: 
	g++ -std=c++11 Virtual-Machine/decodeBinary.cpp -c
	g++ -std=c++11 Virtual-Machine/avm_structs.cpp Virtual-Machine/avm_utilities.cpp Virtual-Machine/avm_dispatcher.cpp Virtual-Machine/avm_tables.cpp -c
	g++ -std=c++11 Virtual-Machine/main.cpp avm_structs.o avm_utilities.o decodeBinary.o avm_tables.o avm_dispatcher.o -o vm

gdb: compiler vm
	 ./alphac  ../test.txt quads.txt
	sudo gdb ./vm 

flex:
	flex --outfile=scanner.c scanner.l 

compiler: flex yacc
	gcc Compiler/utilities/token_list.c -c 
	gcc Compiler/grammatical_rules/grammar_functions.c -c 
	gcc Compiler/utilities/comment_stack.c Compiler/utilities/symbol_table.c Compiler/utilities/quads.c Compiler/utilities/elist.c Compiler/utilities/scopes.c Compiler/utilities/scope_stack.c Compiler/utilities/final_code.c Compiler/utilities/func_stack.c Compiler/utilities/target_code_generators.c Compiler/utilities/binary_file.c -c
	gcc scanner.c parser.c token_list.o comment_stack.o symbol_table.o grammar_functions.o quads.o elist.o scopes.o scope_stack.o final_code.o func_stack.o  target_code_generators.o binary_file.o -o alphac -g


yacc:
	bison --yacc --defines --output=parser.c parser.y -v

clean:
	rm -f *.o parser.c parser.output scanner.c alphac vm
	rm -f quads.txt
