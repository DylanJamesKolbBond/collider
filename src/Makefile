FILES = board.cpp initial.cpp display.cpp move.cpp input.cpp legal.cpp debug.cpp bitboards.cpp sdl.cpp eval.cpp search.cpp collider.cpp 

SDL = -framework SDL2 -framework SDL2_image

OBJECTS = $(FILES:.cpp=.o)

EXECUTABLE = collider

CXX = clang++

CXXFLAGS = -Wall -g -pedantic -ferror-limit=256 -std=c++11 -c -I../include/  

LDFLAGS = $(SDL)

all: $(FILES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@ 

clean:
	rm *.o && rm $(EXECUTABLE)
