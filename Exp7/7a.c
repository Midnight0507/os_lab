#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int i;
    struct stat a;

    for (i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
        stat(argv[i], &a);
        if (S_ISDIR(a.st_mode)) {
            printf("Is a directory\n");
        } else {
            printf("Is a regular file\n");
        }
        printf("FILE PROPERTIES\n");
        printf("Inodenumber: %ld\n", a.st_ino);  // Use %ld for long int
        printf("No of Links: %ld\n", a.st_nlink);  // Use %ld for long int
        printf("Last access time: %s\n", asctime(localtime(&a.st_atime)));
        printf("Permission Flag: %o\n", a.st_mode % 512); // Mask out unused bits
        printf("Size: %ld bytes\n", a.st_size);    // Use %ld for long int
    }

    return 0;
}

/*
gcc 7a.c -o 7a
./7a test.txt data
*/