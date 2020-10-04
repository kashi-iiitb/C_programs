#include <iostream>
#include <sstream>
#include <stack>

int main(){
  std::stack<std::string> st;
  std::string sentence("hello nice world");
  std::string word;
  std::stringstream ss(sentence);

  while(ss>>word){
	  std::cout <<word << "pushed" << std::endl;
	  st.push(word);
  }
  
  //sentence.append(std::endl);
	  sentence.append(" ");

  while(!st.empty()){
	  std::cout << "popped" << std::endl;
	  sentence.append(st.top());
	  sentence.append(" ");
	  st.pop();
  }
  std::cout << sentence << std::endl;


}
