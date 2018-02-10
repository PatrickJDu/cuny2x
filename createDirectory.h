#include<dirent.h>
int isDirectory(const char* path);
//void makeDirectory(const char* path);
//void closeDirectory(DIR* directory);
void makeMovieDir(const char* path, char** movieFile, char* fName);
void makeShowDir(const char* path, char** showFile, char* fName);
void makeMusicDir(const char* path,char **musicFile,char* fName);
void makeDocDir(const char* path,char** docFile, char* fName);
void makeImageDir(const char* path, char** imageFile, char* fName);
char** tokenized(char *fName);
void organize(DIR* directoryy, const char* path);
void makeOthersDir(const char* path, char** imageFile, char* fName);
#define MAX_PATH 255
