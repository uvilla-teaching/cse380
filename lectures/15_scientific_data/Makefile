h5_write.exe: h5_write.c
	mpicc -I${TACC_PHDF5_INC} -L${TACC_PHDF5_LIB} -o $@ $^ -lhdf5 -lz

.PHONY: list dump

list:
	h5ls SDS.h5

dump:
	h5dump SDS.h5

diff:
	h5diff SDS.h5 ref_SDS.h5

diff2:
	h5diff -d 1e-5 SDS.h5 ref_SDS.h5
