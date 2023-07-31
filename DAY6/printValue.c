#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8_T 5
#define TUINT16_T 6
#define TUINT32_T 7
#define TUINT64_T 8


void printValue(const void* valuePtr, uint8_t flag){
     
     switch (flag) {
        case TINT:
            printf("Value: %d\n", *(int*) valuePtr);
            break;
        case TCHAR:
            printf("Value is: %c\n",*(char*)valuePtr);
            break;
        case TDOUBLE:
            printf("Value is: %.2lf\n",*(double*) valuePtr);
            break;
        case TFLOAT:
            printf("Value is: %.2lf\n",*(float*) valuePtr);
            break;
        case TUINT8_T:
            printf("Value is: %d\n",*(uint8_t*) valuePtr);
            break;
        case TUINT16_T:
            printf("Value is: %d\n",*(uint16_t*) valuePtr);
            break;
        case TUINT32_T:
            printf("Value is: %d\n",*(uint32_t*) valuePtr);
            break;
        case TUINT64_T:
            printf("Value is: %d\n",*(uint64_t*) valuePtr);
            break;
     }
}

int main(){
    int num = 23;
    printValue(&num, TINT);

    double num2 = 3.14;
    printValue(&num2,TDOUBLE);

    char symbol = 'A';
    printValue(&symbol,TCHAR);

    float num3 = 5.15;
    printValue(&num3, TFLOAT);

    uint8_t uint8 = 8;
    printValue(&uint8, TUINT8_T);

    uint16_t uint16= 16;
    printValue(&uint16, TUINT16_T);

    uint32_t uint32 = 32;
    printValue(&uint32, TUINT32_T);

    uint64_t uint64 = 64;
    printValue(&uint64, TUINT64_T);



}