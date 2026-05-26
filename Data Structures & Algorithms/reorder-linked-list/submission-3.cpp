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

class Solution {
public:
    void reversal(ListNode* start , ListNode* end){
        ListNode*curr= start->next;
        ListNode* prev = nullptr;
        ListNode*temp = curr->next;
        ListNode*limit=end->next;
        while(temp!=limit){
            curr->next=prev;
            prev=curr;
            curr=temp;
            temp=temp->next;
        }
        curr->next=prev;
        start->next->next = limit;
        start->next=end;
        // ListNode* curr = start->next;
        // ListNode* prev = nullptr;
        // ListNode* limit = end->next; 
        // while (curr != limit) {
        //     ListNode* temp = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = temp;
        // }
        // start->next->next = limit; 
        // start->next = end;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode*slow = head;
        ListNode*fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if (fast->next == nullptr) {
                break;
            }
            if(fast->next->next== nullptr){
                fast=fast->next;
                break;
            }
        }
        reversal(slow,fast);
        ListNode*l1=head;
        ListNode*l2=l1->next;
        ListNode*r1= fast;
        ListNode*r2= r1->next;
        slow->next=nullptr;
        while(r1!=nullptr){
            l1->next=r1;
            if(l2==nullptr){
                break;
            }
            r1->next=l2;
            l1=l2;
            l2=l2->next;
            r1=r2;
            if (r2 != nullptr) {
                r2 = r2->next;
            }
        }
    }
};
