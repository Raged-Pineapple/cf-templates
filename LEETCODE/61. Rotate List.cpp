/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 /*Steps to rotate a LL
 1.first make it like a circular LL,that is connect last node to head,because in the next step u will cut the LL in the middle,second half shouldnt get lost.
2.then write a fn to reach to the kth node,make the kth node's next the new head,point the kth node to NULL
*/

class Solution {
public:
    ListNode* findNode(ListNode* head,int k){
        int cnt = 1;
        ListNode* temp = head;
        while(temp->next!=NULL){
            if(cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)return NULL;
        int len = 1;
        ListNode*tail = head;
        while(tail->next!=NULL){
            len++;
            tail = tail->next;
        }
        if(k%len == 0) return head;
        k = k%len;
        tail->next = head;
        ListNode* kthNode = findNode(head,len-k);
        head = kthNode->next;
        kthNode->next = NULL;
        return head;
    }
};
