# Pull the latest image of CentOS from the Docker repo
FROM centos:7

# Creator
MAINTAINER Karl W. Schulz <karl@oden.utexas.edu>

# Define a user
RUN useradd -u 2000 -m test

# Disable yum fastmirror checks
RUN sed -i 's/enabled=1/enabled=0/' /etc/yum/pluginconf.d/fastestmirror.conf

# enable OpenHPC repository 
RUN yum install -y  http://build.openhpc.community/OpenHPC:/1.3/CentOS_7/x86_64/ohpc-release-1.3-1.el7.x86_64.rpm

# Add some packages
RUN yum -y install make which git
RUN yum -y install ohpc-autotools
RUN yum -y install gnu8-compilers-ohpc
RUN yum -y install openmpi3-gnu8-ohpc
RUN yum -y install hdf5-gnu8-ohpc
RUN yum -y install boost-gnu8-openmpi3-ohpc
RUN yum -y install petsc-gnu8-openmpi3-ohpc
RUN yum -y install lmod-defaults-gnu8-openmpi3-ohpc
RUN yum -y install zlib-devel
RUN yum -y install gsl-gnu8-ohpc

#---------------------------
# Add local install of GRVY
#---------------------------
ARG version=0.34.0
RUN yum -y install wget file
RUN wget https://github.com/hpcsi/grvy/releases/download/$version/grvy-$version.tar.gz -P /tmp
RUN cd /tmp; tar xfz /tmp/grvy-$version.tar.gz
RUN . /etc/profile.d/lmod.sh \
    && module load boost \
    && cd /tmp/grvy-$version \
    && ./configure CXXFLAGS="-std=c++11" LDFLAGS="-Wl,-rpath,$BOOST_LIB" \
    && make \
    && make install
RUN rm /tmp/grvy-$version.tar.gz

#---------------------------
# Add local install of MASA
#---------------------------
ARG version=0.50.0
RUN wget https://github.com/manufactured-solutions/MASA/releases/download/$version/masa-$version.tar.gz -P /tmp
RUN cd /tmp; tar xfz /tmp/masa-$version.tar.gz
RUN . /etc/profile.d/lmod.sh \
    && cd /tmp/masa-$version \
    && ./configure --enable-fortran-interfaces \
    && make \
    && make install
RUN rm /tmp/masa-$version.tar.gz

# Register new libs installed into /usr/local/lib with linker
RUN echo "/usr/local/lib" > /etc/ld.so.conf.d/class.conf
RUN ldconfig

#---------------------------
# Add local install of bats
#---------------------------
RUN yum -y install bats

# add deps for lcov/code coverage
RUN yum -y install perl-Digest-MD5

# User to run as
WORKDIR /home/test
USER test
