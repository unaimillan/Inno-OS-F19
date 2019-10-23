#pragma GCC diagnostic warning "-Wall"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <memory.h>
#include <assert.h>

#define MAX_FILE_COUNT 100
#define MAX_FILENAME_SIZE 1024
#define MAX_RECORDS_AMOUNT 100

typedef struct {
    __ino_t inode;
    size_t count;
    char filenames[MAX_FILE_COUNT][MAX_FILENAME_SIZE];
} iRecord;

iRecord records[MAX_RECORDS_AMOUNT];

void init_irecord(iRecord record[]){
    for(int i = 0; i < MAX_RECORDS_AMOUNT; ++i)
    {
        record[i].inode= 0;
        record[i].count=0;
        for(int j = 0; j < MAX_FILE_COUNT; ++j){
            memset(record[i].filenames[j], 0, sizeof(char)*MAX_FILENAME_SIZE);
        }
    }
}

// Find or add inode to records array
size_t find_irecord(size_t inode){
    for(int i = 0; i < MAX_FILE_COUNT; ++i){
        if(records[i].inode == inode) {
            return i;
        } else if(records[i].inode == 0){
            records[i].inode = inode;
            return i;
        }
    }
    assert(0);
    return -1;
}

void append_filename(size_t index, char flname[]){
    strcpy(records[index].filenames[records[index].count], flname);
    records[index].count += 1;
}

int main(){
    init_irecord(records);

    DIR* dir_stream = opendir(".");
    struct dirent* entry;

    while((entry = readdir(dir_stream)) != NULL){
        if(entry->d_name[0] == '.'){
            continue;
        }

        struct stat buf;
        stat(entry->d_name, &buf);

        if(buf.st_nlink <= 1){
            continue;
        }

        size_t index = find_irecord(buf.st_ino);
        append_filename(index, entry->d_name);
    }

    if(records[0].inode == 0){
        printf("No inodes with >1 hardlinks found!\n");
    }

    for(int i = 0; records[i].inode != 0; ++i){
        printf("For i-node %lu found:\n", records[i].inode);
        for(int j = 0; j < records[i].count; ++j){
            printf("    %s\n", records[i].filenames[j]);
        }
    }
    closedir(dir_stream);
    return 0;
}