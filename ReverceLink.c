/*Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

Subscribe to see which companies asked this question
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode*  currNode = head;
    struct ListNode*  endNode  = head;
    struct ListNode** tempNode = NULL;
      

      
      while(n-- > 0 && endNode->next != NULL) {
      endNode = endNode->next;
      }

      while(endNode->next != NULL) {
        currNode = currNode->next;
        endNode = endNode->next;
      }
       
      if (endNode->next == NULL && n>=0) { 
      
        head = head->next;      
      }
      else if (currNode->next != NULL ) {
       tempNode = &currNode->next;
       currNode->next= (*tempNode)->next;
      }
     
      

    
    

    
    return head;
}