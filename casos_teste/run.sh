#!/bin/bash  

gcc ../codigo_fonte/main.c -o ../codigo_fonte/main -Wall
shift
for arg in "$@"
do
  echo "Running $arg"
  echo ""
  ../codigo_fonte/main < "${arg%.*}".in > "${arg%.*}".out.main
  diff "${arg%.*}".out "${arg%.*}".out.main
done

rm *../codigo_fonte/main
rm ../codigo_fonte/main
