#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool comp(pair<int, int> p1, pair<int, int> p2);

void pairs()
{
    pair<int, int> p1 = {1, 3};
    cout << p1.first << " " << p1.second << endl;

    // Nested
    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[1].second << endl;
}

void vectors()
{
    // push_back() is used to add elements to the vector by copying the provided value or object into the vector's storage.
    // It makes a copy of the given element and inserts that copy into the vector.
    // This means that the element must be copy-constructible and incur a copy operation.

    // emplace_back() is used to add elements to the vector by constructing them directly in the vector's storage without making any unnecessary copies.
    // It forwards the arguments directly to the constructor of the element being inserted, effectively constructing the element in-place inside the vector.
    // This means that the element must be constructible with the given arguments, but it avoids a copy operation and is generally more efficient.
    vector<int> v1;     // creates an empty container
    v1.push_back(1);    // Slower
    v1.emplace_back(2); // faster
    v1.emplace_back(3); // faster
    v1.emplace_back(4); // faster
    v1.emplace_back(5); // faster
    v1.emplace_back(6); // faster
    v1.emplace_back(7); // faster
    v1.emplace_back(8); // faster

    vector<pair<int, int>> v2;
    v2.push_back({1, 2});
    v2.emplace_back(3, 4); // no need to give {} because emplace_back assumes it as an array if you give 2 elements seperated by ,

    vector<int> v3(5, 100); // gives {100,100,100,100,100}
    vector<int> v4(5);      // gives {0,0,0,0,0} You get container with 5 instances of 0. This again depends on the compiler.
    vector<int> v5(5, 20);  // {20,20,20,20,20}
    vector<int> v6(v5);     // {20,20,20,20,20}

    // Iterators
    vector<int>::iterator it = v1.begin();
    printf("The memory location is - %xx \n", it); // I wasn't able to output it using cout
    // cout << std::hex << it; Does not work
    cout << *(it) << endl;
    it++;
    cout << *(it) << endl;
    it += 2;
    cout << *(it) << endl;
    vector<int>::iterator it2 = v1.end();

    cout << v1[0] << " " << v1.at(0) << endl;
    cout << v1.back() << endl;

    // Printing
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
        cout << *(it) << " ";

    cout << endl;

    for (auto it = v1.begin(); it != v1.end(); it++)
        cout << *(it) << " ";
    cout << endl;
    // The auto operator used above can also used to automatically assign datatypes to variables
    auto a = 15;
    auto b = "Srinath";
    auto c = 34.3434343;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;

    // Printing using for each loop
    for (auto it : v1)
        cout << it << " ";
    cout << endl;

    // Deleting vectors
    v1.erase(v1.begin());
    cout << "After earsing - ";
    for (auto it : v1)
        cout << it << " ";
    cout << endl;
    // Syntax - v1.erase(starting address from where u want to delete, end address after the element which you want to delete)
    v1.erase(v1.begin() + 1, v1.begin() + 4);
    cout << "After erasing second time - ";
    for (auto it : v1)
        cout << it << " ";
    cout << endl;

    // Insert - It is a very time consuming function!
    // So use v.emplace(iterator_where_you_want_to_insert, value_which_you_want_to_insert)
    vector<int> v(2, 100);          // {100, 100}
    v.insert(v.begin(), 300);       // {300, 100, 100}
    v.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

    vector<int> copy(2, 50);                       // copy = {50, 50}
    v.insert(v.begin(), copy.begin(), copy.end()); // {50,50,300,10,10,100,100}

    cout << v.size() << endl;

    v.pop_back(); // Removes last elemet
    v1.swap(v3);  // Swaps th elements of v1 with v3
    v.clear();    // Erases the entire vector
    cout << "Is empty - " << v.empty();
}

// These are implemented are doubly linked lists!
void lists()
{
    list<int> ls;
    ls.push_back(1);
    ls.emplace_back(2);
    ls.push_front(3);
    ls.emplace_front(4);
    ls.emplace_front(5);
    // Rest func same as vector - begin, end, rbegin, rend, clear, insert, size, swap
    for (auto it : ls)
        cout << it << " ";
    cout << endl;
}

void dequeues() // Double ended queues
{
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(3);
    dq.emplace_front(4);
    for (auto it : dq)
        cout << it << " ";
    cout << endl;

    dq.pop_back();
    for (auto it : dq)
        cout << it << " ";
    cout << endl;
    dq.pop_front();
    for (auto it : dq)
        cout << it << " ";
    cout << endl;

    cout << "Back - " << dq.back() << endl;
    cout << "Front - " << dq.front();
    // Rest func same as vector - begin, end, rbegin, rend, clear, insert, size, swap
}

void stacks()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.emplace(5);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    cout << st.empty() << endl;
    stack<int> st1, st2;
    st1.swap(st2);
}

