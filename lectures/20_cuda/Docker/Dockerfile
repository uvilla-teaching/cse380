ARG base_image=nvidia/cuda:12.2.2-devel-rockylinux8
FROM ${base_image}
LABEL author="Umberto Villa <uvilla@oden.utexas.edu>"

ARG make_cores=6

########################################
# Configure ENV 
########################################
SHELL ["/bin/bash", "-o", "pipefail", "-c"]

########################################
# Add docker-clean & entrypoint script
########################################
COPY extras/docker-clean /usr/bin/docker-clean
RUN chmod a+rx /usr/bin/docker-clean && docker-clean

########################################
# Add OS updates and IB stack
########################################

RUN yum install -y gcc-toolset-11-toolchain

RUN yum install -y \
    which \
    wget \
    git \ 
    git-lfs \
    file \
    && docker-clean


RUN source scl_source enable gcc-toolset-11 && which gcc
RUN source scl_source enable gcc-toolset-11 && gcc --version
RUN source scl_source enable gcc-toolset-11 && gfortran --version

RUN yum install -y \
    ca-certificates \
    libibmad-devel \
    libibumad \
    libibverbs-devel \
    librdmacm \
    libxml2-devel \
    && docker-clean

RUN yum install -y \
    cmake \
    libcurl-devel \
    automake \
    libtool \
    openssl-devel \
    bison \
    && docker-clean

RUN ldconfig

########################################
# Install mpi
########################################
# Install mvapich2-2.3
ARG MAJV=2
ARG MINV=3
ARG BV=.7
ARG DIR=mvapich${MAJV}-${MAJV}.${MINV}${BV}

RUN source scl_source enable gcc-toolset-11 && \
    curl http://mvapich.cse.ohio-state.edu/download/mvapich/mv${MAJV}/${DIR}.tar.gz | tar -xzf - \
    && cd ${DIR} \
    && ./configure \
       --with-device=ch3 \
       --with-ch3-rank-bits=32 \
       --enable-fortran=yes \
       --enable-cxx=yes \
       --enable-romio \
       --enable-fast=O3 \
       FFLAGS="-w -fallow-argument-mismatch -O2" \
    && make -j ${make_cores} \
    && make install \
    && cd ../ && rm -rf ${DIR} \
    && rm -rf /usr/local/share/doc/mvapich2

# Add hello world
COPY extras/hello.c /tmp/hello.c
RUN source scl_source enable gcc-toolset-11 && \
    mpicc /tmp/hello.c -o /usr/local/bin/hellow && \
    MV2_SMP_USE_CMA=0 mpirun -n 2 hellow && \
    rm /tmp/hello.c

RUN echo /usr/local/cuda/lib64 > /etc/ld.so.conf.d/cuda.conf
RUN ldconfig

COPY extras/entry.sh /entry.sh
RUN chmod a+rx /entry.sh
ENTRYPOINT [ "/entry.sh" ]
    