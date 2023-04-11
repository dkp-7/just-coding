// Best time to buy & sell stock in between given range of days of stock prices to get the maximum profit
//leetcode (Question 121)

//Input: prices = [7,1,5,3,6,4]
//Output: 5


int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minimum = prices[0];

        for(int i=1; i<n; i++){

            int cost = prices[i] - minimum;
            maxProfit = max(maxProfit , cost);
            minimum = min(minimum , prices[i]);
        }
        
        return maxProfit;
}
