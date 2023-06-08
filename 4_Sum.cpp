class Solution {
public:
  // Use 2 for loops for first 2 and then 2 Sum + Sort.
    vector<pair<int,int>> twoSum(vector<int>& v, long long target,int l) {
        
        int n = v.size();
        vector<pair<int,int>> p;
        int i =l, r = n-1;
        while(l < r){
            if(v[l] + v[r] == target){
                p.push_back({l,r});
                
                int L = v[l],R = v[r];
                
                while(l < r && v[l] == L){   
                        l++;
                }
                while(l < r && v[r] == R){
                        r--;
                }
                //l++;r--;
            
            }
            else if(v[l] + v[r] < target)l++;
            else r--;
        }
        return p; 
            
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        // int curr = -1e9 - 1;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i =0;i<n;i++){
            if(i > 0 && nums[i] == nums[i - 1])continue; // Remember this to avoid duplicates.
            for(int j= i + 1;j < n;j ++) {
                if(j != (i + 1) && nums[j] == nums[j - 1])continue; // Avoid duplicates.
                long long sum = nums[i] + nums[j];

                long long tar = target - sum;
                auto p = twoSum(nums,tar,j + 1);

                for(auto &k : p){
                    ans.push_back({nums[i],nums[j],nums[k.first],nums[k.second]});
                }
            }
        }
        return ans;
        

    }
};
