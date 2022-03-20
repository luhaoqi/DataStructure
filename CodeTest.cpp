#include <iostream>
#include <cstdio>
#include "SequentialList.h"
#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "BigInteger.h"
#include "Polynomial.h"
#include "SequentialStack.h"
#include "LinkedStack.h"
#include "Calculate.h"
#include "SequentialQueue.h"
#include "LinkedQueue.h"
#include "SequentialString.h"
#include "LinkedString.h"
#include "PriorityQueue.h"
#include "LinkedBinaryTree.h"
#include "HuffmanTree.h"

void SequentialListTest()
{
    printf("---------- SequentialList ----------\n");
    int a[] = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    SequentialList<int> s(5);
    for (int i = 0; i < 10; i++)
        s.append(a[i]);
    s.traverse();
    if (s.find(4) == -1)
        printf("Element 4 was not found in list\n");
    printf("Element 34 was found by index %d\n", s.find(34));
    printf("Element %d was fetched by index 3\n", s.fetch(3));
    printf("Element %d was visited by index 3\n", s[3]);
    for (int i = 1; i <= 4; i++)
        s.remove(3);
    s.insert(3, 114514);
    printf("Current length of list is %d\n", s.length());
    s.traverse();
    printf("---------- SequentialList ----------\n\n");
}

void SingleLinkedListTest()
{
    printf("---------- SingleLinkedList ----------\n");
    int a[] = { 1, 4, 7, 10, 1, 4, 7, 10, 1, 4 };
    SingleLinkedList<int> s;
    for (int i = 0; i < 10; i++)
        s.append(a[i]);
    s.traverse();
    if (s.find(5) == -1)
        printf("Element 5 was not found in list\n");
    printf("Element 10 was found by index %d\n", s.find(10));
    printf("Element %d was fetched by index 3\n", s.fetch(3));
    for (int i = 1; i <= 3; i++)
        s.remove(2);
    s.insert(2, 114514);
    printf("Current length of list is %d\n", s.length());
    s.traverse();
    printf("Erase relevant element by index 1\n");
    s.erase(1);
    s.traverse();
    printf("---------- SingleLinkedList ----------\n\n");
}

void DoubleLinkedListTest()
{
    printf("---------- DoubleLinkedList ----------\n");
    DoubleLinkedList<int> s;
    for (int i = 1; i <= 5; i++)
    {
        s.push_front(2 * i - 1);
        s.push_back(2 * i);
    }
    s.traverse();
    if (s.find(11) == -1)
        printf("Element 11 was not found in list\n");
    printf("Element 8 was found by index %d\n", s.find(8));
    printf("Element %d was fetched by index 4\n", s.fetch(4));
    for (int i = 1; i <= 3; i++)
        s.remove(2);
    s.insert(2, 114514);
    printf("Current length of list is %d\n", s.length());
    s.traverse();
    printf("List was reversed in order\n");
    s.reverse();
    s.traverse();
    printf("Element 8 was found by index %d\n", s.find(8));
    printf("Clear all element in list\n");
    s.clear();
    if (s.find(8) == -1)
        printf("Element 8 was not found in list\n");
    printf("Current length of list is %d\n", s.length());
    printf("---------- DoubleLinkedList ----------\n\n");
}

void BigIntegerTest()
{
    using namespace std;
    printf("---------- BigInteger ----------\n");
    BigInteger a("1"), b, c("-1"), d(2), e(-2);
    cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << endl;
    b = c;
    cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << endl;
    a += b;
    b += c;
    c += d;
    e = d + d;
    d = b + b;
    cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << endl;
    a -= b;
    b -= c;
    d = c - e;
    c = d - (-d);
    e = d - d;
    cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << endl;
    a = a * a * a;
    b *= a;
    c *= b;
    d *= -1;
    a *= d;
    e *= c;
    cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << endl;
    c /= a;
    b /= c;
    e /= d;
    d /= c;
    b /= c;
    a /= 5;
    cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << endl;
    b = c % a;
    d = c % 5;
    e = c % b;
    a = c % -4;
    c = -7 % c;
    b %= 1;
    cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << endl;
    a = power(2, 0);
    b = power(2, 1);
    c = power(2, 10);
    d = power(2, 30);
    e = power(2, 100);
    cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << endl;
    printf("---------- BigInteger ----------\n\n");
}

