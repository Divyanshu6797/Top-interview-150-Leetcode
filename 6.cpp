class Solution {
public:
    int helper(int index ,vector<int>& prices, int buy,int noOfTransactions) {
        if(index >= prices.size() || noOfTransactions==0) return 0;

        if(buy==1) {
            int take = helper(index+1, prices,0,noOfTransactions) - prices[index];
            int notTake =  helper(index+1, prices, 1,noOfTransactions);
            return max(take, notTake);

        }
        else {
            
           
            int take = helper(index+1,prices,1,noOfTransactions-1) + prices[index];
            int notTake = helper(index+1, prices, 0,noOfTransactions);
            return max(take,notTake);
            

        }
    }
    int maxProfit(vector<int>& prices) {
        
        return helper(0,prices,1,2);
        

        
    }
};
