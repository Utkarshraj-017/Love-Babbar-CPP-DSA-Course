/*
For Condition : 
if (S >= 7 && (N - M) * 6< M) return -1;

Explanation:
S >= 7 → Means the number of days is at least a week, so at least one Sunday is included (a day when you can’t buy food).

On a weekly basis, you can buy food for only 6 days.

In each buying day, the extra food you can save = N - M (because you eat M, and can buy N max).

So in 6 buying days, total surplus food = (N - M) * 6.

Now:
You need food for the 7th day (Sunday).
If the surplus food you store in the week < M, then you cannot survive the Sunday.
*/

class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        // code here
        if (M > N) {
            return -1;
        }
        
        if (S>=7 && (N-M)*6 < M) {
            return -1;
        }
        
        int buyingDays = S - S/7;
        
        int totalFood = S*M;
        
        int ans = 0;
        
        if (totalFood % N == 0) {
            ans = totalFood / N;
        }
        else {
            ans = (totalFood / N) + 1;
        }
        
        if (ans <= buyingDays) {
            return ans;
        } 
        else {
            return -1;
        }
    }
};