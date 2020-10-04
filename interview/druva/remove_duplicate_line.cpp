/*
 * Program to remove duplicate lines from a file.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <ios>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>


int main(){
	std::string str;
	std::ifstream in;
	std::ofstream out;
	std::set<std::string> unique_lines;
	//std::vector<std::pair<std::string,int>> sorted_freq;

  in.open("abc.txt",std::ios::in);
  out.open("abc_new.txt",std::ios::out);

  while(std::getline(in,str)){
	std::cout << str << std::endl;
	if(unique_lines.insert(str).second==true){
		out << str <<std::endl;
	}
  }
/*  for(auto& i: freq){
	  std::cout << i.first << " " << i.second << std::endl;
	  sorted_freq.push_back(i);
  }
  std::sort(sorted_freq.begin(),sorted_freq.end(),cmp);
  for(auto& i: sorted_freq)
	  std::cout << i.first << " " << i.second << std::endl;
*/


}
