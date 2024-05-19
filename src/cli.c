#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "file.h"
#include "cli.h"
#include <time.h>
#include <pwd.h>
#include <grp.h>

void bls_default(const char *cwd)
{
    struct dirent *pDirent;

    DIR *pDir;

    pDir = open_directory(cwd);

    while ((pDirent = readdir(pDir)) != NULL)
    {
        if (!strcmp(pDirent->d_name, ".") || !strcmp(pDirent->d_name, ".."))
        {
            continue;
        }
        else
        {
            if (is_directory(pDirent->d_name))
            {
                printf("  " BLUE("%s") "  ", pDirent->d_name);
            }
            else
            {
                printf("  " GREEN("%s") "", pDirent->d_name);
            }
        }
    }

    closedir(pDir);
}

void bls_info(const char *cwd)
{
    struct dirent *pDirent;

    DIR *pDir;

    pDir = open_directory(cwd);

    while ((pDirent = readdir(pDir)) != NULL)
    {
        if (!strcmp(pDirent->d_name, ".") || !strcmp(pDirent->d_name, ".."))
        {
            continue;
        }
        else
        {
            struct stat info;
            info = file_info(pDirent->d_name);
            char date[256];
            time_t now = time(NULL);
            char *user_name = getpwuid(info.st_uid)->pw_name;
            char *group_name = getgrgid(info.st_gid)->gr_name;
            strftime(date, sizeof date, "%F %T", localtime(&now));

            if (is_directory(pDirent->d_name))
            {
                printf((S_ISDIR(info.st_mode)) ? "d" : "-");
                printf((info.st_mode & S_IRUSR) ? "r" : "-");
                printf((info.st_mode & S_IWUSR) ? "w" : "-");
                printf((info.st_mode & S_IXUSR) ? "x" : "-");
                printf((info.st_mode & S_IRGRP) ? "r" : "-");
                printf((info.st_mode & S_IWGRP) ? "w" : "-");
                printf((info.st_mode & S_IXGRP) ? "x" : "-");
                printf((info.st_mode & S_IROTH) ? "r" : "-");
                printf((info.st_mode & S_IWOTH) ? "w" : "-");
                printf((info.st_mode & S_IXOTH) ? "x" : "-");
                fprintf(stdout, "  %d  %s   %s   %-20s %-10lld" BLUE("%s\n"), info.st_nlink,  user_name, group_name, date, info.st_size, pDirent->d_name);
            }
            else
            {
                printf((S_ISDIR(info.st_mode)) ? "d" : "-");
                printf((info.st_mode & S_IRUSR) ? "r" : "-");
                printf((info.st_mode & S_IWUSR) ? "w" : "-");
                printf((info.st_mode & S_IXUSR) ? "x" : "-");
                printf((info.st_mode & S_IRGRP) ? "r" : "-");
                printf((info.st_mode & S_IWGRP) ? "w" : "-");
                printf((info.st_mode & S_IXGRP) ? "x" : "-");
                printf((info.st_mode & S_IROTH) ? "r" : "-");
                printf((info.st_mode & S_IWOTH) ? "w" : "-");
                printf((info.st_mode & S_IXOTH) ? "x" : "-");
                fprintf(stdout, "  %d  %s   %s   %-20s %-10lld" GREEN("%s\n"), info.st_nlink, user_name, group_name, date, info.st_size, pDirent->d_name);
            }

            fflush(stdout);
        }
    }

    closedir(pDir);
}