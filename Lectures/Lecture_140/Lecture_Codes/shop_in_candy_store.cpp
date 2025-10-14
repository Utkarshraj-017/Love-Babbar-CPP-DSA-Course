class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n = prices.size();
        
        sort(prices.begin(), prices.end());
        
        int buy = 0;
        int free = n-1;
        
        int minAmount = 0;
        
        while (buy <= free) {
            minAmount += prices[buy];
            buy++;
            free -= k;
        }
        
        int maxAmount = 0;
        
        buy = n-1;
        free = 0;
        
        while (free <= buy) {
            maxAmount += prices[buy];
            buy--;
            free += k;
        }
        
        return {minAmount, maxAmount};
        
    }
};