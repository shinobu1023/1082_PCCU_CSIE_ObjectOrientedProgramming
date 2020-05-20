/*==========================================

第二題-Template Queue

==========================================*/

/* 本題重點： 將物件修改成template、運用既定類別完成題目要求、字元處理 */

#include <iostream>
using namespace std;

// Queue with template
template <typename T>
class Queue
{
public:
    Queue();
    void push(T value);
    void pop();
    bool isEmpty() const;
    bool isFull() const;
    T getFront() const;
    T getBack() const;
    int getSize() const;

private:
    T *elements;
    int capacity;
    int front;
    int back;
    void ensureCapacity();
};

template <typename T>
Queue<T>::Queue() : capacity(16), front(-1), back(-1)
{
    elements = new T[capacity];
}

template <typename T>
void Queue<T>::push(T value)
{
    if (isFull())
        ensureCapacity();
    elements[++back] = value;
}

template <typename T>
void Queue<T>::pop()
{
    front++;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return (front == back);
}

template <typename T>
bool Queue<T>::isFull() const
{
    return (back + 1 == capacity);
}

template <typename T>
T Queue<T>::getFront() const
{
    return elements[front + 1];
}

template <typename T>
T Queue<T>::getBack() const
{
    return elements[back];
}

template <typename T>
int Queue<T>::getSize() const
{
    return (back - front);
}

template <typename T>
void Queue<T>::ensureCapacity()
{
    capacity *= 2;
    T *newQueue = new T[capacity];

    int j = -1;
    for (int i = front + 1; i <= back; i++)
    {
        j++;
        newQueue[j] = elements[i];
    }
    front = -1;
    back = j;
    delete[] elements;
    elements = newQueue;
}

// 主程式
int main()
{
    // 宣告一個Queue物件
    Queue<char> queue;
    // 輸入7個值並push至Queue中
    char input;
    for (int i = 0; i < 7; i++)
    {
        cin >> input;
        queue.push(input);
    }
    // 利用迴圈計算直到Queue的大小剩一個值為止
    while (queue.getSize() != 1)
    {
        // 判斷起始值是否為數字
        if (queue.getFront() >= '0' && queue.getFront() <= '9')
        {
            // 取數字字元一個值，並將值從Queue中pop掉
            int num_1 = queue.getFront() - '0';
            queue.pop();
            // 取數字字元一個值，並將值從Queue中pop掉
            int num_2 = queue.getFront() - '0';
            queue.pop();
            // 取符號字元一個值，並將值從Queue中pop掉
            char op = queue.getFront();
            queue.pop();
            // 利用 switch 判斷符號字元為加減乘除並計算後推回至Queue中
            switch (op)
            {
            case '+':
                queue.push((num_1 + num_2) + '0');
                break;
            case '-':
                queue.push((num_1 - num_2) + '0');
                break;
            case '*':
                queue.push((num_1 * num_2) + '0');
                break;
            case '/':
                queue.push((num_1 / num_2) + '0');
                break;
            }
            // 印出最後面的值
            cout << queue.getBack() << endl;
        }
        else
        {
            // 若起始值非數字則直接推回至Queue中，重新計算
            queue.push(queue.getFront());
            queue.pop();
        }
    }

    return 0;
}