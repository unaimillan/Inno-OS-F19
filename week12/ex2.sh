#!/bin/bash

gcc ex2.c -o ex2-auto
cat /proc/cpuinfo | ./ex2-auto ex2.txt
rm ex2-auto
