FROM centos:7
MAINTAINER Umberto Villa <uvilla@oden.utexas.edu>

# Define a user
RUN useradd -u 2000 -m test

# enable OpenHPC repository 
RUN yum install -y https://github.com/openhpc/ohpc/releases/download/v1.3.GA/ohpc-release-1.3-1.el7.x86_64.rpm

# Add some packages
RUN yum -y install make which git
RUN yum -y install ohpc-autotools cmake-ohpc
RUN yum -y install valgrind-ohpc
RUN yum -y install gnu8-compilers-ohpc
RUN yum -y install gsl-gnu8-ohpc hdf5-gnu8-ohpc
RUN yum -y install openmpi3-gnu8-ohpc boost-gnu8-openmpi3-ohpc petsc-gnu8-openmpi3-ohpc
RUN yum -y install lmod-defaults-gnu8-openmpi3-ohpc
RUN yum -y install bc wget zlib-devel perl-Digest-MD5
# Add Bats
RUN yum -y install bats
# Add GRVY
ENV grvy_ver="0.34.0"
RUN wget https://github.com/hpcsi/grvy/releases/download/$grvy_ver/grvy-$grvy_ver.tar.gz -P /tmp
RUN cd /tmp; tar xfz /tmp/grvy-$grvy_ver.tar.gz
RUN . /etc/profile.d/lmod.sh \
    && module load boost \
    && cd /tmp/grvy-$grvy_ver \
    && ./configure CXXFLAGS="-std=c++11" LDFLAGS="-Wl,-rpath,$BOOST_LIB" \
    && make \
    && make install
RUN rm /tmp/grvy-$grvy_ver.tar.gz

# Register new libs installed into /usr/local/lib with linker
RUN echo "/usr/local/lib" > /etc/ld.so.conf.d/class.conf
RUN ldconfig

# User to run as
WORKDIR /home/test
USER test
