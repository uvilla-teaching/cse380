#!/bin/bash

echo "Calling command is:         $0"
echo "Total # of arguments is:    $#"
echo "A list of all arguments is: $*"
echo "The 2nd argument is:        $2"

echo "All arguments are listed below"
for VAR in $*; do
	echo $VAR
done
