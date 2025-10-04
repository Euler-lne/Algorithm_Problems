# C++ Lambda表达式保姆级教程

## 什么是Lambda表达式？

Lambda表达式是C++11引入的一种匿名函数，它允许我们在需要函数的地方内联定义函数，使代码更加简洁和灵活。

## 基本语法

```cpp
[capture](parameters) -> return_type {
    // 函数体
}
```

## 1. 最简单的Lambda表达式

```cpp
#include <iostream>
using namespace std;

int main() {
    // 最简单的Lambda：没有参数，没有返回值
    auto hello = []() {
        cout << "Hello, Lambda!" << endl;
    };
    
    hello(); // 调用Lambda
    return 0;
}
```

输出：
```
Hello, Lambda!
```

## 2. 带参数的Lambda

```cpp
#include <iostream>
using namespace std;

int main() {
    // 带参数的Lambda
    auto add = [](int a, int b) {
        return a + b;
    };
    
    auto multiply = [](double x, double y) -> double {
        return x * y;
    };
    
    cout << "5 + 3 = " << add(5, 3) << endl;
    cout << "2.5 * 4.0 = " << multiply(2.5, 4.0) << endl;
    
    return 0;
}
```

输出：
```
5 + 3 = 8
2.5 * 4.0 = 10
```

## 3. 捕获列表详解

### 3.1 值捕获 `[=]`

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int y = 20;
    
    // 值捕获：创建外部变量的副本
    auto value_capture = [=]() {
        cout << "x = " << x << ", y = " << y << endl;
        // x = 5; // 错误！值捕获的变量是只读的
    };
    
    value_capture();
    cout << "原始值 - x: " << x << ", y: " << y << endl;
    
    return 0;
}
```

### 3.2 引用捕获 `[&]`

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int y = 20;
    
    // 引用捕获：直接操作外部变量
    auto reference_capture = [&]() {
        cout << "修改前 - x = " << x << ", y = " << y << endl;
        x = 100;
        y = 200;
        cout << "修改后 - x = " << x << ", y = " << y << endl;
    };
    
    reference_capture();
    cout << "原始值也被修改 - x: " << x << ", y: " << y << endl;
    
    return 0;
}
```

### 3.3 混合捕获

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 2, c = 3, d = 4;
    
    // 混合捕获：a值捕获，b引用捕获，c值捕获，d引用捕获
    auto mixed_capture = [a, &b, c, &d]() {
        cout << "a = " << a << " (值捕获，只读)" << endl;
        cout << "b = " << b << " (引用捕获，可修改)" << endl;
        cout << "c = " << c << " (值捕获，只读)" << endl;
        cout << "d = " << d << " (引用捕获，可修改)" << endl;
        
        b *= 2;  // 可以修改
        d *= 2;  // 可以修改
        // a = 10; // 错误！值捕获的变量不能修改
    };
    
    mixed_capture();
    cout << "调用后 - b: " << b << ", d: " << d << endl;
    
    return 0;
}
```

### 3.4 指定特定变量的捕获方式

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5, y = 10, z = 15;
    
    // 默认值捕获，但y使用引用捕获
    auto capture1 = [=, &y]() {
        cout << "x = " << x << " (值捕获)" << endl;
        cout << "y = " << y << " (引用捕获)" << endl;
        cout << "z = " << z << " (值捕获)" << endl;
        y = 100; // 可以修改y
    };
    
    // 默认引用捕获，但x使用值捕获
    auto capture2 = [&, x]() {
        cout << "x = " << x << " (值捕获)" << endl;
        cout << "y = " << y << " (引用捕获)" << endl;
        cout << "z = " << z << " (引用捕获)" << endl;
        // x = 50; // 错误！x是值捕获，不能修改
        y = 200;   // 可以修改y
        z = 300;   // 可以修改z
    };
    
    capture1();
    capture2();
    
    return 0;
}
```

## 4. mutable关键字

```cpp
#include <iostream>
using namespace std;

int main() {
    int count = 0;
    
    // 使用mutable允许修改值捕获的变量（修改的是副本）
    auto counter = [count]() mutable {
        count++; // 现在可以修改，但修改的是副本
        cout << "内部计数: " << count << endl;
        return count;
    };
    
    cout << "外部计数: " << count << endl;
    counter();
    counter();
    counter();
    cout << "外部计数仍然: " << count << endl;
    
    return 0;
}
```

## 5. Lambda在STL算法中的应用

### 5.1 与std::sort配合使用

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {5, 2, 8, 1, 9, 3};
    
    // 升序排序
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b;
    });
    
    cout << "升序排序: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // 降序排序
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
    });
    
    cout << "降序排序: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
