EXE = visualize
TEST = test

EXE_OBJ = main.o
OBJS = main.o circle.o line.o shape.o vector2.o visualize.o


# Override "default" rule provided by the Makefile template
all: $(EXE)

# Remove additional executables during `make clean`
CLEAN_RM = $(output.png)

# Use the CS 225 Makefile template
include cs225/make/cs225.mk

# Assignment-specific compiler config
# Note that due to how make processes Makefiles, these flags will even apply
# to the targets inside the included Makefile template
CXXFLAGS += -Wno-delete-non-virtual-dtor

OBJS_PROVIDED = $(OBJS_DIR)/cs225/PNG.o $(OBJS_DIR)/cs225/lodepng/lodepng.o $(OBJS_DIR)/cs225/HSLAPixel.o $(OBJS_DIR)/vector2.o $(OBJS_DIR)/line.o
