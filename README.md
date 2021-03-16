# Three-Adress-Code
Contains Three Adress Code for a subset of C constructs

Steps to Compile the code:

Pre-Requisites:
1) Terminal must support running of lex, yacc and gcc, I/O Redirection from files.

To run the particular test file:

1) Open the file test1.c in the folder in a text editor. (this file has been attached in the folder during the assignment submission)
2) Copy the contents of the test file (say student_test.c) in the test1.c file 
i.e the contents of test1.c file must be the same as the student_test.c file (otherwise the code will not give the correct output)
3) Once, the contents of the code are copied in the test1.c file, save the test1.c file 
(using save option/Ctrl + S key) (save the test1.c file for it to run)
4) Once test1.c file is saved, run the following commands sequentially on the terminal

        lex parser.l       
        yacc parser.y 
        gcc append.c
        ./a.out test1.c > put.c
        gcc y.tab.c -ll -ly
        ./a.out put.c    

	OR

If you are too lazy to run the commands multiple times just run the script attached in the repo by the following command

        ./run.sh    

5) All the commands are run and the final output is displayed on the terminal.
6) Repeat the above 5 steps in sequential order to run the remaining test files. 
(Copy contents of the test file into test1.c, save test1.c and run command at step 4 for the output)
