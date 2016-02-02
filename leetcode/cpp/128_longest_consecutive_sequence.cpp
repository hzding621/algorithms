#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

class Solution {
public:
	int longestConsecutive(vector<int> &num) {  
		unordered_map<int, int> hashmap;  
		vector<int> length(num.size(),0);  
		for(int i =0; i< num.size(); i++)  {  
			 hashmap[num[i]]=i;  
		}  
		for(int i =0; i< num.size(); i++)  
		{  
			 // skip the node, which already calculate the length  
			 if(length[i] > 0) 
			 	continue;                 
			 length[i] = consecutiveLength(num[i], hashmap, length);  
		}  
		int maxV = INT_MIN;  
		for(int i =0; i< num.size(); i++)  {  
			 maxV = length[i]>maxV?length[i]:maxV;  
		}  
		return maxV;  
   }  

   int consecutiveLength(int num, unordered_map<int, int>& hashmap, vector<int>& length)  
   {  
		if(hashmap.find(num) == hashmap.end()) 
			return 0;  
		int index = hashmap[num];  
		// skip the node, which already calculate the length  
		if(length[index] > 0) 
			return length[index];  
		else  {  
			 // hit each fresh node only once  
			 length[index] = consecutiveLength(num - 1, hashmap, length) + 1;  
			 return length[index];  
		}  
   }
};

int main() {

	Solution s;

	vector<int> num = {2,7,1,3,8,4,5,0};
	cout << s.longestConsecutive(num) << endl;

	return 0;
}