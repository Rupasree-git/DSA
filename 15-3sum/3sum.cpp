class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector<int>> a;
        vector <int>b;
        int target=0;
        int n=nums.size();
        int ans=0,start,end;
        int temp=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(nums[j]>nums[j+1]){
                    temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                }
            }
        }
        for(int i=0;i<n-2;i++){
            ans=target-nums[i];
            start=i+1;
            end=n-1;
            if(i>0 && nums[i]==nums[i-1])
            continue;
            while(start<end)
            {
                if(nums[start]+nums[end]==ans){
                    b.push_back(nums[i]);
                    b.push_back(nums[start]);
                    b.push_back(nums[end]);
                    a.push_back(b);
                    b.clear();
                    while(start < end && nums[start] == nums[start+1])
                    start++;

                    while(start < end && nums[end] == nums[end-1])
                     end--;

                    start++;
                    end--;
                }
                else if(nums[start]+nums[end]>ans){
                    end=end-1;
                }
                else
                {
                    start=start+1;
                }
            }
        }
        if(a.size()>0)
        return a;
        else
        return a;

            
        
    }
};