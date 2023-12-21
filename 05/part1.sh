#!/bin/bash

IFS=' ' read -ra seeds < input.txt
seeds=("${seeds[@]:1}")
echo ${seeds[@]}

