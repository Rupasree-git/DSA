class Solution {
public:
    int count(int n){
        int len=0;
        while(n>0){
            n=n/10;
            len++;
        }
        return len;
    }
    vector<int> conv(vector<int> & nums,int n){
        int l=count(n);
        for(int i=0;i<l;i++){
            nums[i]=n%10;
            n=n/10;
        }
        return nums;
    }
    int maxProduct(int n) {
        vector<int> nums(count(n));
        nums=conv(nums,n);

        sort(nums.begin(),nums.end());
        if(count(n)>1)
        return nums[count(n)-1]*nums[count(n)-2];
        else return n;

    }
};