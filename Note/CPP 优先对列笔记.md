## 优先队列默认使用 `std::less`

```cpp
// 默认的优先队列声明
priority_queue<Item> pq;
// 等价于
priority_queue<Item, vector<Item>, less<Item>> pq;
```

`std::less<Item>` 内部是通过调用 `operator<` 来判断的。

## 理解机制

当优先队列需要比较两个元素 `A` 和 `B` 时：

1. **优先队列是最大堆**：默认希望"大"的元素在队首
2. 它调用 `A < B`：
   - 如果 `A < B` 返回 `true`：说明 A 比 B 小，A 的优先级低于 B
   - 如果 `A < B` 返回 `false`：说明 A 不小于 B，A 的优先级不低于 B

## 具体到你的例子

```cpp
bool operator<(const Item &a) const {
    return val > a.val;  // 当前对象的val > 参数a的val
}
```

当比较 `item1 < item2` 时：
- 如果 `item1.val > item2.val`，返回 `true`
- 优先队列看到返回 `true`，认为：`item1 < item2` 成立
- 所以 `item1` 的优先级低于 `item2`

**结果**：val 大的元素优先级低，val 小的元素优先级高 → 最小堆

## 换个角度理解

把比较过程具体化：

```cpp
Item small(1, 10);   // val=10
Item large(2, 100);  // val=100

// 比较 small < large
bool result = small < large; 
// 实际调用：small.operator<(large)
// 执行：return 10 > 100;  → return false;

// 优先队列看到 false，认为：small 不小于 large
// 所以 small 的优先级不低于 large → small 应该在前面
```

## 记忆技巧

**重载 `<` 但思维要反转**：
- 你想要最小堆 → 实际上要让"大"的元素在比较中"更小"
- 所以用 `return val > a.val` 

或者更直观的理解：**我们是在重新定义"小于"的含义**，让val大的元素在优先队列的视角里变得"更小"（优先级更低）。

## 验证理解

可以这样测试你的理解：
```cpp
// 如果我想实现最大堆（val大的优先级高）
bool operator<(const Item &a) const {
    return val < a.val;  // val小的优先级低
}
```

这样当 `current.val < a.val` 时返回true，说明当前对象优先级低于a，符合最大堆要求。


## 理解机制

当优先队列需要比较两个元素 `A` 和 `B` 时：

1. **优先队列是最大堆**：默认希望"大"的元素在队首
2. 它调用 `A < B`：
   - 如果 `A < B` 返回 `true`：说明 A 比 B 小，A 的优先级低于 B
   - 如果 `A < B` 返回 `false`：说明 A 不小于 B，A 的优先级不低于 B

## 具体到你的例子

```cpp
bool operator<(const Item &a) const {
    return val > a.val;  // 当前对象的val > 参数a的val
}
```

当比较 `item1 < item2` 时：
- 如果 `item1.val > item2.val`，返回 `true`
- 优先队列看到返回 `true`，认为：`item1 < item2` 成立
- 所以 `item1` 的优先级低于 `item2`

**结果**：val 大的元素优先级低，val 小的元素优先级高 → 最小堆

## 换个角度理解

把比较过程具体化：

```cpp
Item small(1, 10);   // val=10
Item large(2, 100);  // val=100

// 比较 small < large
bool result = small < large; 
// 实际调用：small.operator<(large)
// 执行：return 10 > 100;  → return false;

// 优先队列看到 false，认为：small 不小于 large
// 所以 small 的优先级不低于 large → small 应该在前面
```

## 记忆技巧

**重载 `<` 但思维要反转**：
- 你想要最小堆 → 实际上要让"大"的元素在比较中"更小"
- 所以用 `return val > a.val` 

或者更直观的理解：**我们是在重新定义"小于"的含义**，让val大的元素在优先队列的视角里变得"更小"（优先级更低）。

## 验证理解

可以这样测试你的理解：
```cpp
// 如果我想实现最大堆（val大的优先级高）
bool operator<(const Item &a) const {
    return val < a.val;  // val小的优先级低
}
```

这样当 `current.val < a.val` 时返回true，说明当前对象优先级低于a，符合最大堆要求。