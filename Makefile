.PHONY: run build rebuild clean

run: build
	./School_DB

build: School_DB

School_DB: Class.o Database.o UserInterface.o
	g++ -o School_DB Class.o Database.o UserInterface.o

Class.o: Class.cpp Class.h
	g++ -o Class.o -c Class.cpp

Database.o: Database.h Database.cpp Class.h
	g++ -o Database.o -c Database.cpp

UserInterface.o: UserInterface.cpp Database.h My_Stack/My_Stack.cpp My_Stack/My_Stack.h
	g++ -o UserInterface.o -c UserInterface.cpp

rebuild: clean build

clean:
	rm -vf *.o School_DB