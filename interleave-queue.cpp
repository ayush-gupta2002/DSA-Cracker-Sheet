#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    stack<int> s1;
    int n = q.size();
    int count = 0;
    while(count != n/2){
        int val = q.front();
        s1.push(val);
        q.pop();
        count++;
    }
    while(!s1.empty()){
        int val = s1.top();
        q.push(val);
        s1.pop();
    }
    count = 0;
    while(count != n/2){
        int val = q.front();
        q.push(val);
        q.pop();
        count++;
    }
    count = 0;
    while(count != n/2){
        int val = q.front();
        s1.push(val);
        q.pop();
        count++;
    }
    while(!s1.empty()){
        q.push(s1.top());
        s1.pop();
        int val = q.front();
        q.push(val);
        q.pop();
    }
}
