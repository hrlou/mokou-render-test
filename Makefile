CXX=x86_64-w64-mingw32-g++
CXXFLAGS=-std=c++17 -pipe -pedantic -O3 -Wall
PREFIX=/usr/local
INCLUDE=-L./SDL2/lib -I./SDL2/include -I./include
LDFLAGS=-Wall -lmingw32 -lSDL2main -lSDL2

BIN=game
BUILD_DIR=./build

CPP=$(wildcard src/*.cpp)
OBJ=$(CPP:%.cpp=$(BUILD_DIR)/%.o)
DEP=$(OBJ:%.o=%.d)

.PHONY: all clean
all: post-build
pre-build:
	@mkdir -p $(BUILD_DIR)
post-build: main-build
main-build: pre-build
	@$(MAKE) --no-print-directory $(BIN)

$(BIN) : $(BUILD_DIR)/$(BIN)
	cp ./SDL2/bin/*.dll ./build/

$(BUILD_DIR)/$(BIN) : $(OBJ)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@ $(LDFLAGS)

-include $(DEP)

$(BUILD_DIR)/%.o : %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -MMD -c $< -o $@

clean:
	-rm -rf $(OBJ) $(DEP) $(BUILD_DIR)