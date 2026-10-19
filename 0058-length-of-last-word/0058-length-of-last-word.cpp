class Solution {
public:
    int lengthOfLastWord(string s){
        int count = 0;
        int found = 0;
        for (int i = s.size() - 1; i>= 0; i--){
            if (s[i] != ' ') {
                found = 1;
            }
            if (s[i] == ' ' && found == 1) {
                break;
            }
            if (s[i] != ' ') {
                count ++;
            }
        }
        return count;
    }
};