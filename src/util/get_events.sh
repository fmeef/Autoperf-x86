#!/bin/bash -x
grep "//\!<" /bgsys/drivers/ppcfloor/spi/include/upci/events.h | awk -F"<" '{print $2}' >events.labels
grep "//\!<" /bgsys/drivers/ppcfloor/spi/include/upci/events.h | awk -F"=" '{print $1}' >events.enum  
sleep 1
./print_labels >labels.txt
echo 'edit hpm.c and replace counter labels with labels.txt'
