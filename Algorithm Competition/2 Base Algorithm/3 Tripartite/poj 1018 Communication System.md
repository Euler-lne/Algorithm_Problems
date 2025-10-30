# Description

We have received an order from Pizoor Communications Inc. for a special communication system. The system consists of several devices. For each device, we are free to choose from several manufacturers. Same devices from two manufacturers differ in their maximum bandwidths and prices.

By overall bandwidth (B) we mean the minimum of the bandwidths of the chosen devices in the communication system and the total price (P) is the sum of the prices of all chosen devices. Our goal is to choose a manufacturer for each device to maximize B/P.

我们收到了 Pizoor Communications 公司的订单，需要一个特殊的通信系统。该系统由多个设备组成。对于每个设备，我们可以自由选择多个制造商。两个制造商生产的相同设备在最大带宽和价格方面存在差异。

总带宽 (B) 是指通信系统中所选设备的最小带宽，总价格 (P) 是所有选定设备价格的总和。我们的目标是为每个设备选择一个制造商，以最大化 B/P。
# Input

The first line of the input file contains a single integer t (1 ≤ t ≤ 10), the number of test cases, followed by the input data for each test case. Each test case starts with a line containing a single integer n (1 ≤ n ≤ 100), the number of devices in the communication system, followed by n lines in the following format: the i-th line (1 ≤ i ≤ n) starts with mi (1 ≤ mi ≤ 100), the number of manufacturers for the i-th device, followed by mi pairs of positive integers in the same line, each indicating the bandwidth and the price of the device respectively, corresponding to a manufacturer.

输入文件的第一行包含一个整数 t (1 ≤ t ≤ 10), 即测试用例的数量，后跟每个测试用例的输入数据。每个测试用例以包含一个整数 n (1 ≤ n ≤ 100) 的行开始，即通信系统中的设备数量，后跟 n 行，格式如下：第 i 行 (1 ≤ i ≤ n) 以 mi (1 ≤ mi ≤ 100) 开始，即第 i 个设备的制造商数量，后跟同一行中的 mi 对正整数，每个表示设备的带宽和价格，对应于一个制造商。

# Output

Your program should produce a single line for each test case containing a single number which is the maximum possible B/P for the test case. Round the numbers in the output to 3 digits after decimal point.

程序应为每个测试用例生成一行，其中包含一个数字，即测试用例的最大可能 B/P。将输出中的数字在小数点后舍入到 3 位。
# Sample Input
```
1 3
3 100 25 150 35 80 25
2 120 80 155 40
2 100 100 120 110
```
# Sample Output
```
0.649
```