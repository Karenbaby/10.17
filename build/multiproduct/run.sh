#!/bin/bash 
echo "student revise times:"
cat ../../log.log | grep -v "student find" | wc -l
echo "class revise times:"
cat ../../log.log | grep -v "class find" | wc -l

read -p "id:" id 
../../log.log | grep "$id" | grep -v "student find"
read -p "class_id:" class_id
../../log.log | grep "$class_id" | grep -v "class find"




