h5_write.exe: h5_write.c
	icc -I${TACC_HDF5_INC} -L${TACC_HDF5_LIB} -o $@ $^ -lhdf5 -lz

.PHONY: clean

clean:
	rm -f h5_write.exe

