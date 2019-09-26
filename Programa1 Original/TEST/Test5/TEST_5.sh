#!/bin/bash
#
# Autor: Rodrigo Souza
#

if [ -e $final ]; then
  result=$(./prue)

  for r in $result ; do
    printf "Test %s\n" $r

  done
else
  printf "Utilizar:\n\t%s NombreArchivo\n" $0
fi