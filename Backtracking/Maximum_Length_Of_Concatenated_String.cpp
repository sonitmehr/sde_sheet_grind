//https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/submissions/1154257858/?envType=daily-question&envId=2024-01-23

// There are 2 approaches 

// GOOD Approach - Bit Manipulation 

class Solution {
public:
    void convertToBits(unordered_set<int>& uniqueBits, vector<string>& arr) {

        // This function will convert each string to its corresponding version
        // in bits form
        for (auto& i : arr) {
            int stringToBit = 0;
            bool flag = true;
            for (auto& c : i) {
                int charToBit = (1 << (c - 'a'));
                // If the string itself has a repeating character then dont take
                // it in unordered_set
                if (stringToBit & charToBit) {
                    flag = false;
                    continue;
                }
                // If no repeating character create its bit mapping
                stringToBit |= charToBit;
            }
            // If we reach here then means that the string is good
            // Store the length of this string after the 26 characters.
            if (flag) {

                int stringToBitLen = i.size() << 26;
                stringToBit |= stringToBitLen;
                uniqueBits.insert(stringToBit);
            }
        }
    }

    int solve(vector<int>& uniqueVec, int i, int result) {
        // oldResult stores the first 26 characters from result
        int oldResult = result & ((1 << 26) - 1);
        int oldResultLen = result >> 26;
        int best = oldResultLen;
        if (i >= uniqueVec.size())
            return best;

        // newResult stores the first 26 characters of the new element.
        int newResult = uniqueVec[i] & ((1 << 26) - 1);
        int newResultLen = uniqueVec[i] >> 26;

        // Check if any repetition after merging
        int mergedResult = (oldResult & newResult);

        if (mergedResult == 0) { // Means there is no repetition.
            int newValue = oldResult | newResult;
            int newValueLength = oldResultLen + newResultLen;

            int newValueWithLength = newValue | (newValueLength << 26);

            best = solve(uniqueVec, i + 1, newValueWithLength);
        }
        best = max(best, solve(uniqueVec, i + 1, result));
        return best;
    }

    int maxLength(vector<string>& arr) {
        unordered_set<int> uniqueBits;
        convertToBits(uniqueBits, arr);
        vector<int> uniqueVec(uniqueBits.begin(), uniqueBits.end());

        // result = 0 initially as our string is empty. with length = 0
        return solve(uniqueVec, 0, 0);
    }
};


// More space and time - DFS

class Solution {
public:

    int f(int i,vector<string>&a,string &unique){
        if(i >= a.size())return 0;

        string s = a[i];
        bool flag = true;
        
        for(int j = 0;j<s.size();j++){
            if(unique.find(s[j]) != std::string::npos)flag = false;
            unique += s[j];
        }
        int one = 0;
        if(flag){
            one = s.size() +  f(i + 1,a,unique);
        }
        for(int j = 0;j<s.size();j++){
            unique.pop_back();
        }
       return max(one,f(i + 1,a,unique));
    }


    int maxLength(vector<string>& arr) {
        string s = "";
        return f(0,arr,s);
    }
};


