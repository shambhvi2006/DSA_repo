#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // students → queue
        // sandwiches → stack (top = sandwiches[i])
        queue<int> q;
        int n = students.size();
        for (int i = 0; i < n; i++) q.push(students[i]);
        
        int i = 0;          // index for sandwiches
        int rotated = 0;    // how many times we've rotated without a match
        
        while (!q.empty() && rotated < q.size()) {
            if (sandwiches[i] == q.front()) {
                q.pop();
                i++;
                rotated = 0;
            } else {
                int x = q.front();
                q.pop();
                q.push(x);
                rotated++;
            }
        }
        return q.size(); // students who can’t eat
    }
};

int main() {
    Solution obj;

    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    int result = obj.countStudents(students, sandwiches);

    cout << "Number of students unable to eat: " << result << endl;

    return 0;
}
