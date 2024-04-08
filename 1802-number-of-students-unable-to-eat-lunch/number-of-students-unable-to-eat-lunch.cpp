class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // when no process can be made?
        // if the top sandwich does not exist in students array
        int ans = students.size();

        vector<int> counter(2, 0);

        for(int& x: students)
            counter[x]++;
        

        stack<int> sand_stack;

        for(int i = sandwiches.size() - 1; i>=0; i--)
            sand_stack.push(sandwiches[i]);
        
        
        while(!sand_stack.empty()) {
            int top_sandwich = sand_stack.top(); sand_stack.pop();
            if(counter[top_sandwich] == 0) break;
            counter[top_sandwich]--;
            ans--;
        }
        return ans;
        
    }
};