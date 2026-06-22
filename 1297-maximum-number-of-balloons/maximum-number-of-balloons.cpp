class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>a(26,0);
        int c=0;
        for(int i=0;i<text.size();i++)
        {
            c=text[i]-97;
            a[c]++;
        }
        return min({a[0],a[1],a[11]/2,a[13],a[14]/2});
    }
};