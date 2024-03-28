#include <stdio.h>

#define SET_BIT(data, pos) (data | (0x00000001<<pos))
#define IS_BIT_SET(data, pos) ((data >> pos) & 0x00000001)
// To execute C, please define "int main()"

int main() {
  unsigned int data = 0x00000000;
  for (int i = 0; i < 32; i++) {
    SET_BIT(data, i);
    for(int j=0; j<32; j++){
      if(IS_BIT_SET(data, j)){
        printf("+");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }

  return 0;
}