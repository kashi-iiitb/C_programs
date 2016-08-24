#include <iostream>       // std::cout
#include <string>         // std::string
#include <locale>         // std::locale, std::tolower
#include <cstring>
int main ()
{
//  std::locale loc;
  char str[100]="Test String.";
  for (int i=0; i<strlen(str); ++i)
     std::tolower(str[i]);
  std::cout << str << std::endl;
  return 0;
}
