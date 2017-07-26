/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
  
  vector<int> array;
  vector<int>& printListFromTailToHead(struct ListNode* head) {
  
    if(head) 
    {
      if(head->next) 
      {
        array = printListFromTailToHead(head->next);
      }
      array.push_back(head->val);
    }
    return array;
  }
};