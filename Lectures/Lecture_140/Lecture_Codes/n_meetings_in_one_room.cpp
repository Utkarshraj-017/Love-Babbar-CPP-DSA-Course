class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        // Create a vector of pairs to hold start and end times
        vector<pair<int, int>> meetings;
        
        for (int i = 0; i < start.size(); i++) {
            meetings.push_back({end[i], start[i]});
        }
        
        // Sort meetings based on their end times
        sort(meetings.begin(), meetings.end());
        
        int count = 1;
        int lastEndTime = meetings[0].first;
        
        // Iterate over the meetings
        for (int i=1; i<meetings.size(); i++) {
            if (meetings[i].second > lastEndTime) {
                // If the current meeting starts after the last meeting ends
                count++;
                lastEndTime = meetings[i].first;
            }
        }
        
        return count;       
    }
};