#!/bin/bash
echo "Building test : )"
make all
chmod +x ./greedy_test
./greedy_test
make clean
