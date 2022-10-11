#include <stdio.h>
#include <stdlib.h>

int* rand_arr(int* arr, int size){
    for (int i=0;i<size;i++){
        arr[i]=rand();
    }
    return arr;
}

void print(int* a, int size){
    for (int i=0;i<size;i++){
        printf("%d", a[i]);
    }
}

int main(){
    int size_arr1,size_arr2;
    printf("Input size of arrays: \n");
    printf("Size of 1st = ");
    scanf("%d", &size_arr1);
    printf("\n Size of 1st = ");
    scanf("%d", &size_arr2);
    if (size_arr1 <= 0 || size_arr2 < 0){
        printf("\nInput error: impossible size!");
        return 0;
    }
    int* arr1 = (int*)malloc(size_arr1 * sizeof(int));
    int* arr2 = (int*)malloc(size_arr2 * sizeof(int));
    int* res = (int*)malloc(size_arr1 * sizeof(int));
    rand_arr(arr1, size_arr1);
    rand_arr(arr2, size_arr2);
    if(size_arr2 == 0){
        print(arr1, size_arr1);
    }
    else{
        for (int i=0;i<size_arr1;i++){
            if (i>size_arr2-1) res[i]=arr1[i]+arr2[size_arr2-1];
            else res[i]=arr1[i]+arr2[i];
        }
    }
    print(res,size_arr1);
    free(arr1);
    free(arr2);
    free(res);
    return 0;
}
