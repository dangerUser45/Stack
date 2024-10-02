
Target = MyStack
Compiler = g++

$(Target) : Main.o Debug.o
	mkdir build
	$(Compiler) Main.o Debug.o -o build/$(Target)

Main.o : Main.cpp
	$(Compiler) -c Main.cpp -o Main.o

Debug.o : Debug.cpp
	$(Compiler) -c Main.cpp -o Main.o

clean :
	rm -f $(Target) *.o
