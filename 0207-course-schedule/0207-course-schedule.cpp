class Solution {
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inor(numCourses, 0);
        vector<vector<int>> adjl(numCourses);
        int n = prerequisites.size();

        for(int i = 0; i < n; i++){
            adjl[prerequisites[i][0]].push_back(prerequisites[i][1]);
            inor[prerequisites[i][1]]++;
        }

        queue<int> trav;
        int count = 0;
        for(int i = 0; i < numCourses; i++){
            if(inor[i] == 0){
                trav.push(i);
                count++;
            }
        }

        while(!trav.empty()){
            int front = trav.front();
            trav.pop();

            for(int i = 0; i < adjl[front].size(); i++){
                inor[adjl[front][i]]--;
                if(inor[adjl[front][i]] == 0){
                    trav.push(adjl[front][i]);
                    count++;
                }
            }
        }
        return (count == numCourses);
    }
};