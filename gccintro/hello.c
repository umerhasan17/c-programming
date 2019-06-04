#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Hello, world!\n");

    unsigned int value = 100;
    unsigned int value2 = 200;
    unsigned char bytes[4];
    unsigned char bytes2[4];
    bytes[0] = (value >> 24) & 0xFF;
    bytes[1] = (value >> 16) & 0xFF;
    bytes[2] = (value >> 8) & 0xFF;
    bytes[3] = value & 0xFF;
    bytes2[0] = (value2 >> 24) & 0xFF;
    bytes2[1] = (value2 >> 16) & 0xFF;
    bytes2[2] = (value2 >> 8) & 0xFF;
    bytes2[3] = value2 & 0xFF;
    // printf("%llu", sizeof(bytes));
    FILE * fPointer;
    fPointer = fopen("test3.bin", "wb");
        
    fwrite(bytes, sizeof(bytes), 1, fPointer);
    printf("Writing new line\n");
    fwrite("\n", sizeof(char), 1, fPointer);
    fwrite(bytes2, sizeof(bytes2), 1, fPointer);
    // for (int i = 0; i < sizeof(bytes); i ++) {
    //     fwrite(bytes, )
    //     if (i % 4 == 3) {

    //     }
    // }
    fclose(fPointer);

}