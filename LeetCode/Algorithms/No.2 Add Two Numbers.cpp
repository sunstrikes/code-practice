/*
Problem:
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

Language:C++
Author:SunStrike
Date:2015/9/6
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        int add = 0;
        while(t1&&t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        int status =0;
        if(t2!=NULL){
            t1=l2;
            t2=l1;
            status = 2;
        }else{
            t1=l1;
            t2=l2;
            status = 1;
        }
        ListNode *pre =NULL;
        while(t1){
            int value ;
            if(t2!=NULL){
            value= t1->val + t2-> val + add;
            }else{
            value=t1->val+add;
            }            add = 0;
            if((value)>9){
                add =1;
                t1->val = value - 10;
            }else{
              t1->val = value;
            }
            pre = t1;
            t1=t1->next;
            if(t2!=NULL)
              t2=t2->next;
        }
        if(add!=0){
            if(t1==NULL)
             pre->next = new ListNode(1);
        }
        return status==1?l1:l2;
    }
};
