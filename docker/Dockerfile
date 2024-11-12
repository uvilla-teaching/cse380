# Pull the latest image of RockyLinux from the Docker repo
FROM rockylinux:8
MAINTAINER Umberto Villa <uvilla@oden.utexas.edu>

# Define a user
RUN useradd -u 2000 -m test

# enable OpenHPC repository 
RUN yum install -y  http://repos.openhpc.community/OpenHPC/2/CentOS_8/x86_64/ohpc-release-2-1.el8.x86_64.rpm
RUN yum install -y yum-utils 
# Add some packages
RUN yum -y install make which git diffutils
RUN yum -y install ohpc-autotools cmake-ohpc
RUN yum -y --enablerepo powertools install lmod-ohpc
RUN yum -y install valgrind-ohpc
RUN yum -y install gnu9-compilers-ohpc
RUN yum -y install gsl-gnu9-ohpc hdf5-gnu9-ohpc
RUN yum -y install mvapich2-gnu9-ohpc boost-gnu9-mvapich2-ohpc petsc-gnu9-mvapich2-ohpc
RUN yum -y install lmod-defaults-gnu9-mvapich2-ohpc
RUN yum -y install bc wget zlib-devel perl-core perl-Digest-MD5 perl-IO-Compress
# Add Bats
RUN yum -y install bats
# Add lcov
ENV lcov_ver="1.16"
RUN wget https://github.com/linux-test-project/lcov/releases/download/v$lcov_ver/lcov-$lcov_ver.tar.gz -P /tmp
RUN cd /tmp; tar xfz /tmp/lcov-$lcov_ver.tar.gz
RUN cd /tmp/lcov-$lcov_ver && make install
RUN rm /tmp/lcov-$lcov_ver.tar.gz
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

RUN mkdir /home/test/shared

# User to run as
WORKDIR /home/test
USER test
