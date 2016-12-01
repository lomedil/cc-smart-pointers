#!/bin/sh
#Script para cambiar el compilador usado.
#En mi caso, el mac no tiene uno compatible con C++
# y he descargado otro con homebrew
echo "Usando el compilador $1"
sed -i .bak "s#CC := \(.*\)#CC := $1#" Makefile **/Makefile 