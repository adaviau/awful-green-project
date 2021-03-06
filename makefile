all: compile link

run: compile link
	./AwfulGreen

link: compile
	g++ -std=c++17 -o AwfulGreen \
		entity.o actor.o crew.o monster.o weapon.o \
		manifest.o \
		location.o map.o \
		effect.o \
		damage_profile.o \
		action_generator.o \
		attack_plan.o \
		game_master.o \
		file_loader.o \
		initializer.o \
		main.o 

compile:
	g++ -std=c++17 -c \
		entity.cc actor.cc crew.cc monster.cc weapon.cc \
		manifest.cc \
		location.cc map.cc \
		effect.cc \
		damage_profile.cc \
		action_generator.cc \
		attack_plan.cc \
		game_master.cc \
		file_loader.cc \
		initializer.cc \
		main.cc

cleanall: clean
	rm *.txt
	rm AwfulGreen

clean:
	rm *.o



