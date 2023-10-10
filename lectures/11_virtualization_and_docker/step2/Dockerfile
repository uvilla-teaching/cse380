# Pull the latest image of RockyLinux from the Docker repo
FROM rockylinux:8

# Creator
MAINTAINER Umberto Villa <uvilla@oden.utexas.edu>

# Define a user
RUN useradd -m uvilla

# Add some packages
RUN yum -y install make which git

RUN mkdir newdir
# User to run as
WORKDIR /home/uvilla
USER uvilla
