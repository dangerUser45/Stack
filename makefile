Target = MyStack
Compiler = g++

$(Target) : Main_stack.o Debug.o Stack.o
	$(Compiler) Main_stack.o Debug.o  Stack.o -o $(Target)


Debug.o : Debug.cpp
	$(Compiler) -c Debug.cpp -o Debug.o

Stack.o : Stack.cpp
	$(Compiler) -c Stack.cpp -o Stack.o
	
Main_stack.o : Main_stack.cpp
	$(Compiler) -c Main_stack.cpp -o Main_stack.o

clean :
	del *.o
