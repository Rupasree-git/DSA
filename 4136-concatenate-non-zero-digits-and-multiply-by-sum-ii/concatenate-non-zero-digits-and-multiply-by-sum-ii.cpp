class Solution {
public:
    static const int MOD = 1000000007;

    struct Node {
        long long val;   // concatenated non-zero number
        long long sum;   // sum of non-zero digits
        int cnt;         // count of non-zero digits

        Node(long long v = 0, long long s = 0, int c = 0) {
            val = v;
            sum = s;
            cnt = c;
        }
    };

    vector<Node> seg;
    vector<long long> pow10;

    Node merge(Node left, Node right) {
        Node res;
        res.cnt = left.cnt + right.cnt;
        res.sum = (left.sum + right.sum) % MOD;
        res.val = (left.val * pow10[right.cnt] + right.val) % MOD;
        return res;
    }

    void build(int idx, int l, int r, string &s) {
        if (l == r) {
            int d = s[l] - '0';
            if (d == 0)
                seg[idx] = Node(0, 0, 0);
            else
                seg[idx] = Node(d, d, 1);
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid, s);
        build(2 * idx + 1, mid + 1, r, s);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(2 * idx, l, mid, ql, qr);

        if (ql > mid)
            return query(2 * idx + 1, mid + 1, r, ql, qr);

        Node left = query(2 * idx, l, mid, ql, qr);
        Node right = query(2 * idx + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        pow10.assign(n + 1, 1);

        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        seg.assign(4 * n + 5, Node());

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (auto &q : queries) {
            Node cur = query(1, 0, n - 1, q[0], q[1]);
            ans.push_back((cur.val * cur.sum) % MOD);
        }

        return ans;
    }
};