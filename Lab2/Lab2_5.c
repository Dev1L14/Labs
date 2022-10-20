#include <stdio.h>
#include <stdlib.h>

void print(int* arr, int size){
    for(int i=0;i<size;i++) printf("%d ", arr[i]);
}

void replace(int* minPtr, int* maxPtr){
    int max = *maxPtr;
    int min = *minPtr;
    *minPtr = max;
    *maxPtr = min;
}

int new_arr(int* arr, int* res, int size){
    int size_new = 1;
    res[0] = *arr;
    for (int i = 1; i < size; i++){
        int flag = 0;
        for(int j = 0; j < size_new; j++){
            if(arr[i] == res[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            res[size_new] = arr[i];
            size_new++;
        }

    }
    return size_new;
}

int main(){
    int size=0;
    printf("Enter the size of array: ");
    if(!scanf("%d", &size)){
        printf("Input error: wrong size");
        return 0;
    }
    if(size<=0){
        printf("Input error: wrong size");
        return 0;
    }
    int* arr = (int*)malloc(size*sizeof(int));
    int a;
    int b;
    printf("Enter min boundary: ");
    if(!scanf("%d", &a)){
        printf("Input error!");
        return 0;
    }
    printf("Enter max boundary: ");
    if(!scanf("%d", &b)){
        printf("Input error!");
        return 0;
    }
    for(int i = 0; i<size; i++){
        arr[i] = rand()%(b-a+1)+a;
    }
    printf("Array is: ");
    print(arr, size);
    printf("Enter :\n");
    printf("'1' to replace min and max elements\n");
    printf("'2' to replace min and max elements\n");
    int inp = 0;
    if(!scanf("%d", &inp)){
        printf("Input error!");
        return 0;
    }
    if(inp == 1){
        int max = arr[0], min = arr[0];
        int* minPtr;
        int* maxPtr;
        for (int i = 1; i < size; i++){
            if(arr[i] < min){
                min = arr[i];
                minPtr = arr+i;
            }
            else if(arr[i] > max){
                max = arr[i];
                maxPtr = arr+i;
            }
        }
        replace(minPtr, maxPtr);
        print(arr, size);
    }
    else if(inp == 2){
        int* result = (int*)malloc(size*sizeof(int));
        int size_res = new_arr(arr, result, size);
        print(result, size_res);
        free(result);
    }
    else{
        printf("Input error!");
        return 0;
    }
    free(arr);
    return 0;
}