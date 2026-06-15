class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int fi=index(nums,target);
        int li=index1(nums,target);
        vector<int>a(2,-1);
        a={fi,li};
        return a;
    }
    int index(vector<int>nums,int target)
    {
        int start=0,end=0,mid=0,index=-1;
        int len=nums.size();
        end=len-1;        
        while(start<=end)
        {
            mid=end+(start-end)/2;
            if(nums[mid]==target)
            {               
                index=mid;
                end=mid-1;               
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }            
        }  
         
        return index;
    }
    int index1(vector<int>nums,int target)
    {
        int start=0,end=0,mid=0,index=-1;
        int len=nums.size();
        end=len-1;        
        while(start<=end)
        {
            mid=end+(start-end)/2;
            if(nums[mid]==target)
            {               
                index=mid;
                start=mid+1;               
            }
            else if(nums[mid]>target)
            {
                end=mid-1;
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }            
        }  
         
        return index;
    }
};