#C++ std::function 保姆级教程

##什么是 std::function？

`std::function` 是 C++ 11 引入的函数包装器，它可以存储、复制和调用任何可调用对象（函数、Lambda表达式、函数对象等）。它定义在 `<functional>` 头文件中。

    ##1. 基本用法

    ## #1.1 包含头文件
```cpp
#include <functional>
#include <iostream>
    using namespace std;
```

    ## #1.2 声明和初始化
```cpp int
    main()
{
    // 声明一个可以调用返回int，无参数的function
    function<int()> func1;

    // 声明一个接受两个int参数，返回int的function
    function<int(int, int)> func2;

    return 0;
}
```

    ##2. 包装不同类型的可调用对象

    ## #2.1 包装普通函数
```cpp
#include <functional>
#include <iostream>
    using namespace std;

// 普通函数
int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    // 包装普通函数
    function<int(int, int)> func_add = add;
    function<int(int, int)> func_multiply = multiply;

    cout << "5 + 3 = " << func_add(5, 3) << endl;
    cout << "5 * 3 = " << func_multiply(5, 3) << endl;

    return 0;
}
```

    ## #2.2 包装Lambda表达式
```cpp
#include <functional>
#include <iostream>
    using namespace std;

int main()
{
    // 包装Lambda表达式
    function<int(int, int)> lambda_func = [](int a, int b) {
        return a * a + b * b;
    };

    function<void()> hello_func = []() {
        cout << "Hello from Lambda!" << endl;
    };

    cout << "3^2 + 4^2 = " << lambda_func(3, 4) << endl;
    hello_func();

    return 0;
}
```

    ## #2.3 包装函数对象（仿函数）
```cpp
#include <functional>
#include <iostream>
    using namespace std;

// 函数对象（仿函数）
class Power
{
    int exponent;

public:
    Power(int exp) : exponent(exp) {}

    double operator()(double base) const
    {
        double result = 1.0;
        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }
        return result;
    }
};

int main()
{
    // 包装函数对象
    Power square(2);
    Power cube(3);

    function<double(double)> func_square = square;
    function<double(double)> func_cube = cube;

    cout << "5的平方: " << func_square(5.0) << endl;
    cout << "5的立方: " << func_cube(5.0) << endl;

    return 0;
}
```

    ## #2.4 包装成员函数
```cpp
#include <functional>
#include <iostream>
    using namespace std;

class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    int subtract(int a, int b)
    {
        return a - b;
    }

    static int multiply(int a, int b)
    {
        return a * b;
    }
};

int main()
{
    Calculator calc;

    // 包装普通成员函数（需要对象实例）
    function<int(Calculator *, int, int)> member_func = &Calculator::add;

    // 包装静态成员函数（和普通函数一样）
    function<int(int, int)> static_func = &Calculator::multiply;

    cout << "成员函数: " << member_func(&calc, 5, 3) << endl;
    cout << "静态函数: " << static_func(5, 3) << endl;

    // 使用std::bind绑定对象实例
    auto bound_func = bind(&Calculator::subtract, &calc, placeholders::_1, placeholders::_2);
    function<int(int, int)> bound_function = bound_func;
    cout << "绑定后的函数: " << bound_function(5, 3) << endl;

    return 0;
}
```

    ##3. std::function 的常用操作

    ## #3.1 检查是否为空
```cpp
#include <functional>
#include <iostream>
    using namespace std;

int main()
{
    function<int(int, int)> func;

    // 检查function是否为空
    if (!func) {
        cout << "func 是空的" << endl;
    }

    func = [](int a, int b) { return a + b; };

    if (func) {
        cout << "func 现在有内容: " << func(5, 3) << endl;
    }

    // 使用empty()方法检查
    if (func.empty()) {
        cout << "func 是空的" << endl;
    } else {
        cout << "func 不为空" << endl;
    }

    return 0;
}
```

    ## #3.2 重置和交换
