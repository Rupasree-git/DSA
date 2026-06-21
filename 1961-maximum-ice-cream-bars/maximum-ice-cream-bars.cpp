class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int>freq(100001,0);
        int ans=0,c=0;
        for(int i :costs)
        {
            freq[i]++;
        }
        for(int i=1;i<=100000;i++)
        {
            c=min(freq[i],coins/i);
            ans+=c;
            coins-=(c*i);
        }
        return ans;

    }
};