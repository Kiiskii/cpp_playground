#!/bin/bash

cat TEMPLATE.cpp | sed -e "s/TEMPLATE/$1/g" > $1.cpp
cat TEMPLATE.hpp | sed -e "s/TEMPLATE/$1/g" > $1.hpp
