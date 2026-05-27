/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>copyMap;
        copyMap[nullptr]=nullptr;
        Node*curr=head;
        while(curr!=nullptr){
            Node*copy=new Node(curr->val);
            copyMap[curr]=copy;
            curr=curr->next;
        }
        curr=head;
        while(curr!=nullptr){
        Node* copy=copyMap[curr];
        copy->next=copyMap[curr->next];
        copy->random=copyMap[curr->random];
        curr=curr->next;
        }
        return copyMap[head];
    }
};
