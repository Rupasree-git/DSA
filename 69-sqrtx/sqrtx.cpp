class Solution {
public:
    int mySqrt(int x) {
        if(x<2){
            return x;
        }
        else{
            int start=1,end=x,mid,index;
            while(start<=end){
                mid=start+(end-start)/2;
                if(mid==x/mid){
                    return mid;
                }
                else if(mid<x/mid){
                    index=mid;
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
         return index;   
        }
       
    }
};