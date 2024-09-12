/**
 *    author:  masterSunflowers
 *    created: 
 *    note:
**/
#include<bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; 


class Solution {
public:
    /*
    *   date:    06/09/2024
    *   problem: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
    */
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s;
        for (auto num : nums) {
            s.insert(num);
        }
        ListNode* cur = head;
        ListNode* before = new ListNode();
        ListNode* tmp = before;
        before->next = head;
        while (cur) {
            if (s.count(cur->val)) {
                if (cur == head) {
                    head = cur->next;
                }
                before->next = cur->next;
                cur = cur->next;
            } else {
                cur = cur->next;
                before = before->next;
            }   
        }
        delete tmp;
        return head;
    }

    /*
    *   date:    07/09/2024 
    *   problem: https://leetcode.com/problems/linked-list-in-binary-tree/
    */
    bool isPathFromNode(ListNode* head, TreeNode* node) {
        if (!head) {
            return true;
        }
        if (!node) {
            return false;
        }
        if (head->val == node->val) {
            return isPathFromNode(head->next, node->left) || isPathFromNode(head->next, node->right);
        } else {
            return false;
        }
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (isPathFromNode(head, cur)) return true;
            q.push(cur->left);
            q.push(cur->right);
        }
        return false;
    }

    /*
    *   date:    08/09/2024
    *   problem: https://leetcode.com/problems/split-linked-list-in-parts/
    */
   vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        res.push_back(head);
        int lengthList = 0;
        ListNode* cur = head;
        while (cur) {
            lengthList++;
            cur = cur->next;
        }
        int mod = lengthList % k;
        int div = lengthList / k;
        cur = head;
        int cnt;

        for (int i = 0; i < k - 1; i++) {
            cnt = 0;
            if (i < mod) {
                while (cnt < div) {
                    cnt++;
                    cur = cur->next;
                }
                res.push_back(cur->next);
                cur->next = nullptr;
            } else {
                while (cnt < div - 1) {
                    cnt++;
                    cur = cur->next;
                }
                if (!cur) {
                    res.push_back(nullptr);
                } else {
                    res.push_back(cur->next);
                    cur->next = nullptr;
                }
            }
            cur = res.back();
        }
        return res;
    }

    /*
    *   date:    09/09/2024
    *   problem: https://leetcode.com/problems/spiral-matrix-iv/
    */
   vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int top_row = 0, bot_row = m - 1, left_col = 0, right_col = n - 1;
        while (head) {
            for (int j = left_col; j <= right_col && head; j++) {
                res[top_row][j] = head->val;
                head = head->next;
            }
            top_row++;
            for (int i = top_row; i <= bot_row && head; i++) {
                res[i][right_col] = head->val;
                head = head->next;
            }
            right_col--;
            for (int j = right_col; j >= left_col && head; j--) {
                res[bot_row][j] = head->val;
                head = head->next;
            }
            bot_row--;
            for (int i = bot_row; i >= top_row && head; i--) {
                res[i][left_col] = head->val;
                head = head->next;
            }
            left_col++;
        }
        
        return res;
    }

    /*
    *   date:    10/09/2024
    *   problem: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
    */
   int gcd(int a, int b) {
        while (a && b) {
            if (a > b) a %= b;
            else b %= a;
        }
        return a ^ b;
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while (cur) {
            if (cur->next) {
                ListNode* new_node = new ListNode(gcd(cur->next->val, cur->val), cur->next);
                cur->next = new_node;
                cur = new_node->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
    /*
    *   date:    11/09/2024
    *   problem: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
    */
    int minBitFlips(int start, int goal) {
        bitset<32> binary(start ^ goal);
        return binary.count();
    }
};