```cpp
#include <functional>
#include <iostream>
    using namespace std;

int main()
{
    function<int(int)> square = [](int x) { return x * x; };
    function<int(int)> cube = [](int x) { return x * x * x; };

    cout << "square(5): " << square(5) << endl;

    // 重置function
    square.reset();
    if (!square) {
        cout << "square 已被重置为空" << endl;
    }

    // 交换两个function的内容
    function<int(int)> temp = cube;
    cube.swap(square);

    cout << "交换后 cube 是否为空: " << !cube << endl;
    cout << "square(3): " << square(3) << endl;

    return 0;
}
```

    ##4. 实际应用场景

    ## #4.1 回调函数系统
```cpp
#include <functional>
#include <iostream>
#include <vector>
    using namespace std;

class EventSystem
{
private:
    vector<function<void()>> callbacks;

public:
    // 注册回调函数
    void registerCallback(function<void()> callback)
    {
        callbacks.push_back(callback);
    }

    // 触发所有回调
    void triggerEvent()
    {
        for (auto &callback : callbacks) {
            if (callback) {
                callback();
            }
        }
    }
};

int main()
{
    EventSystem eventSystem;

    // 注册多个不同类型的回调
    eventSystem.registerCallback([]() {
        cout << "回调1: 事件被触发了！" << endl;
    });

    eventSystem.registerCallback([]() {
        cout << "回调2: 处理事件..." << endl;
    });

    int counter = 0;
    eventSystem.registerCallback([&counter]() {
        counter++;
        cout << "回调3: 计数器 = " << counter << endl;
    });

    // 触发事件
    cout << "第一次触发:" << endl;
    eventSystem.triggerEvent();

    cout << "\n第二次触发:" << endl;
    eventSystem.triggerEvent();

    return 0;
}
```

    ## #4.2 命令模式
```cpp
#include <functional>
#include <iostream>
#include <map>
    using namespace std;

class CommandProcessor
{
private:
    map<string, function<void()>> commands;

public:
    void registerCommand(const string &name, function<void()> command)
    {
        commands[name] = command;
    }

    void executeCommand(const string &name)
    {
        auto it = commands.find(name);
        if (it != commands.end() && it->second) {
            it->second();
        } else {
            cout << "未知命令: " << name << endl;
        }
    }
};

int main()
{
    CommandProcessor processor;

    // 注册命令
    processor.registerCommand("start", []() {
        cout << "系统启动中..." << endl;
    });

    processor.registerCommand("stop", []() {
        cout << "系统停止中..." << endl;
    });

    processor.registerCommand("status", []() {
        cout << "系统状态: 运行中" << endl;
    });

    // 执行命令
    processor.executeCommand("start");
    processor.executeCommand("status");
    processor.executeCommand("stop");
    processor.executeCommand("unknown"); // 未知命令

    return 0;
}
```

    ## #4.3 策略模式
```cpp
#include <functional>
#include <iostream>
#include <vector>
    using namespace std;

class Sorter
{
private:
    function<void(vector<int> &)> sortStrategy;

public:
    void setStrategy(function<void(vector<int> &)> strategy)
    {
        sortStrategy = strategy;
    }

    void sort(vector<int> &data)
    {
        if (sortStrategy) {
            sortStrategy(data);
        } else {
            cout << "没有设置排序策略!" << endl;
        }
    }
};

int main()
{
    Sorter sorter;
    vector<int> data = {5, 2, 8, 1, 9, 3};

    // 设置冒泡排序策略
    sorter.setStrategy([](vector<int> &arr) {
        cout << "使用冒泡排序" << endl;
        for (size_t i = 0; i < arr.size(); ++i) {
            for (size_t j = 0; j < arr.size() - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    });

    sorter.sort(data);
    cout << "排序后: ";
    for (int num : data)
        cout << num << " ";
    cout << endl;

    // 更换策略为选择排序
    data = {5, 2, 8, 1, 9, 3}; // 重置数据
    sorter.setStrategy([](vector<int> &arr) {
        cout << "使用选择排序" << endl;
        for (size_t i = 0; i < arr.size(); ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < arr.size(); ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    });

    sorter.sort(data);
    cout << "排序后: ";
    for (int num : data)
        cout << num << " ";
    cout << endl;

    return 0;
}
```

    ##5. 高级用法

    ## #5.1 函数组合
