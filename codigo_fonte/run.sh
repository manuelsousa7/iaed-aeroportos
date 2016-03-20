#!/bin/bash  
./main < ../casos_teste/exemplo01.in > ../casos_teste/1.txt 
./main < ../casos_teste/exemplo02.in > ../casos_teste/2.txt 
./main < ../casos_teste/exemplo03.in > ../casos_teste/3.txt 
./main < ../casos_teste/exemplo04.in > ../casos_teste/4.txt 
diff ../casos_teste/exemplo01.out ../casos_teste/1.txt 
diff ../casos_teste/exemplo02.out ../casos_teste/2.txt 
diff ../casos_teste/exemplo03.out ../casos_teste/3.txt 
diff ../casos_teste/exemplo04.out ../casos_teste/4.txt 