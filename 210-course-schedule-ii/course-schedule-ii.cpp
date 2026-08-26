class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inorder(numCourses, 0);

        for(auto i : prerequisites)
        {
            inorder[i[0]]++;          
        }

        queue<int> pq;
        for(int i=0;i<numCourses;i++)
        {
            if(inorder[i] == 0)
                pq.push(i);
        }

        vector<int> ans;
        while(!pq.empty())
        {
            int top = pq.front();
            pq.pop();
            ans.push_back(top);

            for(auto i : prerequisites)
            {
                if(i[1] == top)
                {
                    inorder[i[0]]--;
                    if(inorder[i[0]] == 0)     
                    {
                        pq.push(i[0]);
                    }
                }
            }
        }

        return (ans.size() == numCourses) ? ans : vector<int>{};
    }
};