class Solution:
    def reverseArray(self, arr):
        # code here
        a=[]
        for i in range (len(arr)-1,-1,-1):
            a.append(arr[i])
        for i in range(0,len(a)):
            arr[i]=a[i]
        return arr
            
        
        