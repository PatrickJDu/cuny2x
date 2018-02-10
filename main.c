#include"createDirectory.h"
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include "createDirectory.h"
int main(int argc, char** argv){
    char cwd[MAX_PATH];
    struct dirent *d;
    DIR* pDir;
    //too much arguments
    if(argc>2){
        perror("Error: ");
    }
    //1 argument error check otherwise do stuff
    if(argc==1){
        if((getcwd(cwd,MAX_PATH))==NULL){
            perror("Error: \n");
        }
        else{
            if((pDir=opendir(cwd))!=NULL){
                printf("cwd: %s\n",cwd);
                organize(pDir,cwd);
                printf("ORGANIZED: %s\n",cwd);
                closedir(pDir);
            }
            else if(ENOENT==errno){
                perror("Error :");
                exit(1);
            }
            else{
                perror("Error :");
                exit(1);
            }
        }
    }
    //two argument check
    if(argc==2){
        pDir=opendir(argv[1]);
        if(pDir){
            organize(pDir,argv[1]);
            closedir(pDir);
        }
        else if(ENOENT==errno){
            perror("Error :");
            exit(1);
        }
        else{
            perror("Error :");
            exit(1);
        }
    }
    return 0;
}
