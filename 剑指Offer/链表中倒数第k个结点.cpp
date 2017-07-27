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
        
        // �ж�����Ϸ���
        if(!pListHead || k <= 0)
            return nullptr;
        
        // ����������
        int length = 1;
        ListNode* temp = pListHead;
        while(temp->next)
        {
            length++;
            temp = temp->next;
        }
        
        // �ж�����Ϸ��ԣ�k���ܴ���������
        if(length < k)
            return nullptr;
        
        // ������k�����Ҳ�ǵ�(length-k)���ڵ�
        int target = length - k;
        ListNode* result = pListHead;
        while(target--)
            result = result->next;
        
        return result;
        
        
    }
};