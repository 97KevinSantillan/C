#include <assert.h>
#include "array_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include "mybool.h"

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {

    FILE *archivo = NULL;
    unsigned int len = 0;
    archivo = fopen(filepath, "r"); 
    assert(archivo != NULL); 
    fscanf(archivo, "%u", &len); 
    for (unsigned int i = 0; i < len && i < max_size; ++i){ 
        fscanf(archivo, "%d", &array[i]);
    }
    fclose(archivo); 
    return len;
}


void array_dump(int a[], unsigned int length) {

    printf("[ ");
    for (unsigned int i = 0; i < length; ++i) {
        printf("%d", a[i]);
        if (i < length-1) {
            printf(", ");
        }
    }
    printf("]\n");
}

mybool array_is_sorted(int a[], unsigned int length){

    mybool sorted = true;
    if (length == 0)
    {
     sorted = sorted;   
    } else {
        for (unsigned int j = 0u; j < length-1 && sorted; ++j){ // Avoid edge cases (length -1)
            sorted = sorted && a[j] <= a[j+1];
        }
    } 
    return sorted;
}
