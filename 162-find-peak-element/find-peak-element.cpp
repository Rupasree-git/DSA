class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0,end=nums.size()-1,mid;
        if(nums.size()==1)
        return 0;
        while(start<=end){
            mid=(end+(start-end)/2);
            if(mid>0 && mid<nums.size()-1){
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            return mid;
            else if(nums[mid]>nums[mid-1])
            start=mid+1;
            else
            end=mid-1;
            }
            else if(mid==0 && nums[0]>nums[1])
            return mid;
            else if(mid==nums.size()-1 && nums[nums.size()-1]>nums[nums.size()-2])
            return mid;
            else if(mid==0)
            start=mid+1;
            else if(mid==nums.size()-1)
            end=mid-1;
        }
        return -1;
    }
};