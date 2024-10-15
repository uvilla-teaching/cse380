# Pull the latest image of RockyLinux from the Docker repo
FROM rockylinux:8

# Creator
MAINTAINER Umberto Villa <uvilla@oden.utexas.edu>

# Define a user
RUN useradd -m uvilla

# enable OpenHPC repository 
RUN yum install -y  http://repos.openhpc.community/OpenHPC/2/CentOS_8/x86_64/ohpc-release-2-1.el8.x86_64.rpm
RUN yum install -y yum-utils 

# Add some packages
RUN yum -y install make which git
RUN yum -y install ohpc-autotools
RUN yum -y --enablerepo powertools install lmod-ohpc
RUN yum -y install valgrind-ohpc
RUN yum -y install lmod-defaults-gnu9-mvapich2-ohpc
RUN yum -y install gsl-gnu9-ohpc
RUN yum -y install examples-ohpc

RUN . /etc/profile.d/lmod.sh \
      module load gsl
      echo $GSL_LIB > /etc/ld.so.conf.d/ohpc.conf
RUN ldconfig

# User to run as
RUN mkdir /home1
WORKDIR /home/uvilla
USER uvilla
