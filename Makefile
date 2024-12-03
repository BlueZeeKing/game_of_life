CC=g++
STD=c++23

build/game_of_life: build/main.o build/cell.o build/grid.o build/conway.o
	$(CC) -o $@ $^ -std=$(STD) -lncursesw

build/%.o: %.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	$(CC) -c -o $@ $< -std=$(STD)

-include build/*.d

.PHONY: all clean

all: build/game_of_life

clean:
	rm -rf build