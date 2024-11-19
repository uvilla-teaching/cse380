INC	:= -I$(CUDA_HOME)/include -I.
LIB	:= -L$(CUDA_HOME)/lib64 -lcudart

NVCCFLAGS	:= -lineinfo -arch=sm_70 --ptxas-options=-v --use_fast_math -O3
GCCFLAGS := -O3 --fast-math 
all: shuffle serial
shuffle:
	nvcc ./vectorDotProduct.cu -o shuffle $(INC) $(NVCCFLAGS) $(LIB)
serial:
	g++ $(GCCFLAGS) -o serial vectorDotProductSerial.cpp
clean:
	rm -rf shuffle serial