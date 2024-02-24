// https://leetcode.com/problems/find-all-people-with-secret/?envType=daily-question&envId=2024-02-24
// TC : O(MLogM - sorting + M*1 (ammortised for doing Union) + N*1 (for putting into answer array))
// SC : O(M(currPoeople vector) + N(DSU))


// M - number of meetings
// N - Number of people
class UnionFind {
    vector<int> root, rank;

public:
    UnionFind(int n) : root(n), rank(n) {
        rank.assign(n, 1);
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) {
        if (x == root[x])
            return x;
        else
            return root[x] = Find(root[x]);
    }

    void Union(int x, int y) {
        int rX = Find(x), rY = Find(y);
        if (rX == rY)
            return;
        if (rank[rX] > rank[rY])
            swap(rX, rY);
        root[rX] = rY;
        if (rank[rX] == rank[rY])
            rank[rY]++;
    }
    bool connected(int x, int y) { return Find(x) == Find(y); }

    void reset(int x) { // very useful for removing edges
        root[x] = x;
        rank[x] = 1;
    }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {

        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        };

      // Sort based on time
        sort(meetings.begin(), meetings.end(), compare); // O(MLogM)

        UnionFind dsu(n);
        dsu.Union(0, firstPerson);
        
        for (int i = 0; i < meetings.size();) {
            int ct = meetings[i][2];
            vector<int> currPeople;

          // Put all the DSU's with same parent in the same Graph
            while (i < meetings.size() && meetings[i][2] == ct) {
                dsu.Union(meetings[i][0], meetings[i][1]); // This is ammortised O(1)

                currPeople.push_back(meetings[i][0]);
                currPeople.push_back(meetings[i][1]);

                i++;
            }

            // Check if they match with 0 as a 
          // If not then reset them
            for (auto& people : currPeople) {
                if (dsu.Find(people) != dsu.Find(0)) {
                    dsu.reset(people);
                }
            }
        }

        vector<int> ans;


      // Check if 1 to n have parent as 0
        for (int i = 0; i < n; i++) {
            if (dsu.Find(i) == dsu.Find(0)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
