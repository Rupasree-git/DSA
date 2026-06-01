class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0,e=arr.size()-1,mid=0;
        while(s<=e)
        {
            mid=e+(s-e)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                return mid;
            }
            else if(arr[mid]>arr[mid-1])
            {
                s=mid+1;
            }
            else
            e=mid-1;
        }
        return -1;
    }
};