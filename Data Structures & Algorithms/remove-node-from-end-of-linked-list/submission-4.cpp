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
    ListNode* reversal(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* curr=head;
        ListNode* prev= nullptr;
        while(curr){
            ListNode*temp= curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        head=reversal(head);
        ListNode*temp=head;
        if (n == 1) {
            ListNode* node = head;
            head = head->next;
            delete node;
        }
        else {
            ListNode* temp = head;
            int k = n - 2; 
            while(k > 0 && temp != nullptr){
                temp = temp->next;
                k--;
            }
            if(temp != nullptr && temp->next != nullptr){
                ListNode* node = temp->next;
                temp->next = temp->next->next;
                delete node;
            }
        }
        head=reversal(head);
        return head;
    }

};
