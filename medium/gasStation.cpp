#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int start_ind = -1;
        int needed_gas = 0;
        int cur_gas = 0;
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            if (cost[i] > cur_gas + gas[i]) {
                needed_gas += cost[i] - gas[i] - cur_gas;
                cur_gas = 0;
                start_ind = -1;
            } else {
                if (start_ind == -1) start_ind = i;
                cur_gas = cur_gas + gas[i] - cost[i];
            }   
        } 
        return cur_gas >= needed_gas ? start_ind : -1;
    }
};