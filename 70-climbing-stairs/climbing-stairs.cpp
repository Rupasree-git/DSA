class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);int i=0;
        return count(i,n,dp);
    }
    int count(int i,int n,vector<int>&dp)
    {
        if(i==n)
        return 1;
        else if (i>n)
        return 0;
        else
        {
            if(dp[i]!=-1)
                return dp[i];
            else
                return dp[i]=count(i+1,n,dp)+count(i+2,n,dp);
        }

    }
};