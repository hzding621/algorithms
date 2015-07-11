#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    double find_median(const vector<int>& v) {
        int n = v.size()-1;
        if ( n % 2 ) {
            // even length
            return (v[n/2] + v[n/2+1]) / 2.0;
        } else {
            return v[n/2];
        }
    }

    double handle_single(const vector<int>& v, int s, int e, int x) {
        int m = (s + e) / 2;
        if ( (s+e) % 2 ) {
            int x1 = v[m], x2 = v[m+1];
            vector<int> vx = {x1, x2, x};
            sort(vx.begin(), vx.end());
            return find_median(vx);
        } else {
            if (s == e)
                return (v[s] + x) / 2.0;
            int x1 = v[m-1], x2 = v[m], x3 = v[m+1];
            vector<int> vx = {x1, x2, x3, x};
            sort(vx.begin(), vx.end());
            return find_median(vx);
        }
    }

    int get(int index, const vector<int>& v, int xi, int i, int xj, int j) {
        if (index < i)
            return v[index];
        else if (index == i)
            return xi;
        else if (index < j+1)
            return v[index-1];
        else if (index == j+1)
            return xj;
        else
            return v[index-2];
    }

    double handle_two(const vector<int>& v, int s, int e, int y1, int y2) {

        int index1 = lower_bound(v.begin()+s, v.begin()+e+1, y1) - v.begin();
        int index2 = lower_bound(v.begin()+s, v.begin()+e+1, y2) - v.begin();
        int m1 = (s + e) / 2 + 1;
        if ( (e+s) % 2) {
            int a = get(m1, v, y1, index1, y2, index2);
            int b = get(m1+1, v, y1, index1, y2, index2);
            return (a+b)  / 2.0;
        } else {
            return get(m1, v, y1, index1, y2, index2);
        }
    }

    double helper(const vector<int>& v1, const vector<int>& v2, int s1, int e1, int s2, int e2 ) {

        bool even1 = (s1 + e1) % 2;
        bool even2 = (s2 + e2) % 2;
        if (s1 == e1) {
            return handle_single(v2, s2, e2, v1[s1]);
        } else if (s2 == e2) {
            return handle_single(v1, s1, e1, v2[s2]);
        }
        else if (s1 + 1 == e1) {
            return handle_two(v2, s2, e2, v1[s1], v1[e1]);
        } else if (s2 + 1 == e2) {
            return handle_two(v1, s1, e1, v2[s2], v2[e2]);
        }

        int m1 = (s1 + e1) / 2;
        int m2 = (s2 + e2) / 2;
        int doub_me1 = even1 ? (v1[m1] + v1[m1+1]) : (v1[m1] * 2);
        int doub_me2 = even2 ? (v2[m2] + v2[m2+1]) : (v2[m2] * 2);
        if (doub_me1 == doub_me2)
            return doub_me1 / 2.0;
        int min_len = min((e1-s1)/2, (e2-s2)/2);
        if (doub_me1 > doub_me2) {
            e1 = e1 - min_len;
            s2 = s2 + min_len;
        } else {
            s1 = s1 + min_len;
            e2 = e2 - min_len;
        }
        return helper(v1, v2, s1, e1, s2, e2);

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m == 0 && n == 0)
            return 0;
        else if (m == 0)
            return find_median(nums2);
        else if (n == 0)
            return find_median(nums1);
        else
            return helper(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1);
    }
};

int main() {



    Solution sol;

    vector<int> v1 = {1,2,6};
    vector<int> v2 = {3,4,5,8};

    cout << sol.findMedianSortedArrays(v1, v2) << " Solution: ";

    vector<int> v3 = v1;
    v3.insert(v3.end(), v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    cout << sol.find_median(v3) << endl;
}
