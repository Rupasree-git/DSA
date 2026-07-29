class Solution {
public:
    const long long LIM = 1000000;

    long long combCap(int n, int r, long long cap) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        long long res = 1;

        for (int i = 1; i <= r; i++) {
            long long a = n - r + i;
            long long b = i;

            long long g = std::gcd(res, b);
            res /= g;
            b /= g;

            g = std::gcd(a, b);
            a /= g;
            b /= g;

            if (res > cap / a) return cap + 1;
            res *= a;
            res /= b;

            if (res > cap) return cap + 1;
        }

        return res;
    }

    long long countWays(vector<int> &cnt) {
        int used = 0;
        long long ans = 1;

        for (int c : cnt) {
            if (c == 0) continue;

            long long cur = combCap(used + c, c, LIM);

            if (ans > LIM / cur) return LIM + 1;
            ans *= cur;

            if (ans > LIM) return LIM + 1;

            used += c;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26);
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1) mid = char('a' + i);
        }

        if (countWays(half) < k) return "";

        int halfLen = s.size() / 2;
        string left;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (half[ch] == 0) continue;

                half[ch]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + ch));
                    break;
                } else {
                    k -= ways;
                    half[ch]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (s.size() & 1)
            return left + string(1, mid) + right;
        return left + right;
    }
};