all: main

main: Admin.h Admin.cpp Student.h Student.cpp Login.h Login.cpp Menu.h Menu.cpp main.cpp
	g++ -o main main.cpp Login.cpp Admin.cpp Menu.cpp Student.cpp

clean:
	rm -f main.cpp
