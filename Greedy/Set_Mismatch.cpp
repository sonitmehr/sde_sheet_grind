//https://leetcode.com/problems/set-mismatch/?envType=daily-question&envId=2024-01-22


vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = -1;
        int missing = -1;

  // Make the value at that index negative
  // If it is already negative then that is the duplicate.
        for (int i = 0; i < n; i++) {
            int _abs = abs(nums[i]);
            if (nums[_abs - 1] < 0) {
                dup = _abs;
            } else {
                nums[_abs - 1] = -nums[_abs - 1];
            }
        }

  // Only one value should be left as positive which will be the missing value
        for(int i= 0;i<n;i++){
            if(nums[i] > 0){
                missing = i+1;
            }
        }


        return {dup, missing};
    }
