class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int start=0,end=arr.size()-1,mid,first=-1;
        while(start<=end){
            mid=start+(end-start)/2;
            if(arr[mid]==k){
                first=mid;
                end=mid-1;
                
            }
            else if (arr[mid]<k){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return first;
    }
};