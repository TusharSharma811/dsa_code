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
    ListNode* reverseList(ListNode *head)
{
   
   ListNode* temp = head;  
   ListNode* prev = NULL;  
   while(temp != NULL){  
       ListNode* front = temp->next;  
       temp->next = prev;  
       prev = temp;  
       temp = front; 
   }
   
   return prev;  
}

    ListNode* getkthnode(ListNode* head , int k ){
        k=k-1 ;
        while(head != NULL && k>0){
            k-- ;
            head = head->next ;
        }
        return head ;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head ;
        ListNode* knode = NULL ;
        ListNode* ktail = NULL ;
        while(temp != NULL){
            knode = getkthnode(temp , k) ;
            if(knode== NULL){
                if(ktail != NULL){
                    ktail->next = temp ;
                }
                break ;
            }
            ListNode* nextNode = knode -> next;
            knode->next = NULL ;
            reverseList(temp );
            if(temp == head){
                head = knode ;
            }else{
                ktail->next = knode ;
            }
            ktail = temp ;
            temp =  nextNode ;
        }
        return head ;
         
    }
};