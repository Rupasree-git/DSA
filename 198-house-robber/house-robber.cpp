class Solution {
public:
    int robb(int l,vector<int>&nums,vector<int>&dp){
        
        if(l==0)
        return nums[0];
        else if(l==1)
        return max(nums[0],nums[1]);
        else
        if(dp[l]!=-1){
            return dp[l];
        }
        else
        return dp[l]=max(nums[l]+robb(l-2,nums,dp),robb(l-1,nums,dp));
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return robb(nums.size()-1,nums,dp);
    }
};