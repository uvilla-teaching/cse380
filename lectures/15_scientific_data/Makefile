h5_write.exe: h5_write.c
	mpicc -I${TACC_PHDF5_INC} -L${TACC_PHDF5_LIB} -o $@ $^ -lhdf5 -lz

.PHONY: clean

clean:
	rm -f h5_write.exe

