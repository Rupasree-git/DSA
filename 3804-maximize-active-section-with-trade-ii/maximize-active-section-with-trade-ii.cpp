class Solution {
public:
    struct SegmentTree {
        int n;
        vector<int> tree;

        SegmentTree() {}

        SegmentTree(const vector<int>& arr) {
            n = arr.size();
            if (n == 0) return;
            tree.assign(4 * n, 0);
            build(0, 0, n - 1, arr);
        }

        void build(int idx, int l, int r, const vector<int>& arr) {
            if (l == r) {
                tree[idx] = arr[l];
                return;
            }
            int mid = (l + r) / 2;
            build(idx * 2 + 1, l, mid, arr);
            build(idx * 2 + 2, mid + 1, r, arr);
            tree[idx] = max(tree[idx * 2 + 1], tree[idx * 2 + 2]);
        }

        int query(int idx, int l, int r, int ql, int qr) {
            if (l > qr || r < ql) return INT_MIN;
            if (ql <= l && r <= qr) return tree[idx];
            int mid = (l + r) / 2;
            return max(query(idx * 2 + 1, l, mid, ql, qr),
                       query(idx * 2 + 2, mid + 1, r, ql, qr));
        }

        int rmq(int l, int r) {
            if (n == 0 || l > r) return 0;
            return query(0, 0, n - 1, l, r);
        }
    };

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();

        int activeCount = 0;
        for (char c : s)
            if (c == '1') activeCount++;

        vector<int> blockStart, blockEnd;

        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int st = i;
                while (i < n && s[i] == '0') i++;
                blockStart.push_back(st);
                blockEnd.push_back(i - 1);
            } else {
                i++;
            }
        }

        int m = blockStart.size();

        if (m < 2) {
            return vector<int>(queries.size(), activeCount);
        }

        vector<int> blockSize(m);
        for (int i = 0; i < m; i++)
            blockSize[i] = blockEnd[i] - blockStart[i] + 1;

        vector<int> pairSum;
        for (int i = 0; i + 1 < m; i++)
            pairSum.push_back(blockSize[i] + blockSize[i + 1]);

        SegmentTree st(pairSum);

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int low = lower_bound(blockEnd.begin(), blockEnd.end(), l) - blockEnd.begin();
            int high = upper_bound(blockStart.begin(), blockStart.end(), r) - blockStart.begin() - 1;

            int best = 0;

            if (low < high) {
                int firstLen = blockEnd[low] - max(blockStart[low], l) + 1;
                int lastLen = min(blockEnd[high], r) - blockStart[high] + 1;

                if (high - low == 1) {
                    best = firstLen + lastLen;
                } else {
                    int pair1 = firstLen + blockSize[low + 1];
                    int pair2 = blockSize[high - 1] + lastLen;
                    int pair3 = (low + 1 <= high - 2) ? st.rmq(low + 1, high - 2) : 0;
                    best = max({pair1, pair2, pair3});
                }
            }

            ans.push_back(activeCount + best);
        }

        return ans;
    }
};