void priorityQueue() // Data is not stored in a linear fashion, a tree is maintained inside
{
    // In priority_queue push -> log(n). top -> (1). pop -> log(n)
    // In below elements are arranged left to right as top to bottom (largest element on top)
    // Maximum element is stored on top. It is called as max heap!
    priority_queue<int> pq;
    pq.push(5);     // {5}
    pq.push(2);     // {5, 2}
    pq.push(8);     // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}
    cout << pq.top() << endl;

    // size, swap and empty func same as others

    // Priority queue to store the min element on top. It is called as min heap
    // Declare the datatype as below
    priority_queue<int, vector<int>, greater<int>> pqq;
    pqq.push(5);     // {5}
    pqq.push(2);     // {2, 5}
    pqq.push(8);     // {2, 5, 8}
    pqq.emplace(10); // {2, 5, 8, 10}
    cout << pqq.top() << endl;
}

void sets() // Everything in a sorted order and unique (non-repetition)
// A tree is maintained in it
// Everything happens in logarithmic time complexity
{
    set<int> s;
    s.insert(1);
    s.emplace(2);

    s.insert(2);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);

    // Functionality of insert in vector can be used also, this only increases the efficiency
    // Rest functions are all same as above
    auto it1 = s.find(3); // Returns an iterator that points to 3
    auto it2 = s.find(6); // Returns s.end() because 6 is not present in set
    s.erase(5);           // Takes log time
    int c = s.count(2);   // Will have only one occurance

    auto it5 = s.find(3);
    s.erase(it5); // takes constant time!
    auto it11 = s.find(2);
    auto it21 = s.find(4);
    s.erase(it1, it2);

    auto it3 = s.lower_bound(2);
    auto it4 = s.upper_bound(2);
}

void multiSet()
// Everything same as set, stores duplicate elements also
{
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    cout << ms.count(1) << endl;
    ms.erase(1); // All 1's are erased
    cout << ms.count(1) << endl;

    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    cout << ms.count(1) << endl;
    ms.erase(ms.find(1)); // Only a single 1 erased
    cout << ms.count(1) << endl;
}

void unorderedSet()
{
    unordered_set<int> us;
    // Everything same as set except that it doesn't store in order!!
    // It will have random order, but no repetition!!
}

void maps()
// Map stores everything in respect of keys and values
// Map stores unique keys in sorted order only!
{
    map<int, int> mp1;
    map<int, pair<int, int>> mp2;
    map<pair<int, int>, int> mp3;
    mp1[1] = 2;
    mp1.insert({3, 7});
    mp1.emplace(6, 7);

    mp3[{2, 3}] = 10;

    for (auto it : mp1)
        cout << it.first << " " << it.second << endl;
    cout << mp1[1] << endl;
    cout << mp1[6] << endl;
    cout << "Doesn't exist " << mp1[9] << endl;

    auto it4 = mp1.find(3); // Here 3 is the key!
    cout << (*(it4)).second << endl;
    auto it = mp1.find(12); // Which doesnt exits, points to after the end of map.
    auto it1 = mp1.lower_bound(2);
    auto it2 = mp1.upper_bound(2);
}

void multiMap()
{
    multimap<int, int> mm;
    // Same as map but can store multiple keys
    // only map[key] cannot be used here
}

void unorderedMap()
{
    // The keys aren't necessarily stored in ascending order!
}

void sorting()
{
    int arr[] = {3, 7, 2, 56, 8, 3, 23, 0, 6978, 11};
    sort(&arr[0], &arr[10]);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
    vector<int> v;
    sort(v.begin(), v.end());
    sort(&arr[5], &arr[8]); // We can sort in between elements also!

    sort(v.begin(), v.end(), greater<int>()); // For sorting in descending order
    // greater<int>() is a inbuilt comparator!!
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Sort it in the order of increasing second element
    // If second element is same then
    // Sort it according it according to first element, but in descending
    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    sort(a, a + 3, comp); // comp is a boolean self-written comparator defined below

    int num1 = 7;                       // Binary of 7 is 111
    int cnt = __builtin_popcount(num1); // This returns 3 as the number of 1's in binary of 7 are 3!
    cout << " __builtin_popcount() - " << cnt << endl;

    long long num = 12312524563567467;
    int cn = __builtin_popcountll(num);
    cout << " __builtin_popcountll() - " << cn << endl;

    string s = "123"; // This must be sorted!! Printing all the permutations
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    cout << "BREAK" << endl;

    // Suppose you give non-sorted
    string ss = "231";
    do
    {
        cout << ss << endl;
    } while (next_permutation(ss.begin(), ss.end()));
    // We got less permutations! So always give in sorted order
    // Sort using sort(ss.begin(), ss.end());

    int aa[] = {1, 45, 2, 4678, 63, 0, 2, 3, 9, 878};
    int *maxi = max_element(aa, aa + 10);
    cout << "maxi - " << maxi << endl;
}
bool comp(pair<int, int> p1, pair<int, int> p2)
// We assume that p1 lies before than p2!
{
    if (p1.second < p2.second)
        return true; // Means that p1.second < p2.second. They are in correct order. No need to change
    if (p1.second > p2.second)
        return false; // They are in wrong order. So change the order!
    // Below will execute only if they are same!
    if (p1.first > p2.first)
        return true;
    return false;
}

int main()
{
    // pairs();
    vectors();
    // lists();
    // dequeues();
    // stacks();
    // priorityQueue();
    // sets();
    // multiSet();
    // unorderedSet();
    // maps();
    // sorting();
    return 0;
}