#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char find_char(char* enc_str, int pos){
  int enc_len = strlen(enc_str);
  int dec_len=0;
  char* dec_str=NULL;
  for(int i=0;i<enc_len/2;i++){
	  dec_len+=enc_str[2*i+1]-'0';
  }
  dec_str = (char*)malloc(sizeof(char)*dec_len);
  int dec_i=0;
  for(int i=0;i<enc_len/2;i++){
	  for(int j=0;j<enc_str[2*i+1]-'0';j++){
		  *(dec_str+dec_i+j)=enc_str[2*i];
		  printf("char at dec_i=%d is %c\n",dec_i+j,*(dec_str+dec_i+j));
	  }
	  printf("\n");
	  dec_i += enc_str[2*i+1]-'0';
  }
  *(dec_str+dec_i)='\0';
  printf("char at %d position is %s\n",pos, dec_str);
  return *(dec_str+pos);

}
int main(){
  char encrypt_str[]="a2b3c6d8e9";
  int pos=5;
  printf("char at %d position is %c\n",pos,find_char(encrypt_str,pos));
}
