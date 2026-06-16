class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int c=0,a=0;
        vector<int> num1(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                c++;
                continue;
            }
            else{
                num1[a]=nums[i];
                a++;
            }
        }
        nums=num1;
        return nums.size()-c;
    }
};