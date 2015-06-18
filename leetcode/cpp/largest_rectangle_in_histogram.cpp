class Solution {
public:
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