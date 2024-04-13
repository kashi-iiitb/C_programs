#include <stdio.h>
#include <time.h>

int main(int argc, char **argv){
    if(argc<3){
        printf("Insufficient arguments passed.\nMinimum 3 arguments required.");
        return -1;
    }
    printf("Hi %s %s\n", argv[0], argv[1]);
    printf("Welcome!!!\n");
    __time_t t;
    struct tm *tm;
    t = time(NULL);
    //tm = localtime(&t);
    printf("Today is: %s\n", ctime(&t));
}