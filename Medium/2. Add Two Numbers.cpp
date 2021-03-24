// https://leetcode.com/problems/add-two-numbers/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *head = new ListNode();
        
        int tmp = l1->val + l2->val;
        int carry = tmp > 9 ? 1: 0;
        head->val = tmp % 10;
        
        struct ListNode *now = head;
        while (l1->next && l2->next){
            l1 = l1->next;
            l2 = l2->next;
            tmp = l1->val + l2->val + carry;
            carry = tmp > 9 ? 1: 0;
            struct ListNode* newNode = new ListNode(tmp % 10);
            now->next = newNode;
            now = newNode;
        }
        while (l1->next){
            l1 = l1->next;
            tmp = l1->val + carry;
            carry = tmp > 9 ? 1: 0;
            struct ListNode* newNode = new ListNode(tmp % 10);
            now->next = newNode;
            now = newNode;
        }
        while (l2->next){
            l2 = l2->next;
            tmp = l2->val + carry;
            carry = tmp > 9 ? 1: 0;
            struct ListNode* newNode = new ListNode(tmp % 10);
            now->next = newNode;
            now = newNode;
        }
        if (carry){
            now->next = new ListNode(1);;
            now->val = now->val % 10;
        }
        return head;
    }
};
/**
* Runtime: 20 ms, faster than 95.53% of C++ online submissions for Add Two Numbers.
* Memory Usage: 71.1 MB, less than 67.58% of C++ online submissions for Add Two Numbers.
*/