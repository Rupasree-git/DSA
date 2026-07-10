class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> ord;
        ord.reserve(n);
        for (int i = 0; i < n; i++)
            ord.push_back({nums[i], i});

        sort(ord.begin(), ord.end());

        vector<int> val(n), pos(n);
        for (int i = 0; i < n; i++) {
            val[i] = ord[i].first;
            pos[ord[i].second] = i;
        }

        // Connected components in sorted order
        vector<int> comp(n);
        int cid = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (val[i] - val[i - 1] > maxDiff)
                cid++;
            comp[i] = cid;
        }

        // Farthest reachable to the right
        vector<int> rightNext(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            while (r + 1 < n && val[r + 1] <= val[i] + maxDiff)
                r++;
            rightNext[i] = r;
        }

        // Farthest reachable to the left
        vector<int> leftNext(n);
        int l = 0;
        for (int i = 0; i < n; i++) {
            while (val[i] - val[l] > maxDiff)
                l++;
            leftNext[i] = l;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> upR(LOG, vector<int>(n));
        vector<vector<int>> upL(LOG, vector<int>(n));

        upR[0] = rightNext;
        upL[0] = leftNext;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                upR[k][i] = upR[k - 1][upR[k - 1][i]];
                upL[k][i] = upL[k - 1][upL[k - 1][i]];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int u = q[0], v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            if (nums[u] == nums[v]) {
                ans.push_back(1);
                continue;
            }

            int pu = pos[u], pv = pos[v];

            if (comp[pu] != comp[pv]) {
                ans.push_back(-1);
                continue;
            }

            if (pu < pv) {
                int cur = pu;
                int steps = 0;

                for (int k = LOG - 1; k >= 0; k--) {
                    int nxt = upR[k][cur];
                    if (nxt < pv) {
                        cur = nxt;
                        steps += (1 << k);
                    }
                }

                ans.push_back(steps + 1);
            } else {
                int cur = pu;
                int steps = 0;

                for (int k = LOG - 1; k >= 0; k--) {
                    int nxt = upL[k][cur];
                    if (nxt > pv) {
                        cur = nxt;
                        steps += (1 << k);
                    }
                }

                ans.push_back(steps + 1);
            }
        }

        return ans;
    }
};