#!/bin/bash
#
# helper script masking as a test for vpath builds; creates soft links to
# necessary input items and utilities (bats binary, meshes, input files,
# reference solutions, etc) in the test directory.

testDir=`dirname $0`

# necessary text files
files="ref_output"
for file in $files; do
    if [ ! -s $file ];then
        if [ -s $testDir/$file ];then
           ln -s $testDir/$file .
        fi
    fi
done
