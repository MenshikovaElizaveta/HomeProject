#include <stdio.h>
#include <stdlib.h>


struct Node {
    int a;
    struct Node* next;
};

struct Node* mrg(struct Node* a, struct Node* b) {
    if (!a) return b;
    if (!b) return a;
    struct Node* newlist = a;
    struct Node* cur1 = a;
    struct Node* cur2 = b;
    
    while (cur1 && cur2) {
        struct Node* tmp1 = cur1->next;
        struct Node* tmp2 = cur2->next;
        
        cur1->next = cur2;
        if (tmp1) cur2->next = tmp1;
        
        cur1 = tmp1;
        cur2 = tmp2;
    }
    
    return newlist;
}


int main() {
    struct Node a1 = {1, NULL};
    struct Node a2 = {2, NULL};
    struct Node a3 = {3, NULL};
    a1.next = &a2;
    a2.next = &a3;
    
    struct Node b1 = {4, NULL};
    struct Node b2 = {5, NULL};
    b1.next = &b2;
    struct Node* res = mrg(&a1, &b1);
    
    while (res) {
        printf("%d ", res->a);
        res = res->next;
    }
    
    return 0;
}
