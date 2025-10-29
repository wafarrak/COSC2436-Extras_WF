#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int> freq;
        freq[0] = 1;
        long long pref = 0;
        int ans = 0;
        for (int x : nums) {
            pref += x;
            auto it = freq.find(pref - k);
            if (it != freq.end()) ans += it->second;
            freq[pref]++;
        }
        return ans;
    }
};

int main() { return 0; }

