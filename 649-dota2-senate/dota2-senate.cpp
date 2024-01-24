class Solution {
public:
    string predictPartyVictory(string senate) {
        vector<bool> killed(senate.size(), false);
        int rk = 0, dk = 0;
        bool visitedR,visitedD;
        do{
            visitedR = visitedD = false;
            for(int i =0; i<senate.size(); i++){ // first round
                char a = senate[i];
                if(a == 'R' && !killed[i]) {
                    visitedR = true;
                    if(rk > 0) {
                        killed[i] = true;
                        rk--;
                    }else {
                        dk++;
                    }
                }else if(a == 'D' && !killed[i]) {
                    visitedD = true;
                    if(dk > 0) {
                        killed[i] = true;
                        dk--;
                    }else {
                        rk++;
                    }
                }
            }
        }while(visitedR && visitedD);
        if(visitedR) return "Radiant";
        else return "Dire";
    }
};