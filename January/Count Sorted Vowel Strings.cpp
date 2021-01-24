class Solution {
public:
    int countVowelStrings(int n) {
        int ans = 0;
        for (int j=0; j<=n; j++) {
            int sum = 0;
            for (int i=0; i<=j; i++) {
                sum += i + 1;
                ans += sum;
            }
        }
        return ans;
    }
};
