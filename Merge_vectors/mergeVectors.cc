
#include<iostream>
#include<vector>
#include<list>
using std::vector;
vector<int> mergeVectors(const vector<int> &a,const vector<int> &b){
	vector<int> arr;
	int i =0;
	int j =0;	
	while ( i < a.size() && j < b.size()){
		/*Sort the vectors elements*/
		if (a.at(i) > b.at(j)){
			arr.push_back(b.at(j));
			j++;
		}
		else {
			arr.push_back(a.at(i));
			i++;
		}
	}
	while (j < b.size()){
		arr.push_back(b.at(j));
		j++;
	}
	while (i < a.size()){
		arr.push_back(a.at(i));
		i++;
	}

	return arr;
}
