class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l=nums.size()-1;
        if(l<1)
        return -1;
        sort(nums.begin(),nums.end());
        int p=(nums[l]-1)*(nums[l-1]-1);
        //int q=nums[0]-1*nums[1]-1;

        return p;
    }
};