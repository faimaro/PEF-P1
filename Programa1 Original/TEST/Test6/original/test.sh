#archivo para realizar un testeo de codigo muerto.

g++ -fprofile-arcs -ftest-coverage final.cpp

./a.out

gcov final.cpp