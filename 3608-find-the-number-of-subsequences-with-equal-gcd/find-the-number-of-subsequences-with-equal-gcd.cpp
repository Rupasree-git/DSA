class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        const int MAXG = 200;

        vector<vector<int>> dp(MAXG + 1, vector<int>(MAXG + 1, 0));
        vector<vector<int>> ndp(MAXG + 1, vector<int>(MAXG + 1, 0));

        dp[0][0] = 1;

        for (int x : nums) {
            for (int i = 0; i <= MAXG; i++)
                fill(ndp[i].begin(), ndp[i].end(), 0);

            for (int g1 = 0; g1 <= MAXG; g1++) {
                for (int g2 = 0; g2 <= MAXG; g2++) {
                    int cur = dp[g1][g2];
                    if (!cur) continue;

                    // Skip x
                    ndp[g1][g2] = (ndp[g1][g2] + cur) % MOD;

                    // Put into seq1
                    int ng1 = (g1 == 0) ? x : std::gcd(g1, x);
                    ndp[ng1][g2] = (ndp[ng1][g2] + cur) % MOD;

                    // Put into seq2
                    int ng2 = (g2 == 0) ? x : std::gcd(g2, x);
                    ndp[g1][ng2] = (ndp[g1][ng2] + cur) % MOD;
                }
            }

            dp.swap(ndp);
        }

        long long ans = 0;
        for (int g = 1; g <= MAXG; g++) {
            ans += dp[g][g];
            ans %= MOD;
        }

        return (int)ans;
    }
};