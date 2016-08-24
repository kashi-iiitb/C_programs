#include <cstring>
#include <iostream>
 
int main() 
{
    char input[2000] = "";
    char *token = std::strtok(input, "\\/,.:;'\"-\t=+_{}[]? ~!@#$%^*()");
    while (token != NULL) {
        std::cout << token << '\n';
        token = std::strtok(NULL, " ");
    }
}
