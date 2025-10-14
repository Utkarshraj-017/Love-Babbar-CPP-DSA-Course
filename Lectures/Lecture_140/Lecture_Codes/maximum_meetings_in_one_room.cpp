class Solution {
  public:
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        // Create a vector of triplets: {finish_time, start_time, meeting_number}
        vector<pair<pair<int, int>, int>> meetings;
        
        for (int i = 0; i < N; i++) {
            // Store finish time, start time, and 1-based meeting number
            meetings.push_back({{F[i], S[i]}, i + 1});
        }
        
        // Sort meetings based on finish times
        // If finish times are equal, sort by start time (earlier start preferred)
        sort(meetings.begin(), meetings.end());
        
        vector<int> ans;
        
        // Select the first meeting (always optimal to start with earliest finishing)
        ans.push_back(meetings[0].second);  // Push original meeting number
        int lastEndTime = meetings[0].first.first;  // Get finish time
        
        // Iterate over remaining meetings
        for (int i = 1; i < meetings.size(); i++) {
            int currentStartTime = meetings[i].first.second;
            int currentEndTime = meetings[i].first.first;
            int meetingNumber = meetings[i].second;
            
            // Check if current meeting can be scheduled
            if (currentStartTime > lastEndTime) {
                ans.push_back(meetingNumber);
                lastEndTime = currentEndTime;
            }
        }
        
        // Sort the result to return meeting numbers in ascending order
        sort(ans.begin(), ans.end());
        return ans;
    }
};