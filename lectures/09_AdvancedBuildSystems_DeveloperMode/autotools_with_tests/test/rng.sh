#!/bin/bash

executable="../src/rng-tool"

# verify executable exists
if [ ! -x "$executable" ]; then
    echo "Error: expecting executable -> $executable"
    exit 1
fi

# verify rng has 10 lines in stdout
$executable > .tmp_output
lines=`wc -l .tmp_output | awk '{print $1}'`
if [ "$lines" != "10" ];then
    echo "Error: expecting 10 lines of output from rng"
    exit 1
fi

# Verify rng samples by comparing to known good reference
$executable > .tmp_output
diff -q .tmp_output ref_output
status=$?

if [ $status -ne 0 ];then
    echo "Error: rng samples differ from expected values"
    diff .tmp_output ref_output
    exit 1
fi

