class Solution {
    public int removeDuplicates(int[] nums) {
        int n = nums.length;
        if (n <= 2) return n;

        int k = 2; // index to place next valid element

        for (int i = 2; i < n; i++) {
            // Allow current number only if it is different
            // from the element two positions before
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
}
