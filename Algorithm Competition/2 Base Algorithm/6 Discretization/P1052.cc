#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
using namespace std;

const int INF = 1e9;

int main()
{
    int bridgeLen, minJump, maxJump, stoneNum;
    scanf("%d%d%d%d", &bridgeLen, &minJump, &maxJump, &stoneNum);

    // 特殊情况：步长固定
    if (minJump == maxJump) {
        int ans = 0;
        for (int i = 0; i < stoneNum; ++i) {
            int pos;
            scanf("%d", &pos);
            if (pos % minJump == 0)
                ans++;
        }
        printf("%d\n", ans);
        return 0;
    }

    // 读入石子位置并排序
    int stones[105]; // 最多 100 个石子，加一点冗余
    for (int i = 1; i <= stoneNum; ++i)
        scanf("%d", &stones[i]);
    sort(stones + 1, stones + stoneNum + 1);
    stones[0] = 0; // 把起点当作第 0 个“石子”位置（无石子）

    // ---------- 路径压缩 ----------
    // 压缩后的距离数组（相邻两点间的距离）
    int gap[105];                   // gap[i] 表示第 i-1 个石子到第 i 个石子的压缩距离（i=1..stoneNum）
    int totalLen = 0;               // 压缩后的总长度
    bool hasStone[20005] = {false}; // 标记压缩后的桥上是否有石子（数组开大些）

    // 压缩每个石子之间的间隔
    for (int i = 1; i <= stoneNum; ++i) {
        int originalDist = stones[i] - stones[i - 1]; // 原始距离
        // 如果距离超过 90，就压缩到 90（安全值）
        int compressed = (originalDist > 90) ? 90 : originalDist;
        gap[i] = compressed;
        totalLen += compressed;
        hasStone[totalLen] = true; // 在这个压缩后的位置上放一颗石子
    }

    // 最后一段：最后一个石子到终点 L 的距离
    int lastDist = bridgeLen - stones[stoneNum];
    int lastCompressed = (lastDist > 100) ? 100 : lastDist;
    totalLen += lastCompressed; // 压缩后的终点位置

    // ---------- 动态规划 ----------
    int dp[20005] = {0}; // dp[i] 表示到达压缩后位置 i 的最少踩石子数
    // 初始化一个很大的数
    for (int i = 1; i <= totalLen + 10; ++i)
        dp[i] = INF;

    for (int i = 1; i <= totalLen + 10; ++i) {
        // 枚举最后一步的跳跃距离
        for (int step = minJump; step <= maxJump; ++step) {
            if (i >= step) {
                // 从 i-step 跳 step 步到达 i，加上当前位置是否有石子
                dp[i] = min(dp[i], dp[i - step] + (hasStone[i] ? 1 : 0));
            }
        }
    }

    // 答案：从压缩后的终点 totalLen 到 totalLen+9 中取最小值
    // 因为青蛙可能跳过终点，最多再跳 maxJump 步（≤10），所以 +9 足够
    int ans = INF;
    for (int i = totalLen; i <= totalLen + 9; ++i) {
        ans = min(ans, dp[i]);
    }
    printf("%d\n", ans);

    return 0;
}