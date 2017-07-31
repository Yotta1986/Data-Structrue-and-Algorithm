/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    /*
    �����������ʱ����ԭ����nextָ��ָ���Ӧ�½�㣬�½���nextָ��ָ����һ��ԭ��㣬�Դ����ƣ��γ�֮���ι���.
    Ȼ�󣬾Ϳ����ȸ����������randomָ��.
    �ٽ��next����������nextָ��.
    */
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
            return nullptr;
        RandomListNode* newHead = new RandomListNode(pHead->label);
        RandomListNode *p1 = pHead, *p2 = newHead;
        
        while(p1)
        {
            // link them. Make p2 equals to p1, and insert p2 between p1 and p1->next
            RandomListNode* temp = p1->next;
            p2->next = temp;
            p1->next = p2;
            
            // next
            p1 = temp;
            if(temp)
                p2 = new RandomListNode(temp->label);
            else
                p2 = nullptr;
        }
        
        p1 = pHead; p2=newHead;
        while(p1)
        {
            // set random
            if(p1->random)
                p2->random = p1->random->next;
            else
                p2->random  = nullptr;
            
            // next
            p1 = p2->next;
            if(p1)
                p2 = p1->next;
            else
                p2 = nullptr;
        }
        
        p1 = pHead; p2=newHead;
        while(p1)
        {
            // depart. set next
            p1->next = p2->next;
            if(p1->next)
                p2->next = p1->next->next;
            else p2->next = nullptr;
            
            // next
            p1 = p1->next;
            p2 = p2->next;
            
        }
        
        return newHead;
    }
};