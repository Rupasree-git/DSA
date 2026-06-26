class Solution {
public:
    class Fenwick {
    public:
        vector<int> bit;
        int n;

        Fenwick(int sz) {
            n = sz;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int SHIFT = n + 1;
        Fenwick bit(2 * n + 5);

        long long ans = 0;
        int pref = 0;

        // Empty prefix
        bit.update(SHIFT + 1, 1);

        for (int x : nums) {
            pref += (x == target ? 1 : -1);

            int idx = pref + SHIFT + 1;

            // Count previous prefix sums smaller than current
            ans += bit.query(idx - 1);

            bit.update(idx, 1);
        }

        return ans;
    }
};