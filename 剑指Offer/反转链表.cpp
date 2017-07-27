/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {

        ListNode* pre = nullptr, *next = nullptr;
        ListNode* head = pHead;
        
        while(head)
        {
            // 先保存next
????????????next = head->next;
            // 后修改head->next指向pre
????????????head->next = pre;
            
????????????pre = head;
????????????head = next;
        }
        return pre;
    }
};