class Solution {
public:
    int minAddToMakeValid(string s) {
        int minAdd = 0;
        int valid = 0;

        for (char c : s){
            if (c == '(') {
                valid ++;
            } else {
                if (valid == 0) {
                    minAdd++;
                }else{
                    valid--;
                }
            }
        }
        return minAdd + valid;
    }
};