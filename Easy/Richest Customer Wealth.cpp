/*
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.
  */

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for(size_t i = 0;i< accounts.size(); ++i){
            int currentWealth =0;
            for(size_t j = 0; j < accounts[i].size();++j){
                currentWealth += accounts[i][j];
            }
            maxWealth = max(maxWealth, currentWealth);
        }
        return maxWealth;
        
        
    
    }
};
