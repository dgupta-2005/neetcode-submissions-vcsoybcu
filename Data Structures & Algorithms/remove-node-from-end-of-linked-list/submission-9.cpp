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
// reversal function code->
    // ListNode* reversal(ListNode* head){
    //     if(head==nullptr || head->next==nullptr){
    //         return head;
    //     }
    //     ListNode* curr=head;
    //     ListNode* prev= nullptr;
    //     while(curr){
    //         ListNode*temp= curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=temp;
    //     }
    //     return prev;
    // }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        // primary apporach ->
        // reverse the linked list -> delete the nth node -> again reverse the linked list 
        // head=reversal(head);
        // ListNode*temp=head;
        // if (n == 1) {
        //     ListNode* node = head;
        //     head = head->next;
        //     delete node;
        // }
        // else {
        //     ListNode* temp = head;
        //     int k = n - 2; 
        //     while(k > 0 && temp != nullptr){
        //         temp = temp->next;
        //         k--;
        //     }
        //     if(temp != nullptr && temp->next != nullptr){
        //         ListNode* node = temp->next;
        //         temp->next = temp->next->next;
        //         delete node;
        //     }
        // }
        // head=reversal(head);


        // 2nd approch 
        // use of fixed window haiving length n -> shift (length should be constant) it till we reach the
        // end of the list -> delete the next node of the first pointer of the window 
        ListNode* temp1=head;
        ListNode* temp2=temp1;
        while(n>0){
            temp2=temp2->next;
            n--;
        }
        if(temp2==nullptr){
            ListNode* old_head=head;
            head= head->next;
            delete old_head;
            return head;
        }
        while(temp2->next!=nullptr){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        ListNode*nodeToDelete=temp1->next;
        temp1->next=temp1->next->next;
        delete nodeToDelete;
        return head;
    }

};
