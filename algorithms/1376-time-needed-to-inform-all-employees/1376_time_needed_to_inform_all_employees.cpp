#include <unordered_map>

// #1376: Time Needed to Inform All Employees
//
// Rowan Tran
//
// A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the
// company has is the one with headID.
// Each employee has one direct manager given in the manager array where manager[i] is the direct
// manager of the i-th employee, manager[headID] = -1. Also it's guaranteed that the subordination
// relationships have a tree structure.
// The head of the company wants to inform all the employees of the company of an urgent piece of
// news. He will inform his direct subordinates and they will inform their subordinates and so on
// until all employees know about the urgent news.
// The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e
// After informTime[i] minutes, all his direct subordinates can start spreading the news).
// Return the number of minutes needed to inform all the employees about the urgent news.

class Solution {
private:
    map<int, vector<int>> subordinates;

public:
    // Populates a map holding all of the employees who are managed by each employee, so that
    // subordinates[i] is a vector with all of the employees directly under employee i.
    void searchSubordinates(int n, vector<int>& manager) {
        for (int i = 0; i < n; ++i) {
            if (manager[i] >= 0) {
                subordinates[manager[i]].push_back(i);
            }
        }
    }

    // Recursively finds the time taken to inform all of the employees managed by
    // employee with the ID i.
    int totalTime(int i, vector<int>& manager, vector<int>& informTime) {
        if (subordinates[i].size() == 0) return 0;

        int maxSubordinateTime = 0;
        int currentSubordinateTime;
        for (int j = 0; j < subordinates[i].size(); ++j) {
            currentSubordinateTime = totalTime(subordinates[i][j], manager, informTime);
            if (currentSubordinateTime > maxSubordinateTime) {
                maxSubordinateTime = currentSubordinateTime;
            }
        }

        return maxSubordinateTime + informTime[i];
    }

    // Calls the searchSubordinates() method to populate the subordinates array,
    // then simply returns totalTime(headID) to find the time required to inform
    // all employees.
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        searchSubordinates(n, manager);
        return totalTime(headID, manager, informTime);
    }
};
