#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_present(char ch, char* delim){
	char* ptr=delim;
	while(*ptr!=NULL){
		printf("is_presenet *end=%c\n",(char)*ptr);
		if(*ptr==ch)
			break;
		ptr++;
	}
	
	return (*ptr==NULL)?false:true;
}

void my_strtok(char* src,char*delim){
	char* start=src;
	char* end=src;
	char* res=NULL;
	int i=0;
	while(*end!=NULL){
	//int j=0;
	//while(j++<2){
		printf("1 *end=%c\n",*end);
		i=0;
		while(!is_present((char)*end,delim)){
		//while(i<5){
			printf("2 *end=%c\n",*end);
			end++;
			i++;
		}
		res=malloc(sizeof(char)*(i+1));
		memset(res,0,i+1);
		strncpy(res,src,i);
		printf("%s\n",res);
		if(*end!=NULL){
		src = end+1;
		end = src;
		}
	}
return;
}

int main(){
	char str[]={"kashi-hello-what?"};
	char delim[]="-?";
	char *string=NULL;
	//my_strtok(str,delim);
	//printf("");
	string = strtok(str,delim);
	while(string!=NULL){
			printf("%s\n",string);
			string=strtok(NULL,delim);
			}
	printf("string=%s\n",str);
}