/*
A polynomial input sample:
5 0
-3 1
0 2
-9 4
12 5
-1 -1
-4 0
3 1
1 2
9 4
-3 5
-4 7
0 9
-1 -1
*/

void PolynomialTest()
{
    printf("---------- Polynomial ----------\n");
    Polynomial P, Q;
    P.input();
    P.output();
    Q.input();
    Q.output();
    Polynomial R = P + Q;
    printf("Two polynomial are added to be:\n");
    R.output();
    printf("---------- Polynomial ----------\n\n");
}

void SequentialStackTest()
{
    printf("---------- SequentialStack ----------\n");
    SequentialStack<int> s(5);
    for (int i = 0; i < 5; i++)
        s.push(i);
    s.pop();
    for (int i = 5; i < 10; i++)
        s.push(i);
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
    s.clear();
    for (int i = 10; i < 15; i++)
        s.push(i);
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
    printf("---------- SequentialStack ----------\n\n");
}

void LinkedStackTest()
{
    printf("---------- LinkedStack ----------\n");
    LinkedStack<int> s;
    for (int i = 0; i < 5; i++)
        s.push(i);
    s.pop();
    for (int i = 5; i < 10; i++)
        s.push(i);
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
    s.clear();
    for (int i = 10; i < 15; i++)
        s.push(i);
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
    printf("---------- LinkedStack ----------\n\n");
}

void CalculateTest()
{
    printf("---------- Calculate ----------\n");
    try
    {
        char E[] = "(2^10 - 24) / (5 * 2^7 + 20 * 18 - (2^4 - 4^2))";
        Calculate C(E);
        printf("%s = %d\n", E, C.getResult());
        char F[] = "(1 / 2) + (3^5 * 10))";
        Calculate D(F);
        printf("%s = %d\n", F, D.getResult());
    }
    catch (...)
    {
        printf("An error occurred while calculating\n");
    }
    printf("---------- Calculate ----------\n\n");
}

void SequentialQueueTest()
{
    printf("---------- SequentialQueue ----------\n");
    SequentialQueue<int> Q(5);
    for (int i = 0; i < 5; i++)
        Q.push(i);
    Q.pop();
    for (int i = 5; i < 10; i++)
        Q.push(i);
    while (!Q.empty())
    {
        printf("%d ", Q.front());
        Q.pop();
    }
    printf("\n");
    Q.clear();
    for (int i = 10; i < 15; i++)
        Q.push(i);
    while (!Q.empty())
    {
        printf("%d ", Q.front());
        Q.pop();
    }
    printf("\n");
    printf("---------- SequentialQueue ----------\n\n");
}

void LinkedQueueTest()
{
    printf("---------- LinkedQueue ----------\n");
    SequentialQueue<int> Q;
    for (int i = 0; i < 5; i++)
        Q.push(i);
    Q.pop();
    for (int i = 5; i < 10; i++)
        Q.push(i);
    while (!Q.empty())
    {
        printf("%d ", Q.front());
        Q.pop();
    }
    printf("\n");
    Q.clear();
    for (int i = 10; i < 15; i++)
        Q.push(i);
    while (!Q.empty())
    {
        printf("%d ", Q.front());
        Q.pop();
    }
    printf("\n");
    printf("---------- LinkedQueue ----------\n\n");
}

void SequentialStringTest()
{
    printf("---------- SequentialString ----------\n");
    using namespace std;
    SequentialString x("123456789"), y("abc");
    x += y;
    y = x.slice(7, 4);
    x.remove(2, 3);
    cout << x << "\t" << y << endl;
    cout << x.length() << "\t" << y.length() << endl;
    x = SequentialString("abandon");
    y = SequentialString("absolute");
    if (x <= y && x < y)
        printf("abandon < absolute\n");
    x = SequentialString("abcdefg");
    y = SequentialString("bcd");
    if (x != y)
        printf("Unequal!\n");
    for (int i = 0; i < x.length(); i++)
        printf("%c", x[i]);
    printf("\n");
    printf("bcd is found in abcdefg at index %d\n", x.find(y));
    printf("bcd is found in bcd at index %d\n", y.find(y));
    if (y.find(x) == -1)
        printf("abcdefg is not found in bcd\n");
    printf("---------- SequentialString ----------\n\n");
}

