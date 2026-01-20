import java.util.Arrays;

class Solution {
    public int[] twoSum(int[] nums, int target) {

        // Step 1: Store value and index
        int[][] arr = new int[nums.length][2];
        for (int i = 0; i < nums.length; i++) {
            arr[i][0] = nums[i]; // value
            arr[i][1] = i;       // original index
        }

        // Step 2: Sort by value
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);

        // Step 3: Two pointers
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int sum = arr[left][0] + arr[right][0];

            if (sum == target) {
                return new int[] { arr[left][1], arr[right][1] };
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return new int[] {};
    }
}