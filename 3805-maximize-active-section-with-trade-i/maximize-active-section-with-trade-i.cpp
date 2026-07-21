class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        string t = "1" + s + "1";

        vector<pair<char, int>> runs;
        for (char c : t) {
            if (runs.empty() || runs.back().first != c)
                runs.push_back({c, 1});
            else
                runs.back().second++;
        }

        int gain = 0;

        // Check every interior block of 1's surrounded by 0's.
        for (int i = 2; i + 2 < (int)runs.size(); i += 2) {
            gain = max(gain, runs[i - 1].second + runs[i + 1].second);
        }

        return ones + gain;
    }
};