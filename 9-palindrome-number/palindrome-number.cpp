class Solution {
    public: bool isPalindrome(int x) {
        int r=0,k=x,s=0;
        while(x>0){
            r=x%10;
            if(s >= INT_MIN/10 && s <= INT_MAX/10){
            s=s*10+r;
            }
            else
            return false;
            x=x/10;
        }
        if(s==k)
        return true;
        else
        return false;
    }
};