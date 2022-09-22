#include <iostream>

#include "stack.h"
#include "queue.h"

int main()
{
    stack<int> st;

    std::cout << st.empty() << "\n"; //True
    st.push(1); //Stack: 1
    st.push(2); //Stack: 1 2
    st.pop(); //Stack: 1
    std::cout << st.size() << "\n"; //Size = 1

    queue<char> Q;
    Q.push('a'); //Queue: a
    Q.push('b'); //Queue: a b
    std::cout << Q.front() << "\n"; // a
    Q.pop(); //Queue: b
    return 0;
}
