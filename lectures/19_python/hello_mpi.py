#! /usr/bin/env python
#
def hello_mpi ( ):

#*****************************************************************************80
#
## HELLO_MPI is a simple "Hello, world!" test of MPI4PY.
#
#  Licensing:
#
#    This code is distributed under the GNU LGPL license.
#
#  Modified:
#
#    10 August 2017
#
#  Author:
#
#    John Burkardt
#
  import sys
  from mpi4py import MPI

  comm = MPI.COMM_WORLD

  id = comm.Get_rank()

  p = comm.Get_size()

  if ( id == 0 ):
    print ""
    print "HELLO_MPI:"
    print "  P", id, ":  There are ", p, " MPI processes running."

  print "  P", id, ":  Hello, world!"

  return

if ( __name__ == '__main__' ):
  hello_mpi ( )
