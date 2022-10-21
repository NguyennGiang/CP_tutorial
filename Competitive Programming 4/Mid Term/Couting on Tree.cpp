#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Tree {
    private:
        static const int ROOT = 0;
        vector<vector<int>> &neighbors;
        vector<int> &node_vals;
        vector<vector<long long>> sum_ways;
        int target;

        void process_sums(int at, int pre){
            int val = node_vals[at];
            if(val <= target){
                sum_ways[at][val]++;
            }

            for (int n : neighbors[at]){
                if (n == pre){
                    continue;
                }

                process_sums(n, at);
                if (val > target){
                    continue;
                }

                for (int t = target; t >= 0; t--){
                    int new_val = sum_ways[at][t];
                    for (int a = 0; a <= t; a++){
                        int b = t - a;
                        new_val = (new_val + sum_ways[at][a] * sum_ways[n][b]) % MOD;
                    }
                    sum_ways[at][t] = new_val;
                }

            }
        }

    public:
        Tree(const vector<vector<int>> &neighbors, const vector<int> &node_vals, int target) :neighbors(neighbors), node_vals(node_vals), target(target), sum_ways(neighbors.size(), vector<long long>(target + 1))
}