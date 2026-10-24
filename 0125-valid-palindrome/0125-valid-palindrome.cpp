class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (char ch : s) {
            if(isalnum(ch)) {
                str+= tolower(ch);
            }
        }
        string cstr = str;
        cout<<cstr;
        int l=0, r=cstr.size() - 1;
        while(l < r) {
            if (cstr[l++] != cstr[r--]) return 0;
        }
        return 1;
    }
};