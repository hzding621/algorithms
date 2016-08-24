#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// void combinationSumRec(vector<vector<int>>& result, vector<int>& subset, vector<int>& candidates, int startFrom, int target) {
// 	if (target == 0) {
// 	    sort(subset.begin(), subset.end());
// 		result.push_back(subset);
// 		return;
// 	}
// 	if (startFrom == candidates.size())
// 		return;
// 	if (target < 0)
// 		return;
// 	combinationSumRec(result, subset, candidates, startFrom+1, target);
// 	vector<int> altSubset(subset);
// 	altSubset.push_back(candidates[startFrom]);
// 	combinationSumRec(result, altSubset, candidates, startFrom, target-candidates[startFrom]);
// }

// vector<vector<int>> combinationSum(vector<int> candidates, int target) {
// 	vector<vector<int>> result;
// 	vector<int> v;
// 	combinationSumRec(result, v, candidates, 0, target);
// 	return result;
// }

// vector<vector<int>> combinationSumNaive(vector<int> candidates, int target) {
// 	vector<vector<int>> result;
// 	int n = candidates.size();
// 	int p = pow(2, n);
// 	for (int i=0; i<p; i++) {
// 		int k = i;
// 		int sum = 0, m = 0;
// 		vector<int> v;
// 		while (k > 0) {
// 			if (k&1) {
// 				sum += candidates[m];
// 				v.push_back(candidates[m]);
// 			}
// 			k >>= 1;
// 			m++;
// 			if (m < n && sum > target)
// 				break;
// 		}
// 		if (sum == target) {
// 			result.push_back(v);
// 		}
// 	}
// 	return result;
// }

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	sort(candidates.begin(), candidates.end());
    	vector<vector<int>> resultBuilder;
    	vector<int> combinationBuilder;
    	combinationSumSearch(candidates, target, 0, combinationBuilder, resultBuilder);
    	return resultBuilder;
    }
private:
	void combinationSumSearch(const vector<int>& candidates, const int target, const int candidatesStartIndex,
							  vector<int>& combinationBuilder, vector<vector<int>>& resultBuilder) {
		if (target == 0) {
			resultBuilder.push_back(combinationBuilder);
			return;
		}
		for (int i = candidatesStartIndex; i < candidates.size() && target >= candidates[i]; i++) {
			combinationBuilder.push_back(candidates[i]);
			combinationSumSearch(candidates, target - candidates[i], i, combinationBuilder, resultBuilder);
			combinationBuilder.pop_back();
		}
	}
};

int main() {
	vector<int> v = {1,2,3,4,5};
	int n = 5;
	Solution sol;
	auto vv = sol.combinationSum(v, n);
	for (auto vi: vv) {
		for (auto i: vi)
			cout << i << " ";
		cout << endl;
	}

}