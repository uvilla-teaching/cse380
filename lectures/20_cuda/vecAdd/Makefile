INC	:= -I$(CUDA_HOME)/include -I.
LIB	:= -L$(CUDA_HOME)/lib64 -lcudart

NVCCFLAGS	:= -lineinfo -arch=sm_70 --ptxas-options=-v --use_fast_math -O3
GCCFLAGS := -O3 --fast-math 
all:
	nvcc vectorAdd.cu -o par_float $(INC) $(NVCCFLAGS) $(LIB)
clean:
	rm -rf par_float
	rm -rf serial
	rm -rf serialslow
serial:
	g++ $(GCCFLAGS) -o serial vectorAddSerial.cpp

serialslow:
	g++ -o serialslow vectorAddSerial.cpp