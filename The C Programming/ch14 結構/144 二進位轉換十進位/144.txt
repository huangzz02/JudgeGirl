#include <stdio.h>
#include <stdlib.h>
 
//getDecimalValue.h
struct ListNode{
    int val; // record 0 or 1
    struct ListNode *next; // point to next node
};
int getDecimalValue(struct ListNode* head);

//getDecimalValue.c
int getDecimalValue(struct ListNode* head) {
    int s = 0;
    while (head != NULL) {
        s = s * 2 + head->val;
        head = head->next;
    }
    return s;
}

//main.c
void Construct(struct ListNode* node, int length, int num) {
    int a;
    scanf("%d", &a);
    node->val = a;
 
    if(num >= length) {
        node->next = NULL;
        return;
    }
    node->next = (struct ListNode* )malloc(sizeof(struct ListNode));
    num++;
    Construct(node->next, length, num);
}
// ex: 1 1 0
// [1] -> [1] -> [0] -> NULL
 
int main() {
    struct ListNode *head;
    int n, a, length;
    head = (struct ListNode* )malloc(sizeof(struct ListNode));
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &length);
        Construct(head, length, 1);
        int ans = getDecimalValue(head);
        printf("%d\n", ans);
    }
}