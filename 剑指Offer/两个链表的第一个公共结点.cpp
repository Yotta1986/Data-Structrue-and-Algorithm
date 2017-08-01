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
    /*
    �ҳ�2������ĳ��ȣ�Ȼ���ó���������������ĳ��ȲȻ����һ����
    ����Ϊ2�������ù�����β����
    */
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        
        if(!pHead1 || !pHead2) return nullptr;
        
        int length1 = getListLength(pHead1);
        int length2 = getListLength(pHead2);
        int diff = length1 - length2;
        ListNode *p1 = pHead1, *p2 = pHead2;
        if(diff > 0)
        {
            while(diff--)
            	p1 = p1->next;
        }
        else
        {
            while(diff++)
            	p2 = p2->next;
        }
        
        while(p1 && p2)
        {
            if(p1 == p2)
                return p1;
            else
            {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        return nullptr;
    }
    
    
    int getListLength(ListNode* pHead)
    {
        if(!pHead) return 0;
        int i = 1;
        while(pHead)
        {
            pHead = pHead->next;
            i++;
        }
        return i;
    }
    
};