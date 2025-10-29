#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct Cmp { bool operator()(ListNode* a, ListNode* b) const { return a->val > b->val; } };
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
        for (auto* h : lists) if (h) pq.push(h);
        ListNode dummy, *tail = &dummy;
        while (!pq.empty()) {
            auto* n = pq.top(); pq.pop();
            tail->next = n; tail = n;
            if (n->next) pq.push(n->next);
        }
        return dummy.next;
    }
};

int main() { return 0; }

