#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "createDirectory.h"
int isDirectory(const char* path){//Fucntion checks to see if it's a directory that exists
    struct stat statbuf;
    if(stat(path, &statbuf)!=0)
        return 0;
    return S_ISDIR(statbuf.st_mode);
}
/*void makeDirectory(const char* path){
    if(isDirectory(path)!=0){
        DIR* directory=opendir(path);
    }
}
void closeDirectory(DIR* directory){
    if(isDirectory(path)==0){
        closedir(directory);
    }
}*/
//fix isDirectory.
void makeMusicDir(const char* path,char **musicFile,char* fName){//make music
    char cPath[MAX_PATH];//keeps track of current working directory
    char tPath[MAX_PATH];//temp that keeps track of original directory
    strcpy(tPath,path);
    strcat(tPath,"/");
    strcat(tPath,fName);
    int i=0;
    /*for(i=0;i<3;i++){
        printf("Music%d : %s",i,musicFile[i]);
        fflush(stdout);
    }*/
    strcpy(cPath,path);
    strcat(cPath,"/music");
    if(isDirectory(cPath)==0){
        mkdir(cPath,0700);
    }
    strcat(cPath,"/");
    //printf("Music: %s\n", musicFile[0]);
    //fflush(stdout);
    strcat(cPath,musicFile[0]);
    if(isDirectory(cPath)==0){
        mkdir(cPath,0700);

    }
    strcat(cPath,"/");
    //printf("Music 1: %s\n",musicFile[1]);
    //fflush(stdout);
    strcat(cPath,musicFile[1]);
    if(isDirectory(cPath)==0){
        mkdir(cPath,0700);
    }
    strcat(cPath,"/");
    //printf("Music: %s\n",musicFile[2]);
    //fflush(stdout);
    strcat(cPath,musicFile[2]);
    rename(tPath,cPath);
}
void makeMovieDir(const char* path, char** movieFile, char* fName){//make movie
    char cPath[MAX_PATH];//keeps track of current working directory
    char tPath[MAX_PATH];//temp that keeps track of original directory
    strcpy(tPath,path);
    strcat(tPath,"/");
    strcat(tPath,fName);
    strcpy(cPath,path);
    strcat(cPath,"/movie");
    if(isDirectory(cPath)==0){
        mkdir(cPath,0700);
    }
    strcat(cPath,"/");
    strcat(cPath,movieFile[0]);
    if(isDirectory(cPath)==0){
        mkdir(cPath,0700);
    }
    strcat(cPath,"/");
    strcat(cPath,movieFile[1]);
    rename(tPath,cPath);
}
void makeShowDir(const char* path, char** showFile, char* fName){//make show
    char cPath[MAX_PATH];//keeps track of current working directory
    char tPath[MAX_PATH];//temp that keeps track of original directory
    strcpy(tPath,path);
    strcat(tPath,"/");
    strcat(tPath,fName);
    strcpy(cPath,path);
    strcat(cPath,"/shows");
    if(isDirectory(cPath)==0){
        mkdir(cPath,0700);
    }
    strcat(cPath,"/");
    strcat(cPath,showFile[0]);
    if(isDirectory(cPath)==0){
        mkdir(cPath,0700);
    }
    strcat(cPath,"/");
    strcat(cPath,showFile[1]);
    if(isDirectory(cPath)==0){
        mkdir(cPath,0700);
    }
    strcat(cPath,"/");
    strcat(cPath,showFile[2]);
    strcat(cPath,"-");
    strcat(cPath,showFile[3]);
   // printf("tPath: %s\n",tPath);
    //printf("cPath: %s\n",cPath);
    rename(tPath,cPath);
}
void makeDocDir(const char* path,char** docFile, char* fName){//make doc
    char tPath[MAX_PATH];//temp that keeps track of original directory
    strcpy(tPath,path);
    strcat(tPath,"/");
    strcat(tPath,fName);
    //printf("tPath: %s",tPath);
    char cPath[MAX_PATH];//keeps track of current working directory
    strcpy(cPath,path);
    strcat(cPath,"/documents");
    if(isDirectory(cPath)==0){
        mkdir(cPath,0700);
    }
    strcat(cPath,"/");
    strcat(cPath,fName);
    rename(tPath,cPath);
}
void makeImageDir(const char* path, char** imageFile, char* fName){//make image
    char cPath[MAX_PATH];//keeps track of current working directory
    char tPath[MAX_PATH];//temp that keeps track of original directory
    strcpy(tPath,path);
    strcat(tPath,"/");
    strcat(tPath,fName);
    //printf("tPath: %s",tPath);
    strcpy(cPath,path);
    strcat(cPath,"/pictures");
    if(isDirectory(cPath)==0){
        mkdir(cPath,0700);
    }
    strcat(cPath,"/");
    strcat(cPath,fName);
    rename(tPath,cPath);
}
void makeOthersDir(const char* path, char** imageFile, char* fName){//make others
    char cPath[MAX_PATH];//keeps track of current working directory
    char tPath[MAX_PATH];//temp that keeps track of original directory
    strcpy(cPath,path);
    strcat(cPath,"/others");
    if(isDirectory(cPath)==0){
        mkdir(cPath,0777);
    }
    strcat(cPath,"/");
    strcat(cPath,fName);
    strcpy(tPath,path);
    strcat(tPath,"/");
    strcat(tPath,fName);
    rename(tPath,cPath);
}
// char** tokenized(char *fName){
//     char temp[MAX_PATH];
//     int i=0;
//     int j=0;
//     char** tokens;
//     strcpy(temp,fName);
//     const char* delim="-";
//     char* token;
//     token=strtok(temp,delim);
//     //length=strlen(token);
//     tokens=malloc(5*sizeof(char*));
//     tokens[i]=token;
//     i++;
//     while((token=strtok(NULL,delim))!=NULL){
//         tokens[i]=token;
//         i++;
//     }
//     tokens[i]=NULL;
//     /*for(j=0;j<i;j++){
//         printf("Tokens: %s",tokens[j]);
//     }*/
//     return tokens;
// }
void organize(DIR* directoryy,const char* path){//organize function
    struct dirent* e;

   // tokens=malloc(4*sizeof(char*));
    if(isDirectory(path)!=0){//Makes sure path exists
        while((e=readdir(directoryy))!=NULL){//reads directory

            /*THESE VARIABLES USED TO BE OUTSIDE THE LOOP*/
            char cpathName[MAX_PATH];//
            char temp[MAX_PATH];//temporary hold to be tokenized
            char names[MAX_PATH];//file name
            int i=0;
            int j=0;
            int k=0;
            char extra[10];
            char **tokens;

            /*RESET INDEXES HERE TO FIX EXTENSION PROBLEM*/
            i=0;
            j=0;
            k=0;
            strcpy(names,e->d_name);
            strcpy(temp,names);


            /*THIS CODE USED TO BE IN THE TOKENIZER FUNCTION. PUTTING IT HERE FIXED SEGFAUL FOR SOME REASON*/
            const char* delim="-";
            char* token;
            token=strtok(temp,delim);
            //length=strlen(token);
            tokens=malloc(5*sizeof(char*));
            tokens[i]=token;
            i++;
            while((token=strtok(NULL,delim))!=NULL){
                tokens[i]=token;
                i++;
            }
            tokens[i]=NULL;
            /*END OF TOKENIZER CODE*/

            int a = 0;
            for(a=0; a<3; a++)
            {
                if(tokens[a] != NULL)
                {
                    printf("token %d is %s\n",a, tokens[a]);
                }
            }


            for(i=strlen(names)-1;i>0;i--){
                if(names[i]=='.'){
                    k=i;
                    k=k-1;
                    break;
                }
            }
            if(i>0){
                while(i<strlen(names)){
                    extra[j]=names[i];
                    i++;
                    j++;
                }
            extra[j]='\0';

            }

            /*ADDED THIS ELSE TO SKIP FILES WITHOUT EXTENSIONS*/
            else
            {
                continue;
            }

           printf("Extention: %s\n",extra);

            if(strcmp(extra,".mp3")==0){
              /*  for(i=0;i<3;i++){
                printf("Tokens %d : %s",i,tokens[i]);
                fflush(stdout);
            }*/
                makeMusicDir(path,tokens,names);
                printf("Music\n");
            }
            else if(strcmp(extra, ".mkv")==0){
                if(tokens[2]==NULL){
                    makeMovieDir(path,tokens,names);
                    printf("Movie\n");
                }
                else{
                    makeShowDir(path,tokens,names);
                    printf("Shows\n");
                }
            }
            else if(strcmp(extra, ".png")==0||strcmp(extra,".jpg")==0){
                makeImageDir(path,tokens,names);
                printf("images\n");
            }
            else if(strcmp(extra, ".docx")==0||strcmp(extra,".txt")==0){
                makeDocDir(path,tokens,names);
                printf("Docs\n");
            }
            else{
                if(strcmp(extra, ".c")==0||strcmp(extra,".o")==0||strcmp(extra,".h")==0){
                    continue;
                   }
                else{
                    makeOthersDir(path,tokens,names);
                    printf("Others\n");
                   }
            }
        }
    }
    else{
        perror("Error: ");
        exit(1);
    }
}