```cpp
#include <functional>
#include <iostream>
    using namespace std;

// 函数组合：f(g(x))
template <typename T>
function<T(T)> compose(function<T(T)> f, function<T(T)> g)
{
    return [f, g](T x) { return f(g(x)); };
}

int main()
{
    function<int(int)> square = [](int x) { return x * x; };
    function<int(int)> increment = [](int x) { return x + 1; };
    function<int(int)> double_val = [](int x) { return x * 2; };

    // 组合函数：先平方，再加1
    auto square_then_increment = compose<int>(increment, square);
    cout << "(5^2) + 1 = " << square_then_increment(5) << endl;

    // 组合多个函数：先加倍，再平方，再加1
    auto complex_op = compose<int>(compose<int>(increment, square), double_val);
    cout << "((5*2)^2) + 1 = " << complex_op(5) << endl;

    return 0;
}
```

    ## #5.2 记忆化（缓存）函数
```cpp
#include <functional>
#include <iostream>
#include <map>
    using namespace std;

template <typename Result, typename... Args>
function<Result(Args...)> memoize(function<Result(Args...)> func)
{
    return [func](Args... args) {
        static map<tuple<Args...>, Result> cache;

        auto key = make_tuple(args...);
        auto it = cache.find(key);

        if (it != cache.end()) {
            cout << "从缓存中获取结果" << endl;
            return it->second;
        }

        cout << "计算新结果" << endl;
        auto result = func(args...);
        cache[key] = result;
        return result;
    };
}

int main()
{
    function<int(int)> fibonacci = [&](int n) -> int {
        if (n <= 1)
            return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    };

    auto memoized_fib = memoize<int, int>(fibonacci);

    cout << "斐波那契数列:" << endl;
    for (int i = 0; i <= 10; ++i) {
        cout << "fib(" << i << ") = " << memoized_fib(i) << endl;
    }

    return 0;
}
```

    ##6. 注意事项

    ## #6.1 性能考虑
```cpp
#include <chrono>
#include <functional>
#include <iostream>
    using namespace std;
using namespace chrono;

void testPerformance()
{
    auto start = high_resolution_clock::now();

    function<int(int, int)> func = [](int a, int b) { return a + b; };

    int result = 0;
    for (int i = 0; i < 1000000; ++i) {
        result += func(i, i + 1);
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "std::function 执行时间: " << duration.count() << " 微秒" << endl;
}

int main()
{
    testPerformance();
    return 0;
}
```

    ## #6.2 类型安全
```cpp
#include <functional>
#include <iostream>
    using namespace std;

int main()
{
    // 正确的类型匹配
    function<int(int, int)> correct_func = [](int a, int b) { return a + b; };

    // 错误！返回类型不匹配
    // function<string(int, int)> wrong_func = [](int a, int b) { return a + b; };

    // 错误！参数类型不匹配
    // function<int(string, string)> wrong_func2 = [](int a, int b) { return a + b; };

    cout << "类型安全检查通过" << endl;
    return 0;
}
```

        ##总结

`std::function` 的主要优势： 1. *
        *类型擦除 **：可以存储各种可调用对象 2. * *统一接口 **：提供一致的调用语法 3. * *运行时多态 **：可以在运行时改变行为 4. * *安全性 **：提供类型安全检查

                                                                                                                                      使用场景： -
    回调函数系统 - 命令模式 - 策略模式 - 事件处理 - 函数组合和装饰器

                                                        注意事项： -
    有一定的性能开销 - 需要检查是否为空 before calling - 注意生命周期管理（特别是捕获引用时）

`std::function` 是现代C++ 中非常重要的工具，熟练掌握它能大大提高代码的灵活性和可维护性！