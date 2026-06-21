class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int>freq(100001,0);
        for(int cost :costs)
        {
            freq[cost]++;
        }
        int ans=0,m=0;
        for(int i=1;i<=100000;i++){
            m=min(freq[i],coins/i);
            ans+=m;
            coins-=i*m;
        }
        return ans;
    }
};