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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode() ;
        ListNode* mint = dummy ;
        ListNode* maxt = dummy ;
        ListNode* curr = head ;
        while(curr!=NULL ){
            ListNode* temp = new ListNode(curr->val) ;
            if(temp->val < x){
                temp->next = mint->next ;
                mint->next = temp ;
                if(mint == maxt){
                    maxt = maxt->next ;
                }

                mint=mint->next ;
                
            }
            else{
                maxt->next = temp ;
                maxt = maxt->next ;
            }

            curr = curr->next ;
        }

        return dummy->next ;
    }
};