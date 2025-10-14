#include <vector>
#include <algorithm>
#include <utility>  // for pair

using namespace std;

class Solution {
  public:
    // Union-Find data structure for efficient slot finding
    // parent[i] points to the next available slot <= i
    vector<int> parent;
    
    // Find the next available slot <= x using path compression
    int findNextSlot(int x) {
        if (parent[x] == x) {
            return x;  // Slot x is available
        }
        // Path compression: directly point to the root
        return parent[x] = findNextSlot(parent[x]);
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        
        // Step 1: Create jobs with profit and deadline, add index for tracking
        vector<pair<int, pair<int, int>>> jobs;  // {profit, {deadline, index}}
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], {deadline[i], i}});
        }
        
        // Step 2: Sort jobs by profit in descending order (greedy approach)
        sort(jobs.rbegin(), jobs.rend());
        
        // Step 3: Initialize Union-Find structure
        // parent[i] = i means slot i is available
        // parent[i] = j (j < i) means slot i is occupied, next available is j
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        
        int jobsCompleted = 0;
        int totalProfit = 0;
        
        // Step 4: Process jobs in decreasing order of profit
        for (int i = 0; i < n; i++) {
            int currentProfit = jobs[i].first;
            int currentDeadline = jobs[i].second.first;
            
            // Find the latest available slot <= deadline
            int availableSlot = findNextSlot(min(currentDeadline, n));
            
            // If we found an available slot (> 0)
            if (availableSlot > 0) {
                jobsCompleted++;
                totalProfit += currentProfit;
                
                // Mark this slot as occupied by pointing it to the previous slot
                parent[availableSlot] = availableSlot - 1;
            }
        }
        
        return {jobsCompleted, totalProfit};
    }
};