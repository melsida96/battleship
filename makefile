TARGET	:= run
SOURCE	:= $(wildcard ./src/*.cpp)
HEADER	:= $(wildcard ./src/*.h)
OBJECT	:= $(patsubst %.cpp, %.o, $(SOURCE))
DIR_bin := $(addprefix bin/, $(TARGET))
INCLUDE_PATH := -I./src
CC		:= g++

$(TARGET): $(OBJECT)
	@mkdir -p bin
	@mkdir -p obj
	@$(CC) $(OBJECT) -o $(DIR_bin)
	@mv src/main.o obj/main.o
	@mv src/functions.o obj/functions.o
%.o: %.cpp $(HEADER) 
	@$(CC) -c $< -o $@ $(INCLUDE_PATH)


.PHONY: clean
clean: 
	@echo "Cleaning..."
	@rm -rf bin
	@rm -rf ./docs/doxygen
	@rm -rf obj
	
.PHONY: doxygen
doxygen:
	@doxygen Doxyfile


