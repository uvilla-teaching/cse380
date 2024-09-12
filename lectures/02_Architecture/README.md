# CPU info

1. Type `lscpu` command

# Interconnet

In this class, we will use the OSU Micro-Benchmarks to measure bandwidth (https://mvapich.cse.ohio-state.edu/benchmarks/) and latency of lonestar6 interconnect.
Many of today's steps (configuring and compiling the library, requesting an interactive session on a compute note) will explained later in the class.

## Obtain and build OSU Micro-Benchmarks

1. After connecting to lonestar6, we will use the Linux command `wget` and `tar` to download and unpack the benchmarks suite

```
wget https://mvapich.cse.ohio-state.edu/download/mvapich/osu-micro-benchmarks-7.2.tar.gz
tar -xzf osu-micro-benchmarks-7.2.tar.gz
```

2. Configure, compile, and install the benchmarks (More on this later in the course). 

```
cd osu-micro-benchmarks-7.2
./configure CC=mpicc CXX=mpicxx --prefix=$(pwd)/../osu-benchmark-install
make
make install
```

Note: You can also find the precompiled benchmarks in 
```
/work/03453/villa13/ls6/CSE380/PUBLIC/osu-micro-benchmarks/mpi
```

## Run a latency and bandwidth test

3. Request an interactive session with 2 compute nodes. Use the class account `CDA23007`

```
idev -N 2 -A CDA23007
```

4. Run the `osu_latency` test:
> The latency tests are carried out in a ping-pong fashion. The sender sends a message with a certain data size to the receiver and waits for a reply from the receiver. The receiver receives the message from the sender and sends back a reply with the same data size. Many iterations of this ping-pong test are carried out and average one-way latency numbers are obtained. Blocking versions of MPI functions (MPI_Send and MPI_Recv) are used in the tests. 

Here we use the command `ibrun -n 2` to launch the test using two processes (sitting on two different nodes)

```
export OSU_DIR=/work/03453/villa13/ls6/CSE380/PUBLIC/osu-micro-benchmarks/mpi
ibrun -n 2 $OSU_DIR/pt2pt/osu_latency 
```

5. Run the `osu_bw` test:
> The bandwidth tests are carried out by having the sender sending out a fixed number (equal to the window size) of back-to-back messages to the receiver and then waiting for a reply from the receiver. The receiver sends the reply only after receiving all these messages. This process is repeated for several iterations and the bandwidth is calculated based on the elapsed time (from the time sender sends the first message until the time it receives the reply back from the receiver) and the number of bytes sent by the sender. The objective of this bandwidth test is to determine the maximum sustained date rate that can be achieved at the network level. Thus, non-blocking version of MPI functions (MPI_Isend and MPI_Irecv) are used in the test. 

```
ibrun -n 2 $OSU_DIR/pt2pt/osu_bw
```




