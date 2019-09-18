#!/bin/bash
succs=0

while true
do
    if `ln file file.lock 2> /dev/null`; # Attepmting to write silently
    then
        last=`tail -n 1 file`
        echo $((last+1)) >> file
        rm file.lock
        
        sleep 0.1
        echo "Successes: $((++succs))"
    else
        sleep 0.1
    fi
done
