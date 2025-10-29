#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Monotonic increasing stack of indices
        // When we see a height lower than stack top, we compute areas
        long long best = 0;
        deque<int> st;
        int n = (int)heights.size();

        for (int i = 0; i <= n; ++i) {
            int cur = (i == n ? 0 : heights[i]); // sentinel 0 at the end to flush stack
            while (!st.empty() && heights[st.back()] > cur) {
                int h = heights[st.back()];
                st.pop_back();
                int leftIdx = st.empty() ? -1 : st.back();
                long long width = i - leftIdx - 1; // span where h is the minimum
                best = max(best, 1LL * h * width);
            }
            st.push_back(i);
        }
        // Fits in 32-bit, but we used long long to avoid overflow along the way
        return (int)best;
    }
};


