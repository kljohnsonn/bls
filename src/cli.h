#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "file.h"

#define BLUE(string) "\x1b[1;94m" string "\x1b[0m"
#define GREEN(string) "\x1b[1;92m" string "\x1b[0m"


void bls_default(const char *);

void bls_info(const char *);