class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int max = 0;
        if (matrix.size() == 0)
            return 0;
        vector<int> v(matrix[0].size(), 0);
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                v[j] = matrix[i][j] == '0' ? 0 : v[j] + 1;
            }
            int m = largestRectangleArea(v);
            max = std::max(max, m);
        }
        return max;
    }

    int largestRectangleArea(vector<int>& height) {
        stack<int> values;
        stack<int> indices;
        int max = 0;
        int i;
        for (i = 0; i < height.size(); i++) {
            int n = height[i];
            int ind = i;
            while ( !values.empty() && values.top() > n) {
                int width = i - indices.top();
                max = std::max(max, width * values.top());
                ind = indices.top();
                values.pop();
                indices.pop();
            }
            values.push(n);
            indices.push(ind);
        }
        while ( !values.empty()) {
            int width = i - indices.top();
            max = std::max(max, width * values.top());
            values.pop();
            indices.pop();
        }
        return max;

    }

};