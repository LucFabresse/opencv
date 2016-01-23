#!/usr/bin/env bash

./headerParser2Pharo.py 
pvm image/Pharo.image eval --quit "OCVBindingGenerator newWithDeclarationsFromFileNamed: '../build/allDecls.st'; outputDirectory: '../build/' ; generateNBBinding"
