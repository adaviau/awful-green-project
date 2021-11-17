all: compile link

run: compile link
	./AwfulGreen

link: compile
	g++ -std=c++17 -o AwfulGreen \
		entity.o actor.o crew.o monster.o weapon.o \
		manifest.o \
		location.o map.o \
		main.o 

compile:
	g++ -std=c++17 -c \
		entity.cc actor.cc crew.cc monster.cc weapon.cc \
		manifest.cc \
		location.cc map.cc \
		main.cc

clean:
	rm *.o
