#include "file.h"
#include <stdio.h>



DIR *open_directory(const char *cwd)
{
    DIR *pDir;
    pDir = opendir(cwd);
    if (pDir == NULL)
    {
        perror("opendir");
        return NULL;
    }

    return pDir;
}


bool is_directory(char* path)
{
    struct stat path_stat;

    if(stat(path, &path_stat) != 0) {
        return 0;
    }

    return S_ISDIR(path_stat.st_mode);
}

struct stat file_info(char* path) {
    struct stat path_stat;

    if (stat(path, &path_stat) != 0)
    {
        return path_stat;
    }

    return path_stat;
}