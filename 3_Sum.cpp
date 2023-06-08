class Solution {
public:
  // Use 2 Sum + Sorting to do 3 Sum 
    vector<pair<int,int>> twoSum(vector<int> &v,int target,int l){
        int n = v.size();
        int i = l,j = n - 1;
        vector<pair<int,int>> p;
        while(i < j){
            int sum = v[i] + v[j];
            if(sum == target){
                p.push_back({i,j});
                int L = v[i],R = v[j];
                while(i < j && v[i] == L)i++;
                while(i < j && v[j] == R)j--;
            }
            else if(sum < target)i++;
            else j--;
        }
        return p;

    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int curr = -1e6;
         int n = nums.size();
        vector<vector<int>> ans;
        for(int i= 0;i<n;i++){
            if(curr == nums[i])continue;
            curr = nums[i];

            auto p = twoSum(nums,-curr,i+1);

            for(int j = 0;j<p.size();j++){
                auto pp = p[j];
                ans.push_back({curr,nums[pp.first],nums[pp.second]});
            }

            
        }
        return ans;





    }
};
