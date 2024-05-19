#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>


DIR *open_directory(const char *);
bool is_directory(char* path);
struct stat file_info(char* path);