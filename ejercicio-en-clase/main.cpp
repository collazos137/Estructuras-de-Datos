#include "queuep.h"
#include <cstdio>

int main(){
    Queuep q;
    
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(1);
    q.enqueue(10);
    q.enqueue(8);
    q.enqueue(20);

    while(!q.empty()){
        cout << q.front() << endl;
        q.deque();
    }
    return 0;
}