void LinkedStringTest()
{
    printf("---------- LinkedString ----------\n");
    using namespace std;
    LinkedString x("123456789"), y("abc");
    x += y;
    y = x.slice(7, 4);
    x.remove(2, 3);
    cout << x << "\t" << y << endl;
    cout << x.length() << "\t" << y.length() << endl;
    x = LinkedString("abandon");
    y = LinkedString("absolute");
    if (x <= y && x < y)
        printf("abandon < absolute\n");
    x = LinkedString("abcdefg");
    y = LinkedString("abcdefg ");
    if (x != y)
        printf("Unequal!\n");
    printf("%d\n", x.length());
    for (int i = 0; i < x.length(); i++)
        printf("%c", x[i]);
    printf("\n");
    printf("---------- LinkedString ----------\n\n");
}

void PriorityQueueTest()
{
    printf("---------- PriorityQueue ----------\n");
    PriorityQueue<int> heap;
    int array[15] = { 7, 4, 1, 6, 5, 9, 3, 0, 8, 2 };
    for (int i = 0; i < 10; i++)
        heap.push(array[i]);
    for (int i = 0; i < 10; i++)
        printf("%d ", heap.pop());
    printf("\n");
    heap.clear();
    for (int i = 0; i < 10; i++)
        array[i] = i;
    PriorityQueue<int, Greater<int>> queue(array, 10);
    for (int i = 1; i <= 5; i++)
        queue.push(100 + i);
    for (int i = 0; i < 15; i++)
    {
        int x = queue.front();
        queue.pop();
        printf("%d ", x);
    }
    printf("\n");
    heap.clear();
    if (heap.empty())
        printf("Now heap is already empty!\n");
    printf("---------- PriorityQueue ----------\n\n");
}

/*
A binary tree input sample:
1
2 3
4 5
6 7
-1 8
-1 -1
9 -1
-1 -1
-1 -1
-1 -1
*/

void LinkedBinaryTreeTest()
{
    printf("---------- LinkedBinaryTree ----------\n");
    LinkedBinaryTree<int> T;
    T.createTree(-1);
    T.doPreOrder();
    T.doInOrder();
    T.doPostOrder();
    T.doLevelOrder();
    printTree(T, -1);
    printf("Size of binary tree is %d\n", T.size());
    printf("Height of binary tree is %d\n", T.height());
    T.deleteLeftChild(2);
    T.deleteRightChild(3);
    printTree(T, -1);
    printf("Size of binary tree is %d\n", T.size());
    printf("Height of binary tree is %d\n", T.height());
    T.insertLeftChild(2, 10);
    T.insertLeftChild(10, 11);
    T.insertRightChild(10, 12);
    T.insertRightChild(3, 12);
    T.insertLeftChild(12, 13);
    printTree(T, -1);
    printf("Size of binary tree is %d\n", T.size());
    printf("Height of binary tree is %d\n", T.height());
    printf("---------- LinkedBinaryTree ----------\n\n");
}

void HuffmanTreeTest()
{
    printf("---------- HuffmanTree ----------\n");
    char d[] = "abcde";
    int t[] = { 1, 2, 2, 5, 9 };
    HuffmanTree<char> T(d, t, 5);
    HuffmanTree<char>::HuffmanCode C[5];
    T.getCode(C);
    for (int i = 0; i < 5; i++)
        std::cout << C[i].data << ": " << C[i].code << std::endl;
    printf("Total weight: %d\n", T.getWeight());
    printf("---------- HuffmanTree ----------\n\n");
}

int main()
{
    HuffmanTreeTest();
	std::cout << "---------- All The Tests Have Been Finished! ----------\n";
	return 0;
}