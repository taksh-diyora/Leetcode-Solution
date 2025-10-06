class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals, res;
        for (auto p = head; p; p = p->next) vals.push_back(p->val);
        res.resize(vals.size());
        stack<int> st;
        for (int i = 0; i < vals.size(); ++i) {
            while (!st.empty() && vals[st.top()] < vals[i]) {
                res[st.top()] = vals[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