```

### 5.2 与std::for_each配合使用

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    int sum = 0;
    
    // 使用Lambda计算总和
    for_each(numbers.begin(), numbers.end(), [&sum](int n) {
        sum += n;
    });
    
    cout << "总和: " << sum << endl;
    
    // 修改向量中的每个元素
    for_each(numbers.begin(), numbers.end(), [](int &n) {
        n *= 2;
    });
    
    cout << "加倍后: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
```

### 5.3 与std::find_if配合使用

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    
    // 查找第一个偶数
    auto it = find_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0;
    });
    
    if (it != numbers.end()) {
        cout << "第一个偶数是: " << *it << endl;
    }
    
    // 查找大于5的第一个数
    it = find_if(numbers.begin(), numbers.end(), [](int n) {
        return n > 5;
    });
    
    if (it != numbers.end()) {
        cout << "第一个大于5的数是: " << *it << endl;
    }
    
    return 0;
}
```

## 6. 返回Lambda函数

```cpp
#include <iostream>
#include <functional>
using namespace std;

// 返回一个Lambda函数
function<int(int)> createMultiplier(int factor) {
    return [factor](int x) -> int {
        return x * factor;
    };
}

int main() {
    auto doubleIt = createMultiplier(2);
    auto tripleIt = createMultiplier(3);
    
    cout << "5 的两倍: " << doubleIt(5) << endl;
    cout << "5 的三倍: " << tripleIt(5) << endl;
    
    return 0;
}
```

## 7. 实际应用示例

### 7.1 简单的计算器

```cpp
#include <iostream>
#include <functional>
#include <map>
using namespace std;

int main() {
    map<string, function<double(double, double)>> calculator;
    
    // 注册操作
    calculator["+"] = [](double a, double b) { return a + b; };
    calculator["-"] = [](double a, double b) { return a - b; };
    calculator["*"] = [](double a, double b) { return a * b; };
    calculator["/"] = [](double a, double b) { 
        if (b != 0) return a / b;
        else throw runtime_error("除零错误");
    };
    
    try {
        cout << "10 + 5 = " << calculator["+"](10, 5) << endl;
        cout << "10 - 5 = " << calculator["-"](10, 5) << endl;
        cout << "10 * 5 = " << calculator["*"](10, 5) << endl;
        cout << "10 / 5 = " << calculator["/"](10, 5) << endl;
    } catch (const exception& e) {
        cout << "错误: " << e.what() << endl;
    }
    
    return 0;
}
```

### 7.2 过滤器函数

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
vector<T> filter(const vector<T>& vec, function<bool(const T&)> predicate) {
    vector<T> result;
    for (const auto& item : vec) {
        if (predicate(item)) {
            result.push_back(item);
        }
    }
    return result;
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // 过滤出偶数
    auto even_numbers = filter<int>(numbers, [](const int& n) {
        return n % 2 == 0;
    });
    
    cout << "偶数: ";
    for (int num : even_numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // 过滤出大于5的数
    auto large_numbers = filter<int>(numbers, [](const int& n) {
        return n > 5;
    });
    
    cout << "大于5的数: ";
    for (int num : large_numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
```

## 8. C++14和C++17的增强特性

### 8.1 泛型Lambda (C++14)

```cpp
#include <iostream>
using namespace std;

int main() {
    // 泛型Lambda - 自动推导参数类型
    auto generic_add = [](auto a, auto b) {
        return a + b;
    };
    
    cout << "整数相加: " << generic_add(5, 3) << endl;
    cout << "浮点数相加: " << generic_add(2.5, 3.7) << endl;
    cout << "字符串连接: " << generic_add(string("Hello"), string(" World")) << endl;
    
    return 0;
}
```

### 8.2 初始化捕获 (C++14)

```cpp
#include <iostream>
#include <memory>
using namespace std;

int main() {
    int x = 10;
    
    // 初始化捕获 - 在捕获时进行初始化
    auto lambda = [y = x + 5]() {
        cout << "y = " << y << endl;
    };
    
    lambda();
    
    // 移动语义的初始化捕获
    auto ptr = make_unique<int>(42);
    auto lambda2 = [p = move(ptr)]() {
        if (p) {
            cout << "*p = " << *p << endl;
        }
    };
    
    lambda2();
    
    return 0;
}
```

## 总结

Lambda表达式是C++中非常强大的特性，它：

1. **简化代码**：避免为简单操作单独定义函数
2. **提高可读性**：将函数逻辑放在使用的地方
3. **灵活捕获**：通过捕获列表控制对外部变量的访问
4. **与STL完美配合**：在算法中广泛使用
5. **类型安全**：编译器会自动推导类型

掌握Lambda表达式将大大提高你的C++编程效率和代码质量！