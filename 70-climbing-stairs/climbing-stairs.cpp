class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return count(n,dp);

        
    }
    int count(int n,vector<int>&dp){
            if(n<0)
            {
                return 0;
            }
            else if(n==0)
            {
                return 1;
            }
            else
            {
                if(dp[n]==-1)
                    return dp[n]=count(n-1,dp)+count(n-2,dp);
                else
                    return dp[n];
            }
    }
};