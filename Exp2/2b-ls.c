#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dirop;
    struct dirent *dired;

    if (argc != 2)
    {
        printf("Invalid number of arguments\n");
        return 1;
    }

    if ((dirop = opendir(argv[1])) == NULL)
    {
        printf("Cannot open the directory\n");
        return 1;
    }

    while ((dired = readdir(dirop)) != NULL)
        printf("%ld %s\n", dired->d_ino, dired->d_name);

    closedir(dirop);
    return 0;
}
