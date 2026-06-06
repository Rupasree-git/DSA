class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> a;int start=0,end=0;long long sum=0,ans=0,ans1=0;
        sort(nums.begin(),nums.end());
        if(nums.size()>=4){
        for(int i=0;i<nums.size()-3;i++){
            ans1=target-nums[i];
            if(i>0 && nums[i]==nums[i-1])
            continue;
            for(int j=i+1;j<nums.size()-2;j++){
                start=j+1;
                end=nums.size()-1;
                ans=ans1-nums[j];
                if(j>i+1 &&nums[j]==nums[j-1])
                continue;
                while(start<end){
                    sum=nums[start]+nums[end];
                    if(sum==ans)
                    {
                        a.push_back({nums[i],nums[j],nums[start],nums[end]});
                        while(start<end && nums[start]==nums[start+1]) start++;
                        while(start<end && nums[end]==nums[end-1]) end--;
                        start++;
                        end--;
                    }
                    else if(sum>ans){
                        end--;
                    }
                    else
                    start++;
                }
            }
        }
        }
        return a;
    }
};