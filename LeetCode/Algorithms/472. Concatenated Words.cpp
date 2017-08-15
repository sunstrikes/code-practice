/*
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.
*/
class Solution {
public:
    struct node{
        bool is_end;
        node* next[26];
        node(){
            is_end = false;
            for(int i=0;i<26;i++){
                next[i] = nullptr;
            }
        }
    }
    int add_word(string &s, node* root){
        node* mov = root;
        for (int i=0;i<s.size();i++){
            int tmp = s[i] -'a';
            if (!mov->next[tmp]){
                mov->next[tmp] = new node();
            }
            mov = mov->next[tmp];
        }
        mov->is_end = true;
    }
    int search(string &s, node* root){
        node* mov = root;
        int count = 0;
        for(int i=0;i<s.size();i++){
            int tmp = s[i]- 'a';
            if(!mov->next[tmp]){
                return 0;
            }else if(mov->next[tmp]->is_end){
                count ++;
                mov = root;
            }else{
                mov = mov ->next[tmp];
            }
        }
        return count;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        node* root = new node();
        for(int i=0;i<words.size();i++){
            add_word(word[i], root);
        }
        
    }
};