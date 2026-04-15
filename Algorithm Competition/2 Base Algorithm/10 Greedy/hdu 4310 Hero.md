## 题目复述（英文原文）

**Hero**  
*Time Limit*: 6000/3000 MS (Java/Others)  
*Memory Limit*: 65536/65536 K (Java/Others)  

**Problem Description**  
When playing DotA with god-like rivals and pig-like team members, you have to face an embarrassing situation: All your teammates are killed, and you have to fight 1vN.

There are two key attributes for the heroes in the game, health point (HP) and damage per shot (DPS). Your hero has almost infinite HP, but only 1 DPS.

To simplify the problem, we assume the game is turn-based, but not real-time. In each round, you can choose one enemy hero to attack, and his HP will decrease by 1. While at the same time, all the lived enemy heroes will attack you, and your HP will decrease by the sum of their DPS. If one hero's HP fall equal to (or below) zero, he will die after this round, and cannot attack you in the following rounds.

Although your hero is undefeated, you want to choose best strategy to kill all the enemy heroes with minimum HP loss.

**Input**  
The first line of each test case contains the number of enemy heroes N (1 <= N <= 20). Then N lines followed, each contains two integers DPSi and HPi, which are the DPS and HP for each hero. (1 <= DPSi, HPi <= 1000)

**Output**  
Output one line for each test, indicates the minimum HP loss.

**Sample Input**  
```
1
10 2
2
100 1
1 100
```

**Sample Output**  
```
20
201
```

---

## 中文翻译

**题目：英雄**  

**问题描述**  
当你在 DotA 游戏中遇到如神一般的对手和如猪一般的队友时，你会面临一个尴尬的局面：所有队友都被击杀了，而你不得不进行 1vN 的战斗。

游戏中的英雄有两个关键属性：生命值（HP）和每次攻击造成的伤害（DPS）。你的英雄拥有近乎无限的生命值，但 DPS 仅为 1。

为简化问题，我们假设游戏是回合制的（而非实时）。在每一回合中，你可以选择一名敌方英雄进行攻击，使其 HP 减少 1。与此同时，所有存活的敌方英雄都会攻击你，你的 HP 会减少他们 DPS 的总和。如果某英雄的 HP 降至 0 或以下，他会在本回合结束后死亡，并且在后续回合中不再攻击你。

尽管你的英雄是不败的，但你希望选择最佳策略，以最小的生命值损失杀死所有敌方英雄。

**输入**  
每个测试用例的第一行包含敌方英雄的数量 N（1 ≤ N ≤ 20）。接下来 N 行，每行包含两个整数 DPSi 和 HPi，分别表示该英雄的 DPS 和 HP（1 ≤ DPSi, HPi ≤ 1000）。

**输出**  
对于每个测试用例，输出一行，表示最小损失的生命值。

**样例输入**  
```
1
10 2
2
100 1
1 100
```

**样例输出**  
```
20
201
```