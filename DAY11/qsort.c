#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define COUNT 30

typedef struct Book{
    char name[150];
    char author[100];
    int pages;
    float price;
}Book;
char *alphabet="abcdefghijklmnopqrstuvwxyz";

int generate(int min, int max){
    return (rand()%(max -min+1)+min);
}
void randomName(int lenght, char n[]){
    int i;
    for(i=0; i<lenght; i++){
        int k = generate(1, 26);
        n[i] = alphabet[k-1];
    }
    n[0] = toupper(n[0]);
    n[i] = '\0';
}

int pagesASC(const void * a, const void * b){
    return (((Book*)a) -> pages - ((Book*)b) -> pages);

}
int pagesDESC(const void * a, const void * b){
        return (((Book*)b) -> pages - ((Book*)a) -> pages);

}
int pricesASC(const void * a, const void * b){
        return (((Book*)a) -> price - ((Book*)b) -> price)*10;

}
int pricesDESC(const void * a, const void * b){
        return (((Book*)b) -> price - ((Book*)a) -> price)*10;

}

void print_arr(Book arr[], size_t n){
    for(size_t i = 0; i < n; i++){
        printf("%s \t %s \t %d \t %.2lf \n", arr[i].name,arr[i].author,arr[i].pages,arr[i].price);
    }
    printf("\n");
}

int main(){
    Book *arr = malloc( COUNT*sizeof(Book));
   
    for(size_t i =0; i < COUNT; i++){
        int names = generate(10,20);
        randomName(names,arr[i].name);
        randomName(names,arr[i].author);
        arr[i].pages = generate(5,2000);
        arr[i].price = generate((double)1.00, (double)1000.00);

    }
    print_arr(arr, COUNT);
    qsort(arr, COUNT, sizeof(Book), pagesASC);
    print_arr(arr, COUNT);
    qsort(arr, COUNT, sizeof(Book), pagesDESC);
    print_arr(arr, COUNT);
    qsort(arr, COUNT, sizeof(Book), pricesASC);
    print_arr(arr, COUNT);
    qsort(arr, COUNT, sizeof(Book), pricesDESC);
    print_arr(arr, COUNT);

    return 0;
}