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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head ;
        ListNode* prev = dummy ;
        int k=1 ; 
        while(k<left && prev != nullptr){
            prev = prev->next ;
            k++ ;
        }
        ListNode* curr = prev->next ;
        int total = right-left ;
        while(total > 0 ){
            ListNode *temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
            total-- ;
        }

        return dummy->next ;
    }
};