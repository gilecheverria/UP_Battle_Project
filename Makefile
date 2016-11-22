# Simple makefile to use with the make program
# For more information on makefiles, read:
#   http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

# Variables with the options for compilation
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
#LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# List of the objects to compile
OBJECTS = Character.o Hero.o Monster.o Party.o Battle.o Randomizer.o Game.o battle_game.o
# List of header files that should be treated as dependencies
DEPENDS = Character.hpp Hero.hpp Monster.hpp Party.hpp Battle.hpp Randomizer.hpp FileIOTemplate.hpp Game.hpp

# Variables with rule names
BATTLE = battle

# Default rule
all: $(BATTLE)

# Rule to compile object files
# Commented because it is the same as an explicit rule in Make
#   https://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_10.html
%.o: %.cpp $(DEPENDS)
	$(CXX) -c -o $@ $< $(CXXFLAGS) 

# Rule to compile the program
$(BATTLE): $(OBJECTS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

# Rule to remove compiled object files and executables
clean:
	-rm -f *.o $(BATTLE)

# Indicate that the rules listed do not correspond to files
.PHONY: all clean
