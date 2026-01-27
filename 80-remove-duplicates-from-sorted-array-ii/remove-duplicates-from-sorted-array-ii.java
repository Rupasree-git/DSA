class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        if (n <= 2) return n;

        int k = 2; // write index

        for (int i = 2; i < n; i++) {
            // Allow nums[i] only if it is not the same as nums[k-2]
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
}
