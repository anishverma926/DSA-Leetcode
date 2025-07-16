class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int evenCount = 0;
        int oddCount = 0;

        // Count number of even and odd numbers
        for (int num : nums) {
            if (num % 2 == 0) {
                evenCount++;  // Even number
            } else {
                oddCount++;   // Odd number
            }
        }

        // Calculate longest alternating parity subsequence
        int parity = nums[0] % 2; // Start with first number's parity
        int len = 1; // At least one number in alternating subsequence

        for (int i = 1; i < n; i++) {
            // If current number has different parity than previous
            if (nums[i] % 2 != parity) {
                len++; // Increase alternating length
                parity = nums[i] % 2; // Update parity
            }
            // Else, skip (same parity as previous)
        }

        // Return the maximum among all three
        return max({len, evenCount, oddCount});
    }
};
