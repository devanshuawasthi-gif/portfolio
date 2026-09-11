class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        int even = 0, z = 0;
        unordered_map <int, int> mpp;
        for (auto i : digits) mpp[i] += 1;
        unordered_map <int, int> temp(mpp.begin(), mpp.end());
        int count = 0;
        for (int i = 100;i<1000;i += 2) {
            int val = i;
            bool flag = true;
            while (val != 0) {
                int rem = val % 10;
                if (mpp.count(rem)) {
                    mpp[rem] -= 1;
                    if (mpp[rem] == 0) mpp.erase(rem);
                } else {
                    flag = false;
                    break;
                }
                val /= 10;
            }
            mpp = temp;
            if (flag) count += 1;
        }
        return count;
    }
};