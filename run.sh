lex parser.l  ;
yacc parser.y ;
gcc append.c ;
./a.out test1.c > put.c ;
gcc y.tab.c -ll -ly ;
./a.out put.c  ;    
rm put.c ;