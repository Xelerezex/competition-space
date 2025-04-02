[121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)

You are given an array `prices` where `prices[i]` is the price of a given stock on the $i^{th}$ day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a __different day__ in the future to sell that stock.

_Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit,_ `return 0`.

__Example 1:__

    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

__Example 2:__

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.

__Constraints:__

    - $1 \leq$ `prices.length` $\leq 10^5$
    - $0 \leq$ `prices[i]` $\leq 10^4$

