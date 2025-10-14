class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        
        vector<pair<int, int>> activities;
        
        for (int i = 0; i < n; i++) {
            activities.push_back({finish[i], start[i]});
        }
        
        sort(activities.begin(), activities.end());
        
        if (n == 0) return 0;
        
        int count = 1;
        int lastEndTime = activities[0].first;
        
        
        for (int i = 0; i < n; i++) {
            int currentStartTime = activities[i].second;
            int currentEndTime = activities[i].first;
            
            if (currentStartTime > lastEndTime) {
                count++;
                lastEndTime = currentEndTime;
            }
        }
        
        return count;
    }
};