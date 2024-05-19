#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "file.h"
#include "cli.h"

int main(int argc, char *argv[])
{

    char cwd[256];

    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd");
        return -1;
    }
    else
    {

        for (size_t i = 0; i < strlen(argv); i++)
        {
            if (argv[i] == NULL)
            {
                bls_default(cwd);
                break;
            }
            else if (strcmp(argv[i], "-info") == 0)
            {
                bls_info(cwd);
                break;
            }
        }

        return 0;
    }
}
