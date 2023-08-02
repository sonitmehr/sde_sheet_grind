class Solution {
public:
    // Swap with indexes forward. This ensures that distinct will only be formed.
    void f(int ind,vector<int>& v,vector<vector<int>> & ds){
        if(ind == v.size()){
            ds.push_back(v);
            return;
        }

        for(int i = ind;i<v.size();i++){
            swap(v[i],v[ind]);
            f(ind + 1,v,ds); // Here ind + 1 comes not i + 1.
            swap(v[i],v[ind]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        f(0,nums,ans);
        return ans;
    }
};
