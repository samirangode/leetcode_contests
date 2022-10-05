struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* a_1;
        ListNode* b_after;
        ListNode* list2_end;
        ListNode* nextPtr = list1;
        int i = 0;
        if(a==0) a_1 = list1;
        while(nextPtr!=nullptr){
            if(i == (a - 1)) a_1 = nextPtr;
            if(i == (b+1)) b_after = nextPtr;
            nextPtr = nextPtr->next;
            i++;
        }
        nextPtr = list2;
        while(nextPtr->next!=nullptr){
            nextPtr = nextPtr->next;
        }
        list2_end = nextPtr;
        a_1->next = list2;
        list2_end->next = b_after;
        return list1;
                
    }
};
