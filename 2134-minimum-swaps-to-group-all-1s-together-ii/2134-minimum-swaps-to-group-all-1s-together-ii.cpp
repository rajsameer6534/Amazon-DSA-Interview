class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int n = nums.size();

        // Count total 1s
        int totalones = 0;
        for (int x : nums) {
            if (x == 1)
                totalones++;
        }

        if (totalones == 0 || totalones == n)
            return 0;

        int ones = 0;
        int maxOnes = 0;
        int left = 0;

        for (int right = 0; right < n + totalones - 1; right++) {

            // Circular indexing
            if (nums[right % n] == 1)
                ones++;

            // Keep window size <= totalones
            if (right - left + 1 > totalones) {
                if (nums[left % n] == 1)
                    ones--;

                left++;
            }

            // Window has exactly totalones elements
            if (right - left + 1 == totalones) {
                maxOnes = max(maxOnes, ones);
            }
        }

        return totalones - maxOnes;
    }
};