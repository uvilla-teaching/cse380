# Files
EXEC := solver
SRC  := $(wildcard *.c)
OBJ  := $(patsubst %.c,%.o,$(SRC))

include ${PETSC_DIR}/lib/petsc/conf/variables

# Options
CC      := mpicc
CFLAGS  := -O0 ${PETSC_CCPPFLAGS}
LDFLAGS := -L${PETSC_LIB_DIR} ${PETSC_LIB_BASIC}
LDLIBS  := 



# Rules
$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $<


# Useful phony targets
.PHONY: clobber clean neat echo
clobber: clean
	$(RM) $(EXEC)
clean: neat
	$(RM) $(OBJ)
neat:
	$(RM) *~ .*~
echo:
	@echo ${PETSC_CCPPFLAGS} && echo ${PETSC_LIB_BASIC}
