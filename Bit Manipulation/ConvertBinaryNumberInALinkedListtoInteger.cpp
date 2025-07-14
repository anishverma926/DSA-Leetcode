// Approach - 1

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
    int getDecimalValue(ListNode* head) {
        vector<int> temp;

        while(head){
            temp.push_back(head-> val);
            head = head -> next;
        }

        int n = temp.size();

        int ans = 0;

        if(n == 1 && temp[0] == 0)
        return 0;

        for(int i = 0; i < n; i++){
            if(temp[i] == 1){
                int idx = abs(n - 1 - i);
                ans += pow(2, idx); 
            }
        }
        return ans;
    }
};


// Approach - 2

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;

        while(head){
            ans = ans | (head -> val);
            ans = ans<<1;
            head = head -> next;
        }
        
        return ans / 2;
    }
};

// Approach - 3

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;

        while(head){
            ans = (ans << 1) | (head -> val);
            head = head -> next;
        }
        
        return ans;
    }
};