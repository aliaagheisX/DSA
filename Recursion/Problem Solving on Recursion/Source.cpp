#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
    1-Add Two Numbers (Medium) : https://leetcode.com/problems/add-two-numbers/ 
    3-Merge Two Sorted Lists (Easy) : https://leetcode.com/problems/merge-two-sorted-lists/ 
    5-Swap Nodes in Pairs (Medium) : https://leetcode.com/problems/swap-nodes-in-pairs/  
    6-Reverse Linked List (Easy) : https://leetcode.com/problems/reverse-linked-list/ 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carr = 0) {
        if (l1 == NULL && l2 == NULL && carr == 0) return NULL;


        int sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + carr;
        carr = sum / 10;
        sum %= 10;

        ListNode* r = new ListNode(sum);

        r->next = addTwoNumbers(((l1 == NULL) ? NULL : l1->next), ((l2 == NULL) ? NULL : l2->next), carr);


        return r;
    }

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

    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxArea = 0;
        while (i < j) {
            int min = height[i] < height[j] ? height[i] : height[j];
            maxArea = min * (j - i) > maxArea ? min * (j - i) : maxArea;

            if (height[i] < height[j])  i++;
            else j--;
        }
        return maxArea;
    }
    bool isMatch(string s, string p,int i = -100,int j = -100) {
        if(i == -100 && j == -100) {
            i = s.size() - 1;
            j = p.size() - 1;
        }
        if (i < 0 && j < 0) return true;
        if (j < 0) return false;
        if (i < 0) {
            if (p[j] == '*') return true;
            return false;
        }
        if (p[j] == '.' || p[j] == s[i]) return isMatch(s, p, i - 1, j - 1);
        if (p[j] == '*') {
            if (isMatch(s, p, i - 1, j)) return true;
            else return isMatch(s, p, i, j - 2);
        }
        return false;
    }

};

int main() {

    string s = "mississippi";
    string p = "mis*is*p*.";
    Solution sol;
    cout << sol.isMatch(s, p);

}