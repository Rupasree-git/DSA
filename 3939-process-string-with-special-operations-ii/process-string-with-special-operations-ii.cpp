class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        // Forward pass: compute final length only
        for(char c : s) {
            if(c >= 'a' && c <= 'z') {
                len++;
            }
            else if(c == '*') {
                if(len > 0) len--;
            }
            else if(c == '#') {
                len *= 2;
            }
            // '%' does not change length
        }

        if(k >= len) return '.';

        // Backward pass
        for(int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if(c >= 'a' && c <= 'z') {
                if(k == len - 1)
                    return c;
                len--;
            }
            else if(c == '#') {
                long long oldLen = len / 2;

                if(k >= oldLen)
                    k -= oldLen;

                len = oldLen;
            }
            else if(c == '%') {
                k = len - 1 - k;
            }
            else if(c == '*') {
                len++;
            }
        }

        return '.';
    }
};