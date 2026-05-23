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
    bool hasCycle(ListNode* head) {
        // with no extra space;
        ListNode* slow=head;
        ListNode* fast= head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }

        //  APPROACH "with extra space"
        // unordered_set<int>visited;
        // ListNode*curr=head;
        // while(curr){
        //     if(visted.find(curr) != visited.end()){
        //         return true;
        //     }
        //     visited.insert(curr);
        //     curr=curr->next;
        // }
        // return false;
    return false;
    }
};
