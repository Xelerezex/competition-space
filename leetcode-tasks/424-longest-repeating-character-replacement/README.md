[424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/description/)

You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

_Return the length of the longest substring containing the same letter you can get after performing the above operations._

__Example 1:__

    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.

__Example 2:__

    Input: s = "AABABBA", k = 1
    Output: 4
    Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
    The substring "BBBB" has the longest repeating letters, which is 4.
    There may exists other ways to achieve this answer too.

__Constraints:__

-    $1 \leq$ `s.length` $\leq 10^5$
-    `s` consists of only uppercase English letters.
-    $0 \leq$ `k` $\leq$ `s.length`
