#include <iostream>
#include <fstream>
#include <string>
#include <ios>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

bool cmp(std::pair<std::string,int> a, std::pair<std::string,int> b){
  return a.second>b.second;
}

int main(){
	std::string str;
	std::ifstream in;
	std::map<std::string,int> freq;
	std::vector<std::pair<std::string,int>> sorted_freq;
  in.open("abc.txt",std::ios::in);
  while(in>>str){
	std::cout << str << std::endl;
	freq[str]++;
  }
  for(auto& i: freq){
	  std::cout << i.first << " " << i.second << std::endl;
	  sorted_freq.push_back(i);
  }
  std::sort(sorted_freq.begin(),sorted_freq.end(),cmp);
  for(auto& i: sorted_freq)
	  std::cout << i.first << " " << i.second << std::endl;



}
