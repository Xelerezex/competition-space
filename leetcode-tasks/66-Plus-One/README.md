## 66. Plus One

Given a **non-empty** array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

#### Example 1:

 ```cpp
 Input: digits = [1,2,3]
 Output: [1,2,4]
 Explanation: The array represents the integer 123.
 Incrementing by one gives 123 + 1 = 124.
 Thus, the result should be [1,2,4].
 ```

#### Example 2:

 ```cpp
 Input: digits = [4,3,2,1]
 Output: [4,3,2,2]
 Explanation: The array represents the integer 4321.
 Incrementing by one gives 4321 + 1 = 4322. 
 Thus, the result should be [4,3,2,2].
 ```

#### Example 3:

 ```cpp
 Input: digits = [0]
 Output: [1]
 Incrementing by one gives 9 + 1 = 10.
 Explanation: The array represents the integer 9.
 Thus, the result should be [1,0].
 ```

#### Constraints:

- $1 <= digits.length <= 100$
- $0 <= digits[i] <= 9$
