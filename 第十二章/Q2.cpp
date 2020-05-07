/*==========================================

第二題-Template Stack

==========================================*/

#include <iostream>
using namespace std;

// Stack with template
template <typename T>
class Stack
{
public:
    Stack();
    Stack(const Stack &);
    ~Stack();
    bool empty() const;
    T peek() const;
    void push(T value);
    T pop();
    int getSize() const;

private:
    T *elements;
    int size;
    int capacity;
    void ensureCapacity();
};

template <typename T>
Stack<T>::Stack() : size(0), capacity(16)
{
    elements = new T[capacity];
}

template <typename T>
Stack<T>::Stack(const Stack &stack)
{
    elements = new T[stack.capacity];
    size = stack.size;
    capacity = stack.capacity;
    for (int i = 0; i < size; i++)
    {
        elements[i] = stack.elements[i];
    }
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] elements;
}

template <typename T>
bool Stack<T>::empty() const
{
    return (size == 0);
}

template <typename T>
T Stack<T>::peek() const
{
    return elements[size - 1];
}

template <typename T>
void Stack<T>::push(T value)
{
    ensureCapacity();
    elements[size++] = value;
}

template <typename T>
void Stack<T>::ensureCapacity()
{
    if (size >= capacity)
    {
        T *old = elements;
        capacity = 2 * size;
        elements = new T[size * 2];

        for (int i = 0; i < size; i++)
            elements[i] = old[i];

        delete[] old;
    }
}

template <typename T>
T Stack<T>::pop()
{
    return elements[--size];
}

template <typename T>
int Stack<T>::getSize() const
{
    return size;
}

// 主程式
int main()
{
    // 宣告一個Stack物件
    Stack<char> charStack;

    // 輸入9個值並push至stack中
    char input;
    for (int i = 0; i < 9; i++)
    {
        cin >> input;
        charStack.push(input);
    }

    // 兩兩取出並計算後推回至stack中
    for (int i = 0; i < 4; i++)
    {
        // 取數字字元一個值，並將值從stack中pop掉
        int num_1 = charStack.peek() - '0';
        charStack.pop();
        // 取符號字元一個值，並將值從stack中pop掉
        char op = charStack.peek();
        charStack.pop();
        // 取數字字元一個值，並將值從stack中pop掉
        int num_2 = charStack.peek() - '0';
        charStack.pop();
        // 利用 switch 判斷符號字元為加減乘除並計算後推回至stack中
        switch (op)
        {
        case '+':
            charStack.push((num_2 + num_1) + '0');
            break;
        case '-':
            charStack.push((num_2 - num_1) + '0');
            break;
        case '*':
            charStack.push((num_2 * num_1) + '0');
            break;
        case '/':
            charStack.push((num_2 / num_1) + '0');
            break;
        }
        // 印出最上層的值
        cout << charStack.peek() << endl;
    }

    return 0;
}