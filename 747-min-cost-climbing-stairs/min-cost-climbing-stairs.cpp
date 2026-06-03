class Solution {
public:
    int ways(int n,vector <int>& cost,vector <int>& dp){
        if(n<=1)
        return 0;
        else 
        if(dp[n]!=-1)
        return dp[n];
        else
        {
            return dp[n]=min(cost[n-1]+ways(n-1,cost,dp),cost[n-2]+ways(n-2,cost,dp));
        }
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return ways(n,cost,dp);
    }
};