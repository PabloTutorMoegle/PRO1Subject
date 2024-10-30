CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Game.o Player.o Character.o Equipment.o
	$(LINK.cc) -o $@ $^
	
program.o: program.cpp Game.hpp Player.hpp Character.hpp Equipment.hpp

Game.o: Game.cpp Game.hpp Player.hpp Character.hpp Equipment.hpp

Player.o: Player.cpp Player.hpp Character.hpp

Character.o: Character.cpp Character.hpp Equipment.hpp

Equipment.o: Equipment.cpp Equipment.hpp