#!/bin/bash
#
# Autor: Rodrigo Souza
#
if [ -e $final ]; then

  #Escribir el archivo prueba.dat

  #result=$(./FinalOriginal) #Codigo Original 
  result=$(./FinalCorregido) #Codigo Corregido

  for r in $result ; do

    echo $r
    case $r in 
      "837.3") 
        echo Codigo 1, paso
        ;;
      "2044.03")  
        echo Codigo 2, paso
        ;;
      "3606.12") 
        echo Codigo 3, paso
        ;;
      *)
        echo No paso
    esac
  done

else
  printf "Utilizar:\n\t%s NombreArchivo\n" $0
fi