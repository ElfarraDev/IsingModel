# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude -I/opt/homebrew/Cellar/sfml/2.6.1/include

# SFML library path
SFML_LIB_PATH = /opt/homebrew/Cellar/sfml/2.6.1/lib
SFML_LIB = -L$(SFML_LIB_PATH) -lsfml-graphics -lsfml-window -lsfml-system

# Directories
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj

# Files
SRCS = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
TARGET = ising_model

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SFML_LIB)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)/$(SRC_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
