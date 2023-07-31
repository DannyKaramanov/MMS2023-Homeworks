#include <stddef.h>
#include <stdio.h>

int isPositive(int a){
    if(a>0){
        return 1;
    }else {
        return 0;
    }
}
int addOne(int a){
    a+=1;
    return a;
}

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f) (int),int dest[],size_t* dest_cnt){

    for(size_t i= 0; i < n; i ++ ){
        if(filter_f(arr[i]) == 1){
            int temp = map_f(arr[i]);
            dest[*dest_cnt] = temp;
             *dest_cnt+=1;
        }
    }
}

int main(){
    int arr[8] = {1,2,3,4,-1,-2,11,-100};
    int dest[10];
    size_t new_size;
    printf("Array before: ");
    for(size_t i = 0; i< 8; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    filter_and_map(arr, 8, isPositive, addOne, dest, &new_size);
    printf("new_size: %ld\n",new_size);
    printf("Array after: ");
    for(size_t i = 0; i< new_size; i++){
        printf("%d ", dest[i]);
    }
    printf("\n");


    return 0;
}