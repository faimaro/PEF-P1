# test -e prueba.dat && echo "file1 exists" || echo "file1 does not exist"

if [ -e $final ]; then
  result=$(./a)

  for r in $result ; do
    printf "Test %s\n" $r

  done
else
  printf "Utilizar:\n\t%s NombreArchivo\n" $0
fi