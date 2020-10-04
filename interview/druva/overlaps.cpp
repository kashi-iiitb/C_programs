#include <iostream>
#include <vector>
#include <limits>

std::pair<int,int> find_min_beg_max_end(const std::vector<std::pair<int,int>> &intervals){
	int min_start=std::numeric_limits<int>::max(),max_end=0;
	for(auto& i:intervals){
		if(i.first<min_start)
			min_start=i.first;
		if(i.second>max_end)
			max_end=i.second;
	}
	return std::make_pair(min_start,max_end);
}
int main(){
	std::vector<std::pair<int,int>> intervals;
	intervals.push_back(std::make_pair(1,3));
	intervals.push_back(std::make_pair(5,7));
	intervals.push_back(std::make_pair(2,5));
	intervals.push_back(std::make_pair(6,8));
	intervals.push_back(std::make_pair(4,7));
	intervals.push_back(std::make_pair(6,9));
	intervals.push_back(std::make_pair(2,4));
	intervals.push_back(std::make_pair(4,6));
	intervals.push_back(std::make_pair(7,10));
	intervals.push_back(std::make_pair(2,5));
	intervals.push_back(std::make_pair(5,8));
	intervals.push_back(std::make_pair(1,4));
	intervals.push_back(std::make_pair(5,8));
	intervals.push_back(std::make_pair(3,6));
	std::pair<int,int> beg_end;
	beg_end = find_min_beg_max_end(intervals);
	std::cout << "min begin:" << beg_end.first << "max_end:" <<beg_end.second << std::endl;

	std::vector<std::pair<int,int>> overlaps(beg_end.second-beg_end.first+1);
	for(auto& i: intervals){
		for(auto j=i.first; j<=i.second; j++){
			overlaps.at(j-beg_end.first).first++;
			overlaps.at(j-beg_end.first).second=j;

		}
	}
	int max=0,index=0;
	for(auto& i:overlaps){
		if(i.first>max){
			max = i.first;
			index=i.second;
		}
	}
	std::cout <<"max overlaps="<<max << "at time=" << index ;
}
