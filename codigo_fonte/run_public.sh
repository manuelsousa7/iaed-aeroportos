#!/bin/bash  
./main < ../testes_publicos/test01.in > ../testes_publicos/1.txt 
./main < ../testes_publicos/test02.in > ../testes_publicos/2.txt 
./main < ../testes_publicos/test03.in > ../testes_publicos/3.txt 
./main < ../testes_publicos/test04.in > ../testes_publicos/4.txt  
./main < ../testes_publicos/test05.in > ../testes_publicos/5.txt 
./main < ../testes_publicos/test06.in > ../testes_publicos/6.txt 
./main < ../testes_publicos/test07.in > ../testes_publicos/7.txt 
./main < ../testes_publicos/test08.in > ../testes_publicos/8.txt 
diff ../testes_publicos/test01.out ../testes_publicos/1.txt 
diff ../testes_publicos/test02.out ../testes_publicos/2.txt 
diff ../testes_publicos/test03.out ../testes_publicos/3.txt 
diff ../testes_publicos/test04.out ../testes_publicos/4.txt 
diff ../testes_publicos/test05.out ../testes_publicos/5.txt 
diff ../testes_publicos/test06.out ../testes_publicos/6.txt 
diff ../testes_publicos/test07.out ../testes_publicos/7.txt 
diff ../testes_publicos/test08.out ../testes_publicos/8.txt 