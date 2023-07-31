#include <stddef.h>
#include <stdio.h>

int isEven(int a){
    if(a%2==0){
        return 1;
    }else {
        return 0;
    }
}
int isPrime(int a){
    int c =0;
    for(int i=1; i<=a; i++){
            if(a%i == 0){
                c++;
            }
    }
    if(c == 2){
        return 1;
    }else {
        return 0;
    }
}

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f) (int),int dest[],size_t* dest_cnt,int arr2[],size_t* dest_cnt2){

    for(size_t i= 0; i < n; i ++ ){
        if(filter_f(arr[i]) == 1){
            dest[*dest_cnt] = arr[i];
            *dest_cnt+=1;
        }
    }

    
    for(size_t i = 0; i<n; i++){
        printf("print i %ld\n", i);
        printf("print arr[i] %d\n",arr[i]);
        if(map_f(arr[i]) == 1){
            
            arr2[*dest_cnt2] = arr[i]*arr[i];
            *dest_cnt2+=1;
        }
        
    }
}

int main(){
    int arr[8] = {1,2,3,4,-1,7,11,23};
    int dest[10];
    int arr2[10];
    size_t new_size;
    size_t new_size2;
    printf("Array before: ");
    for(size_t i = 0; i< 8; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    filter_and_map(arr, 8, isEven, isPrime, dest, &new_size,arr2,&new_size2);
    printf("new_size: %ld\n",new_size);
    printf("Array with even: ");
    for(size_t i = 0; i< new_size; i++){
        printf("%d ", dest[i]);
    }
    printf("\n");

    printf("Array with square prime: ");
    for(size_t i = 0; i< new_size2; i++){
        printf("%d ", arr2[i]);
    }
    printf("\n");


    return 0;
}