class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> cnt;
        for (int x : nums) cnt[x]++;

        int ans = 1;

        if (cnt.count(1)) {
            ans = max(ans, cnt[1] % 2 ? cnt[1] : cnt[1] - 1);
        }

        for (auto &[x, f] : cnt) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (cnt[cur] >= 2) {
                if (cur > 31622) break;          // cur*cur > 1e9
                long long nxt = cur * cur;
                if (!cnt.count(nxt)) break;      // current must become the peak

                len += 2;
                cur = nxt;
            }

            if (cnt[cur])
                ans = max(ans, len + 1);
        }

        return ans;
    }
};