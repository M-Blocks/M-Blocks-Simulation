src = $(wildcard src/*.cpp)
obj = $(src:.c=.o)

CXX = g++

CFLAGS = -std=c++11 -Wall
LIBS = -lGLEW -lGLU -lglfw3 -lrt -lXrandr -lXinerama -lXi -lXcursor -lGL -lm -ldl -lXrender -ldrm -lXdamage -lX11-xcb -lxcb-glx -lxcb-dri2 -lxcb-dri3 -lxcb-present -lxcb-sync -lxshmfence -lXxf86vm -lXfixes -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp -lSOIL
LFLAGS = -L/usr/local/lib
INCLUDES = -I./include

MAIN = triangle

all: $(MAIN)

$(MAIN): $(obj)
	$(CXX) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(obj) $(LFLAGS) $(LIBS)

.c.o:
	$(CXX) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: depend clean
clean:
	rm -f *.o triangle

depend: $(src)
	makedepend $(INCLUDES) $^
# DO NOT DELETE

main.o: /usr/include/GL/glew.h /usr/include/stdint.h /usr/include/features.h
main.o: /usr/include/stdc-predef.h /usr/include/GL/glu.h /usr/include/GL/gl.h
