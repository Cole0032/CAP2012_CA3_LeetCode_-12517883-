#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // Stores indices in monotonically increasing height order
        int maxArea = 0;

        // Iterate up to n inclusive; i == n acts as a virtual sentinel bar of height 0
        for (int i = 0; i <= n; ++i) {
            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                // If stack is empty, bar h extends all the way to index 0
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};
