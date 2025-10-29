#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<long long> s;
        s.reserve(nums.size() * 2 + 1);
        for (int x : nums) s.insert(x);
        int best = 0;
        for (int x : nums) {
            if (!s.count((long long)x - 1)) {
                int len = 1;
                long long cur = x;
                while (s.count(cur + 1)) { cur++; len++; }
                if (len > best) best = len;
            }
        }
        return best;
    }
};

int main() { return 0; }

