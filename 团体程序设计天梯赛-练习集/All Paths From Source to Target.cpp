// 80ms, 64.64%; 13.2MB, 70.00%
class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(const vector<vector<int>> &graph)
    {
        vector<vector<int>> res;     // results
        int dest = graph.size() - 1; // destination

        vector<int> trace; // trace the procedure of dfs
        stack<vector<int>> st;
        st.emplace(1, 0);
        while (!st.empty()) {
            int choice = st.top().back(); // next step
            trace.push_back(choice);
            if (choice != dest && !graph[choice].empty()) { // still on the way
                st.push(graph[choice]);
            } else {                                      // dead end or destination
                if (choice == dest) res.push_back(trace); // arrive at destination
                while (!st.empty() && st.top().size() == 1) st.pop(), trace.pop_back();
                if (!st.empty()) st.top().pop_back(), trace.pop_back();
            }
        }
        return res;
    }
};
