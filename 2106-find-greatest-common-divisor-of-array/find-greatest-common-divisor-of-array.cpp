class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[0];
        int b=nums[nums.size()-1];
        int hcf=0;
        int m=0;
        if(a>b){
            m=a;
        }
        else
        {
            m=b;
        }
        for(int i=1;i<=m;i++){
            if(a%i==0 && b%i==0)
            {
                hcf=i;
            }
        }
        return hcf;
    }
};