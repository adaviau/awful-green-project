all: compile link

run: compile link
	./AwfulGreen

link: compile
	g++ -std=c++17 -o AwfulGreen main.o location.o entity.o map.o manifest.o

compile:
	g++ -std=c++17 -c main.cc location.cc entity.cc map.cc manifest.cc

clean:
	rm *.o
