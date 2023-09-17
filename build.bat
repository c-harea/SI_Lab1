gcc aes.c -o aes.o -c
gcc main.c -o main.o -c
gcc -o aes.exe aes.o main.o