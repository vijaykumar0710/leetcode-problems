
class Solution {
public:
    int minimumTime(std::vector<int>& taskTimesA, std::vector<int>& taskTimesB, int maxTime) {
        int tasksCount = taskTimesA.size(); // Number of tasks
        // Pair each task's time from B with the corresponding time from A
        std::vector<std::pair<int, int>> taskPairs;
        for (int i = 0; i < tasksCount; ++i) {
            taskPairs.emplace_back(taskTimesB[i], taskTimesA[i]);
        }
      
        // Sort the pair array based on times from B task times (ascending)
        std::sort(taskPairs.begin(), taskPairs.end());
      
        // Initialize the dynamic programming array; 
        // f[i] will hold the maximum time saved after completing i tasks
        std::vector<int> dp(tasksCount + 1, 0);
      
        // Calculate the maximum time saved for each number of tasks
        for (auto& [timeB, timeA] : taskPairs) {
            for (int j = tasksCount; j > 0; --j) {
                dp[j] = std::max(dp[j], dp[j - 1] + timeA + timeB * j);
            }
        }
      
        // Calculate the sum of the times for both A and B tasks
        int totalTimeA = accumulate(taskTimesA.begin(), taskTimesA.end(), 0);
        int totalTimeB = accumulate(taskTimesB.begin(), taskTimesB.end(), 0);
      
        // Find the minimum number of tasks needed such that the time limit is not exceeded
        for (int j = 0; j <= tasksCount; ++j) {
            if (totalTimeA + totalTimeB * j - dp[j] <= maxTime) {
                return j; // Minimum number of tasks
            }
        }
      
        // If no solution is found return -1
        return -1;
    }
};