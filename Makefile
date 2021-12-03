# A simple Makefile for SDL projects

# set the compiler
CC = g++

# set the compiler flags
CFLAGS =  -Wall -g 

# add header files here
HDRS = Vector.h Camera.h ImagePlane.h Ray.h Trace.h Sphere.h Plane.h Scene.h

# add source files here
SRCS = raytrace.cpp Camera.cpp ImagePlane.cpp Ray.cpp Trace.cpp Sphere.cpp Plane.cpp Scene.cpp

# generate names of object files
OBJS = $(SRCS:.cpp=.o)

# name of executable
EXEC = raytrace

# default recipe
all: $(EXEC)
 
#showfont: showfont.c Makefile
#    $(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

#glfont: glfont.c Makefile
#    $(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

# recipe for building the final executable
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS)

# recipe for building object files
$(OBJS): $(@:.o=.cpp) $(HDRS) Makefile
	$(CC) -o $@ $(@:.o=.cpp) -c $(CFLAGS)

# recipe to clean the workspace
clean:
	rm -f $(EXEC) 
	rm -f $(OBJS)

