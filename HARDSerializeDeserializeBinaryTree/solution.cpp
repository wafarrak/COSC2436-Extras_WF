#include <bits/stdc++.h>
using namespace std;

class Codec {
    void ser(TreeNode* node, string& out) {
        if (!node) { out += "#,"; return; }
        out += to_string(node->val) + ",";
        ser(node->left, out);
        ser(node->right, out);
    }
    TreeNode* build(vector<string>& t, int& i) {
        if (i >= (int)t.size() || t[i] == "#") { i++; return nullptr; }
        TreeNode* n = new TreeNode(stoi(t[i++]));
        n->left = build(t, i);
        n->right = build(t, i);
        return n;
    }
public:
    string serialize(TreeNode* root) {
        string out; ser(root, out); return out;
    }
    TreeNode* deserialize(string data) {
        vector<string> tokens; tokens.reserve(data.size()/2+1);
        string cur; for (char c: data) {
            if (c == ',') { if (!cur.empty()) tokens.push_back(cur); else tokens.push_back("#"); cur.clear(); }
            else cur.push_back(c);
        }
        if (!cur.empty()) tokens.push_back(cur);
        int i = 0; return build(tokens, i);
    }
};

