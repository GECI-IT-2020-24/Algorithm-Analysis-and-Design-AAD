#!/bin/bash
echo "Building test : )"
make all
chmod +x ./dac_test
./dac_test
make clean
