ABI=x86_64
CXX=$(ABI)-w64-mingw32-g++
CXXFLAGS=-std=c++17 -pipe -pedantic -O2 -Wall
PREFIX=/usr/local
INCLUDE=-L./SDL2/$(ABI)/lib -I./SDL2/$(ABI)/include -I./include -I./
LDFLAGS=-static-libstdc++ -static-libgcc -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

BIN_DIR=./bin
OBJ_DIR=./obj
DLL_DIR=./SDL2/$(ABI)/bin

BIN=touhou.exe
DLL=SDL2.dll SDL2_image.dll zlib1.dll libpng16-16.dll

CPP=$(wildcard src/*.cpp)
OBJ=$(CPP:%.cpp=$(OBJ_DIR)/%.o)
DEP=$(OBJ:%.o=%.d)

.PHONY: all clean full-clean update
all: post-build
post-build: main-build
	-rsync -ur $(DLL:%.dll=$(DLL_DIR)/%.dll) $(BIN_DIR)/.
	-rsync -ur ./assets $(BIN_DIR)/.

pre-build:
	-mkdir -p $(BIN_DIR) $(OBJ_DIR)

main-build: pre-build
	-$(MAKE) --no-print-directory $(BIN)

$(BIN) : $(BIN_DIR)/$(BIN)

$(BIN_DIR)/$(BIN) : $(OBJ)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@ $(LDFLAGS)

-include $(DEP)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -MMD -c $< -o $@

clean:
	-rm -rf $(BIN_DIR) $(OBJ_DIR)

full-clean: clean
	-rm -rf ./SDL2 ./json.hpp

update: full-clean
	-bash setup.sh
