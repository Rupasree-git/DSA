class Solution {
    public int divide(int dividend, int divisor) {

        // Overflow case
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        // Determine sign of result
        boolean negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long and take absolute values
        long dvd = Math.abs((long) dividend);
        long dvs = Math.abs((long) divisor);

        int result = 0;

        // Bit shifting division
        while (dvd >= dvs) {
            long temp = dvs;
            int multiple = 1;

            // Find the largest double of divisor
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            result += multiple;
        }

        return negative ? -result : result;
    }
}
