class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>res;
        // for (int i =0; i <strs.length(); i++){
        //     string sortedS = strs[i];
        //     sort(sortedS.begin(), sortedS.end());
        //     res[sortedS].push_back(strs[i]);
        // }
        // below for auto loop doe same thing
        for(const auto& s : strs){
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            res[sortedS].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& anagrams: res){
            result.push_back(anagrams.second);
        }
        return result;

    }
};
