# Executable names:
EXE = main
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o Animation.o


# mp_traverals specific stuff
# Add all `colorPicker` and `imageTraversal`s:
#CPP_FILES += $(wildcard colorPicker/*.cpp)
#CPP_FILES += $(wildcard imageTraversal/*.cpp)
OBJS += $(CPP_FILES:.cpp=.o)

# Generated files
CLEAN_RM = GIFTEST.gif frames

# Use the cs225 makefile template:
include cs225/make/cs225.mk

