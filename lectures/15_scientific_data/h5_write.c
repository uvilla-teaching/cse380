/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the COPYING file, which can be found at the root of the source code       *
 * distribution tree, or in https://www.hdfgroup.org/licenses.               *
 * If you do not have access to either file, you may request a copy from     *
 * help@hdfgroup.org.                                                        *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 *  This example writes data to the HDF5 file.
 *  Data conversion is performed during write operation.
 */

#include<stdio.h>
#include<stdlib.h>

#include "hdf5.h"

#define DATASETNAME "DoubleArray"
#define NX          5 /* dataset dimensions */
#define NY          6
#define RANK        2


void usage()
{
  printf("\nUsage: h5_write [filename] [val]\n\n");
  printf("   where \n");
  printf("   - filename is the name of the output file \n");     
  printf("   - val is the value of the additive shift \n\n");
  exit(1);
}
int main(int argc, char *argv[])
{
    double bias;
    char * fname;
    if(argc != 3)
        usage();
    else
    {
        fname = argv[1];
        bias = atof(argv[2]);
    }

    hid_t   file, dataset;       /* file and dataset handles */
    hid_t   datatype, dataspace; /* handles */
    hsize_t dimsf[2];            /* dataset dimensions */
    herr_t  status;
    double     data[NX][NY]; /* data to write */
    int     i, j;

    /*
     * Data  and output buffer initialization.
     */
    for (j = 0; j < NX; j++)
        for (i = 0; i < NY; i++)
            data[j][i] = (i + j)/(j+0.01) + bias;


    /*
     * Create a new file using H5F_ACC_TRUNC access,
     * default file creation properties, and default file
     * access properties.
     */
    file = H5Fcreate(fname, H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);

    /*
     * Describe the size of the array and create the data space for fixed
     * size dataset.
     */
    dimsf[0]  = NX;
    dimsf[1]  = NY;
    dataspace = H5Screate_simple(RANK, dimsf, NULL);

    /*
     * Define datatype for the data in the file.
     * We will store little endian INT numbers.
     */
    datatype = H5Tcopy(H5T_NATIVE_DOUBLE);
    status   = H5Tset_order(datatype, H5T_ORDER_LE);

    /*
     * Create a new dataset within the file using defined dataspace and
     * datatype and default dataset creation properties.
     */
    dataset = H5Dcreate2(file, DATASETNAME, datatype, dataspace, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);

    /*
     * Write the data to the dataset using default transfer properties.
     */
    status = H5Dwrite(dataset, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, data);

    /*
     * Close/release resources.
     */
    H5Sclose(dataspace);
    H5Tclose(datatype);
    H5Dclose(dataset);
    H5Fclose(file);

    return 0;
}

