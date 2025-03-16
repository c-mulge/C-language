#include <iostream>
#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main()
{
    // pair<int, int> a[] = {{1, 2}, {3, 4}, {5, 6}};
    // cout << a[1].second;
    vector<int> v;     // defining a vector
    v.push_back(1);    // Method-1 for pushing elements
    v.emplace_back(2); // Method-2 for pushing elements

    // cout << v1[5];
    vector<int> v1(5, 20); //(size of, default value)  the default value is stored number of times
    v1.emplace_back(10);

    // vector<int>::iterator it; // deining an iterator
    /*for (auto it : v1) // for each loop
    {
        cout << it << " ";
    }*/
    /*
     vector<int> v2;
     v2 = {10, 20, 30, 40};
     cout << "Vector: ";
     for (auto it : v2)
     {
         cout << it << " ";
     }
     cout << endl;
     cout << "Insert: ";
     v2.insert(v2.begin() + 1, 25);
     for (auto it : v2)
     {
         cout << it << " ";
     }
     cout << endl;
     cout << "Erase: ";
     v2.erase(v2.begin() + 1); // 20 is deleted from the vector
     for (auto it : v2)
     {
         cout << it << " ";
     }

     v2.pop_back(); // pops the last element
     v2.swap(v1);   // swaps the vectors
     v2.size();     // returns the size of the vector
     v2.clear();    // clear the vector
     cout << v2.empty();
     */

    list<int> ls; // list same as vector and uses double linked list
    ls.push_back(1);
    ls.emplace_back(2);
    ls.push_front(0);
    ls.emplace_front(-1);
    for (auto it : ls)
    {
        cout << it << " ";
    }
    /*
     deque<int> dq;          //deque same as vector
     dq.push_front(1);
     dq.emplace_back(2);
     dq.emplace_back(3);
     dq.back();
     dq.front();
     for (auto it : dq)
     {
         cout << it << " ";
     }*/
    /*
    stack<int> st;          //stack algorithm uses-push,pop,top
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    cout << st.empty() << endl;
    */

    /*
     queue<int> q;
     q.push(1);
     q.push(2);
     q.push(3);
     cout << q.front() << endl;
     q.pop();
     cout << q.front() << endl;
     cout << q.size() << endl;
     cout << q.empty() << endl;
     */
    /*
    priority_queue<int> pq;         //MAX HEAP
    pq.push(1);
    pq.push(2);
    pq.push(3);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    priority_queue<int, vector<int>, greater<int>> pq1;        //MIN HEAP
    pq1.push(1);
    pq1.push(2);
    pq1.push(3);
    cout << pq1.top() << endl;
    pq1.pop();
    cout << pq1.top() << endl;
    */

    /*
     set<int> s; // store in sorted order and unique value ie. value's are not repeated
     s.insert(1);
     s.insert(3);
     s.insert(2);
     for (auto it : s)
     {
         cout << it << " ";
     }
     cout << endl;
     s.insert(6);
     s.erase(3);
     for (auto it : s)
     {
         cout << it << " ";
     }
     */

    /*
    map<int, char> m; // stores in sorted order with unique key
    m.emplace(1, 's');
    m.emplace(3, 'b');
    m.emplace(2, 'c');
    for (auto it : m)
    {
        cout << it.first << " " << it.second << endl;
    }

    //have types like- multi_map and unordered_map
    */

    /*
     vector<int> vn;
     vn = {10,
           30,
           20,
           15};
     for (auto it : vn)
     {
         cout << it << " ";
     }
     cout << endl;
     sort(vn.begin(), vn.end());
     for (auto it : vn)
     {
         cout << it << " ";
     }
     cout << endl;
     sort(vn.begin(), vn.end(), greater<int>());
     for (auto it : vn)
     {
         cout << it << " ";
     }
     cout << endl;

     */

    /*
    int num = 9;
    int cnt = __builtin_popcount(num); // counts the 1s occured in binary string of 32 bits
    cout << cnt << endl;

    long long n = 121544561365;
    int c = __builtin_popcountll(n);
    cout << c << endl;
    */

    /*
     string s = "123";   //gives like all possible dictionary order of the string
     do
     {
         cout << s << endl;
     } while (next_permutation(s.begin(), s.end()));
     */
    /*
    vector<int> vn;
    vn = {1,
          10,
          20,
          30,
          15,
          16};
    int maxi = *max_element(vn.begin(), vn.end());
    int mini = *min_element(vn.begin(), vn.end());
    cout << "Max: " << maxi << endl;
    cout << "Min: " << mini << endl;
    */
}