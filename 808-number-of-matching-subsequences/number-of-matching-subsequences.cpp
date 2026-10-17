class Solution {
    struct Node {
        Node* ch[26]{};
        int cnt = 0;
    };

public:
    int numMatchingSubseq(string s, vector<string>& words) {
        Node* rt = new Node();

        for (auto& w : words) {
            Node* p = rt;
            for (char c : w) {
                int x = c - 'a';
                if (!p->ch[x]) p->ch[x] = new Node();
                p = p->ch[x];
            }
            p->cnt++;
        }

        vector<vector<int>> pos(26);
        for (int i = 0; i < (int)s.size(); i++)
            pos[s[i] - 'a'].push_back(i);

        function<int(Node*, int)> dfs = [&](Node* p, int idx) -> int {
            int ans = p->cnt;
            for (int c = 0; c < 26; c++) {
                if (!p->ch[c]) continue;
                auto& v = pos[c];
                auto it = upper_bound(v.begin(), v.end(), idx);
                if (it != v.end())
                    ans += dfs(p->ch[c], *it);
            }
            return ans;
        };

        int ans = 0;
        for (int c = 0; c < 26; c++) {
            if (!rt->ch[c]) continue;
            auto& v = pos[c];
            auto it = lower_bound(v.begin(), v.end(), 0);
            if (it != v.end())
                ans += dfs(rt->ch[c], *it);
        }

        return ans;
    }
};