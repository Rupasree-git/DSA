class Solution {
public:
    static const long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();

        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long aik = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;
        int sz = 2 * m;

        vector<long long> init(sz, 0);

        for (int v = 0; v < m; v++) {
            init[v] = v;
            init[m + v] = m - 1 - v;
        }

        if (n == 2) {
            long long ans = 0;
            for (auto x : init)
                ans = (ans + x) % MOD;
            return (int)ans;
        }

        Matrix T(sz, vector<long long>(sz, 0));

        for (int v = 0; v < m; v++) {

            for (int x = 0; x < v; x++)
                T[v][m + x] = 1;

            for (int x = v + 1; x < m; x++)
                T[m + v][x] = 1;
        }

        Matrix P = power(T, n - 2);

        vector<long long> finalState(sz, 0);

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                finalState[i] =
                    (finalState[i] +
                     P[i][j] * init[j]) % MOD;
            }
        }

        long long ans = 0;

        for (auto x : finalState)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};