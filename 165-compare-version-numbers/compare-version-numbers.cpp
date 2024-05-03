class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = split(version1,'.');
        auto v2 = split(version2,'.');
        int x = 0, y =0;
        while(x < v1.size() && y < v2.size()) {
            int a = stoi(v1[x]);
            int b = stoi(v2[y]);
            if( a== b) {
                x++;
                y++;
            }else if(a > b) {
                return 1;
            }else {
                return -1;
            }
        }
        while(x < v1.size()){
            int a = stoi(v1[x]);
            if(a != 0) return 1;
            x++;
        }
        while(y < v2.size()){
            int a = stoi(v2[y]);
            if(a != 0) return -1;
            y++;
        }
        return 0;
    }
    vector<string> split(string &s, char d) {
        stringstream ss(s);
        vector<string> res;
        string temp;
        while(getline(ss,temp, '.')) {
            res.push_back(temp);
        }
        return move(res);
    }
};