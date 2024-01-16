/* We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:

- We can buy and sell the stock any number of times.
- In order to sell the stock, we need to first buy it on the same or any previous day.
- We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
- After every transaction, there is a transaction fee (‘fee’) associated with it. */

#include <bits/stdc++.h>
using namespace std;

// TC = n*2, SC = n*2 + n
long spaceOptimised(vector<int> &Arr, int n, int fee)
{
    long aheadNotBuy = 0, aheadBuy = 0, curNotBuy, curBuy;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        // If you sell, you'll have a profit of +Arr[ind]
        long SellStock = +Arr[ind] + aheadBuy;
        long dontSellStock = 0 + aheadNotBuy;
        curNotBuy = max(SellStock, dontSellStock);

        // If you buy, you'll have a profit of -Arr[ind]
        long buyStock = -Arr[ind] + aheadNotBuy - fee;
        long dontBuyStock = 0 + aheadBuy;
        curBuy = max(buyStock, dontBuyStock);

        aheadNotBuy = curNotBuy;
        aheadBuy = curBuy;
    }
    return aheadBuy;
}

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int n = prices.size();
    int fee = 2;
    cout << spaceOptimised(prices, n, fee) << endl;
    return 0;
}
