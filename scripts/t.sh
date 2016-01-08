#!/bin/sh

while true
	do
		echo $v
		v=` expr $v + 1 `
		sleep 0.05
		clear
	done
