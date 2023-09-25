# Files
EXEC := foo
SRC  := $(wildcard *.c)
OBJ  := $(patsubst %.c,%.o,$(SRC))

# Machine-specific Options

HOST=$(shell dnsdomainname)

ifeq ("$(HOST)","ls6.tacc.utexas.edu")
$(info Using System = $(HOST) settings)
include Makefile.ls6
else
$(info Using Default settings)
CC      := gcc
CFLAGS  := -O3
LDFLAGS := -L/usr/lib
LDLIBS  := -lm
endif


# Rules
$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Header dependency
foo.o bar.o: bar.h

# Useful phony targets
.PHONY: clobber clean neat echo
clobber: clean
	$(RM) $(EXEC)
clean: neat
	$(RM) $(OBJ)
neat:
	$(RM) *~ .*~
echo:
	@echo $(OBJ)
