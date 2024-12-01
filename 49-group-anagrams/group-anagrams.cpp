class Solution {
public:
    inline uint hash(vector<int> &V){ 
        uint ans = 0; 
        for(auto x : V){ 
            ans *= 131; 
            ans += x; 
        }
        return ans; 
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> hist(26, 0); 
        vector<pair<uint, int> > V;  
        int ind = 0; 
        for(string str : strs){ 
            fill(hist.begin(), hist.end(), 0); 
            for(char c: str) 
                hist[c-'a']++;
            V.push_back({hash(hist), ind++}); 
        }
        sort(V.begin(), V.end());  
        vector<vector<string> >ans; 
        ans.push_back({strs[V[0].second]});  
        for(int i = 1; i < V.size(); i++){ 
            if(V[i].first == V[i-1].first)
                ans.back().push_back(strs[V[i].second]); 
            else 
                ans.push_back({strs[V[i].second]}); 
        }
        return ans; 
    }
};