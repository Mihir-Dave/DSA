class Solution {
public:
    static const int MOD = 1000000007;

    struct Node {
        long long val; // concatenated non-zero digits modulo MOD
        int cnt;       // number of non-zero digits
        Node(long long v = 0, int c = 0) : val(v), cnt(c) {}
    };

    vector<int> pow10;
    vector<Node> seg;
    vector<int> prefSum;
    string str;

    Node merge(const Node &L, const Node &R) {
        return Node((L.val * pow10[R.cnt] + R.val) % MOD, L.cnt + R.cnt);
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            int d = str[l] - '0';
            if (d == 0)
                seg[idx] = Node(0, 0);
            else
                seg[idx] = Node(d, 1);
            return;
        }
        int mid = (l + r) / 2;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return seg[idx];
        int mid = (l + r) / 2;
        if (qr <= mid) return query(idx * 2, l, mid, ql, qr);
        if (ql > mid) return query(idx * 2 + 1, mid + 1, r, ql, qr);
        Node left = query(idx * 2, l, mid, ql, qr);
        Node right = query(idx * 2 + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        str = s;
        int n = s.size();

        pow10.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (long long)pow10[i - 1] * 10 % MOD;

        prefSum.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefSum[i + 1] = prefSum[i] + (s[i] - '0');

        seg.assign(4 * n + 5, Node());
        build(1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0], r = q[1];
            Node res = query(1, 0, n - 1, l, r);
            long long sum = prefSum[r + 1] - prefSum[l];
            ans.push_back((res.val * (sum % MOD)) % MOD);
        }

        return ans;
    }
};