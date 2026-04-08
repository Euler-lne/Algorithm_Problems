# Evil Straw Warts Live


A palindrome is a string of symbols that is equal to itself when reversed. Given an input string, not necessarily a palindrome, compute the number of swaps necessary to transform the string into a palindrome. By swap we mean reversing the order of two adjacent symbols. For example, the string "mamad" may be transformed into the palindrome "madam" with 3 swaps:
swap "ad" to yield "mamda"
swap "md" to yield "madma"
swap "ma" to yield "madam"
## Input

The first line of input gives n, the number of test cases. For each test case, one line of input follows, containing a string of up to 8000 lowercase letters.
## Output

Output consists of one line per test case. This line will contain the number of swaps, or "Impossible" if it is not possible to transform the input to a palindrome.
## Sample Input
```
3
mamad
asflkj
aabb
```
## Sample Output
```
3
Impossible
2
```



## 邪恶稻草人活生生（Evil Straw Warts Live）

**回文**是指正着读和反着读都相同的字符串。给定一个输入字符串（不一定是回文），计算将其转换为回文所需的最少**相邻交换**次数。相邻交换即交换两个相邻的字符。

例如，字符串 `"mamad"` 可以通过 3 次交换变为回文 `"madam"`：
1. 交换 `"ad"` → `"mamda"`
2. 交换 `"md"` → `"madma"`
3. 交换 `"ma"` → `"madam"`

### 输入
- 第一行一个整数 \(n\)，表示测试用例的数量。
- 接下来 \(n\) 行，每行一个字符串（仅包含小写字母，长度不超过 8000）。

### 输出
- 对于每个测试用例，输出一行：最少交换次数，如果无法通过相邻交换将其变为回文，则输出 `"Impossible"`。

### 样例输入
```
3
mamad
asflkj
aabb
```

### 样例输出
```
3
Impossible
2
```