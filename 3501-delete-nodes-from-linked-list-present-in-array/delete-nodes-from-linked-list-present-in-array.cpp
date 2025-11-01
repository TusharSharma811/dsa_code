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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st ;
        for(int i=0 ; i<nums.size() ; i++ ){
            st.insert(nums[i]) ;
        }


        ListNode* temp = new ListNode(-1) ;
        temp->next = head ;
        head = temp ;
        while(temp != NULL && temp->next != NULL ){
            if(st.contains(temp->next->val)){
                ListNode* tempPtr = temp->next ;
                temp->next = temp->next->next ;
                tempPtr->next = nullptr ;
                
            }
            else{
                temp = temp->next ;
            }
        }

        return head->next ;
    }
};