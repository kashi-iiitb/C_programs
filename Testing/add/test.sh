#!/bin/bash

./add 10 20 > gen_output.txt

diff exp_output.txt gen_output.txt

#if $var eq 30
#	echo "Correct output"
#else
#	echo "Wrong output"

