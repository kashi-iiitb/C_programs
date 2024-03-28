#include <stdio.h>

int main(){
    unsigned int data = 0x12345678;
    unsigned int big_end_data=0;
    char *ptr;
    printf("Little Endian format:\n");
    for(int i=0; i<4; i++){
        ptr = ((char *)&data)+i;
        printf("ptr= %p byte=%0x\n", ptr, (__uint8_t)*ptr);
    }
    big_end_data = ((data & (0xFF << 24)) >> 24) | ((data & 0xFF) << 24) |
                    (data & (0xFF << 16) >> 8) | (data & (0xFF << 8) << 8);
    printf("Big Endian format:\n");
        for(int i=0; i<4; i++){
        ptr = ((char *)&big_end_data)+i;
        printf("ptr= %p byte=%0x\n", ptr, (__uint8_t)*ptr);
    }
}