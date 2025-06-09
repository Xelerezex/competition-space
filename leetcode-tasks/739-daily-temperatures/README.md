[739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/description/)

Given an array of integers `temperatures` represents the daily temperatures, return an array `answer` such that `answer[i]` is the number of days you have to wait after the $i^{th}$ day to get a warmer temperature. If there is no future day for which this is possible, keep `answer[i] == 0` instead.

__Example 1:__

    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]

__Example 2:__

    Input: temperatures = [30,40,50,60]
    Output: [1,1,1,0]

__Example 3:__

    Input: temperatures = [30,60,90]
    Output: [1,1,0]

__Constraints:__

- $1 \leq$ `temperatures.length` $\leq 10^5$
- $30 \leq$ `temperatures[i]` $\leq 100$
