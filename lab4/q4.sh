#!/bin/bash
case $2 in
	-linecount)
            wc "$1" -l;;
	-wordcount)
			wc "$1" -w;;
	-charcount)
			wc "$1" -c;;
	*)
	echo "no match found";;
esac
