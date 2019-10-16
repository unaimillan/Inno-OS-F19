#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>
#include <memory.h>
#include <assert.h>

typedef struct {
    int id;
    unsigned int counter;
} page_t;

const unsigned int INF = -1;
const unsigned int RBit = 1u<<(sizeof(int)*8-1);
int PAGE_AMOUNT = 0;
int hits = 0;
int misses = 0;
FILE* inputFile = NULL;

// Lookup through the table and update counters
// Returns 1 if page have hit and 0 otherwise
char lookup(int pageid, page_t table[]){
    char success = 0;

    for(int i = 0; i < PAGE_AMOUNT; ++i){
        table[i].counter >>= 1u;
        if(table[i].id == -1){
            table[i].id = pageid;
            table[i].counter = RBit;
            success = 1;
            break;
        }else if(table[i].id == pageid){
            table[i].counter |= RBit;
            success = 1;
        }
    }

    return success;
}

void insert_page(int pageid, page_t table[]){
    unsigned int mindex = -1, mcount = INF;
    for(int i = 0; i < PAGE_AMOUNT; ++i){
        if(table[i].id == -1){
            table[i].id = pageid;
            table[i].counter = RBit;
        }
        if(table[i].counter < mcount){
            mindex = table[i].id;
            mcount = table[i].counter;
        }
    }

    assert(mindex != -1);
    table[mindex].id = pageid;
    table[mindex].counter |= RBit;
}

// Helper functions
// Return next referencing page number from the file
int next_page(){
    int buff = 0;
    if(fscanf(inputFile, "%d", &buff) == 1){
        return buff;
    }
    return -1;
}

// Initialize page table with zero values
void initialize_table(page_t table[]){
    for(int i = 0; i < PAGE_AMOUNT; ++i){
        table[i].id=-1;
        table[i].counter = 0;
    }
}

// Print to 'stdout' usage message
void print_usage(){
    printf("Usage: ./ex1 number file\nwhere\n");
    printf("\tnumber - is a amount of page frames\n");
    printf("\tfile - is a path to input file\n");
}

int main(int argc, char* argv[]) {
    if(argc != 3){
        print_usage();
        exit(0);
    }

    PAGE_AMOUNT = (int)strtol(argv[1], NULL, 10);

    if(PAGE_AMOUNT < 1){
        printf("Incorrect 'number' specified\nExiting...");
        exit(0);
    }

    inputFile = fopen(argv[2], "r");
    if(inputFile == NULL){
        printf("Failed to open specified 'file'\nExiting...");
        exit(0);
    }

    page_t memtable[PAGE_AMOUNT];
    initialize_table(memtable);

    // Index of the referencing page
    int ref_index = -1;

    while((ref_index = next_page()) != -1){

        if(lookup(ref_index, memtable) == 1){
            hits++;
        }else{
            misses++;
            insert_page(ref_index, memtable);
        }
    }

    printf("%d page frames\n", PAGE_AMOUNT);
    printf("    %d hits, %d misses\n", hits, misses);
    printf("    Hit/Miss ration is: %lf\n", (double)hits/misses);

    return (0);
}
