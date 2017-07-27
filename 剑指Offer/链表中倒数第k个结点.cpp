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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        
        // 判断输入合法性
        if(!pListHead || k <= 0)
            return nullptr;
        
        // 计算链表长度
        int length = 1;
        ListNode* temp = pListHead;
        while(temp->next)
        {
            length++;
            temp = temp->next;
        }
        
        // 判断输入合法性，k不能大于链表长度
        if(length < k)
            return nullptr;
        
        // 倒数第k个结点也是第(length-k)个节点
        int target = length - k;
        ListNode* result = pListHead;
        while(target--)
            result = result->next;
        
        return result;
        
        
    }
};