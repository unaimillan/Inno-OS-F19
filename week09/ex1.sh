name=ex1
default="input1.txt"
input=${1:-$default}  #$([ "$1"=="" ] && echo $1 || echo $default)
gcc $name.c -o $name.out
./$name.out 10 $input
./$name.out 50 $input
./$name.out 100 $input
