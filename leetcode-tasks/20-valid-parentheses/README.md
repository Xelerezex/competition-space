[20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

__Example 1:__

    Input: s = "()"
    Output: true

__Example 2:__

    Input: s = "()[]{}"
    Output: true

__Example 3:__

    Input: s = "(]"
    Output: false

__Example 4:__

    Input: s = "([])"
    Output: true

__Constraints:__

- $1 \leq $ `s.length` $ \leq 10^4$
- `s` consists of parentheses only `'()[]{}'`.
