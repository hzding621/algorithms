#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(vector<int>& height) {
    	int i = 0, j = height.size()-1;
    	int maxArea = 0;
    	while (i < j) {
    		maxArea = max(maxArea, min(height[i],height[j]) * (j-i+1));
    		if (height[i] > height[j])
    			j--;
    		else
    			i++;
    	}
    	return maxArea;
    }
};

int main() {

	vector<int> v = {1,2,3,2,1,2,3,4};

}