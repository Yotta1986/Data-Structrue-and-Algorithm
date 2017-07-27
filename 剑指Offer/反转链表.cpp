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
            // �ȱ���next
????????????next = head->next;
            // ���޸�head->nextָ��pre
????????????head->next = pre;
            
????????????pre = head;
????????????head = next;
        }
        return pre;
    }
};