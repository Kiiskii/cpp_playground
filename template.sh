#!/bin/bash

# Check for argument
if [ -z "$1" ]; then
    echo "Usage: $0 ClassName"
    exit 1
fi

# Create files in srcs and inc
cat ../../TEMPLATE.cpp | sed -e "s/TEMPLATE/$1/g" > srcs/$1.cpp
cat ../../TEMPLATE.hpp | sed -e "s/TEMPLATE/$1/g" > inc/$1.hpp

echo "Created srcs/$1.cpp and inc/$1.hpp"
