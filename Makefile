target := a.out
depsdir = include

CC := g++
CFLAGS := -std=c++17 -Wall -I include
CLIBS := -lsfml-graphics -lsfml-window -lsfml-system -lstdc++

VPATH = src

all: $(target)

cfiles := $(wildcard src/*.cpp) # get all c/cpp files from src
objs := $(subst src/,,$(patsubst %.cpp,%.o,$(cfiles))) # replace .c with .o and remove src/ (src/file.c -> file.o)
deps := $(patsubst %.o,%.d,$(objs)) # replace .o with .d
-include $(depsdir)/*.d
DEPFLAGS = -MMD -MF $(depsdir)/$(@:.o=.d) # generate dependencies

$(target): $(objs)
	$(CC) $(CFLAGS) -o $@ $^ $(CLIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< $(DEPFLAGS) $(CLIBS)

clean:
	rm -f $(target) $(objs) $(depsdir)/*.d

print:
	echo $(objs) $(deps)
