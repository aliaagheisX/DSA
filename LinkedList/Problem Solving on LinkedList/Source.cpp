#include <vector>
using namespace std;
/*
    1-Add Two Numbers (Medium) : https://leetcode.com/problems/add-two-numbers/ (loop and recursion) solution
    2-Remove Nth Node From End of List (Medium) : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
    3-Merge Two Sorted Lists (Easy) : https://leetcode.com/problems/merge-two-sorted-lists/ (loop and recursion) solution
    4-Merge k Sorted Lists (Hard) : https://leetcode.com/problems/merge-k-sorted-lists/ brute force solution
    5-Swap Nodes in Pairs (Medium) : https://leetcode.com/problems/swap-nodes-in-pairs/ (loop and recursion) 
    6-Reverse Linked List (Easy) : https://leetcode.com/problems/reverse-linked-list/ recursion solution
*/



/*Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    /*ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = new ListNode;
        ListNode* temp = result;

        while (l1 != nullptr || l2 != nullptr) {
            int q = l1 == nullptr ? 0 : l1->val;
            int v = l2 == nullptr ? 0 : l2->val;

            int val = q + v + carry;

            carry = val / 10;
            val = val % 10;

            temp->next = new ListNode(val);


            temp = temp->next;

            if(l1 != nullptr)
                l1 = l1->next;

            if (l2 != nullptr)
            l2 = l2->next;
        }



        while (carry) {
            temp->next = new ListNode(carry % 10);
            carry = carry / 10;
            temp = temp->next;
        }

        return result->next;

    }*/
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carr = 0) {
        if (l1 == NULL && l2 == NULL && carr == 0) return NULL;


        int sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + carr;
        carr = sum / 10;
        sum %= 10;

        ListNode* r = new ListNode(sum);

        r->next = addTwoNumbers(((l1 == NULL) ? NULL : l1->next), ((l2 == NULL) ? NULL : l2->next), carr);


        return r;
    }


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*get size*/
        int size = 0;
        ListNode* temp = head;
        while (temp != nullptr) temp = temp->next, size++;

        n = size - n;


        if (n == 0) {
            temp = head->next;
            delete head;
            return temp;
        }


        ListNode* prev = head;
        for (int i = 0; i < n - 1; i++) prev = prev->next;

        temp = prev->next;

        prev->next = temp->next;

        delete temp;

        return head;
    }

    /*ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* Result = new ListNode();
        ListNode* temp = Result;

        while (list1 != nullptr || list2 != nullptr) {
            ListNode** toChange ;

            if (list1 != nullptr && list2 != nullptr){
                if (list1->val <= list2->val) toChange = &list1;
                else toChange = &list2;
            }
            else if (list1 != nullptr) toChange = &list1;
            else toChange = &list2;

            temp->next = new ListNode((**toChange).val);

            *toChange = (**toChange).next;
            temp = temp->next;

        }
        return Result;

    }*/
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;

        }

    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = new ListNode();
        ListNode* temp = result;

        while (!Empty(lists)) {
            int min = INT_MAX;
            ListNode** toChange = nullptr;

            for (auto l : lists) {
                if (l->val < min) {
                    min = l->val;
                    toChange = &l;
                }
            }

            temp->next = new ListNode(min);
            temp = temp->next;
            *toChange = (**toChange).next;
        }

        return result->next;
    }
    bool Empty(vector<ListNode*>& lists) {

        for (auto l : lists)
            if (l != nullptr) return false;
        return true;

    } // for 4th Q


    /*ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* temp = head;
        ListNode* Nexttemp = head->next;

        head->next = Nexttemp->next;

        Nexttemp->next = head;

        head = Nexttemp;

        ListNode* PrevTemp = head->next;

        while (PrevTemp != NULL && PrevTemp->next != NULL && PrevTemp->next->next != NULL) {
            temp = PrevTemp->next;
            Nexttemp = temp->next;

            PrevTemp->next = Nexttemp;
            temp->next = Nexttemp->next;
            Nexttemp->next = temp;

            PrevTemp = PrevTemp->next->next;
        } 
        return head;
        
    }*/
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* Next = head->next;
        head->next = swapPairs(head->next->next);
        Next->next = head;
        return Next;
    }


    ListNode* reverseList(ListNode* head) {

        if (head == NULL || head->next == NULL) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }


};

int main() {

    ListNode l1(4);
    ListNode l2(3, &l1);
    ListNode l3(2, &l2);
    ListNode l4(1, &l3);
    ListNode l5(5, &l4);
    ListNode l6(6, &l5);
    ListNode l7(7, &l6);


    Solution s;
    s.swapPairs(&l7);
}