#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // will store indices
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Remove elements outside the current window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove all elements smaller than current element nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Add the maximum (front of deque) to the result after first k-1 elements
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }
        return result;
    }
};

// Optional: for local testing (not needed on LeetCode)
int main() {
    Solution s;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = s.maxSlidingWindow(nums, k);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}

