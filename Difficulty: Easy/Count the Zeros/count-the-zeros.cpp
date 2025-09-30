// User function template for C++

class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        // code here
        int start=0,end=arr.size()-1,mid,first=-1,last=-1,target=0;
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]==target){
                first=mid;
                end=mid-1;
            }
            else if(arr[mid]>target){
                start=mid+1;
            }
            else{
                end=mid-1;
                
            }
        }
        start=0,end=arr.size()-1;
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]==target){
                last=mid;
                start=mid+1;
            }
            else if(arr[mid]>target){
                start=mid+1;
            }
            else{
                end=mid-1;
                
            }
        }
        
        return (last-first+1);
        
    }
};