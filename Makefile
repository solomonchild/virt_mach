NAME:=svm
EXE:=$(NAME).exe
GCC:=g++
LN:=g++

CFLAGS:= -Iinclude -Isrc -MMD -Wall --std=c++0x
LDFLAGS:=

SOURCE:=$(wildcard src/*.cpp)
OBJS:=$(patsubst %.cpp, obj/%.o, $(SOURCE))

$(EXE):$(OBJS) 
	$(LN) $(LDFLAGS) $(OBJS) -o $@

all:$(EXE)

obj/%.o:%.cpp
	mkdir -p $(dir $@)
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj/

-include ${OBJS:.o=.d}
