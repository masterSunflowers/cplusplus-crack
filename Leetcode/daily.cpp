/*
 *  author:  masterSunflowers
 *  email:   lvdthieu@gmail.com
 */
#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    /*
     *   date:    06/09/24
     *   problem: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
     */
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        set<int> s;
        for (auto num : nums)
        {
            s.insert(num);
        }
        ListNode *cur = head;
        ListNode *before = new ListNode();
        ListNode *tmp = before;
        before->next = head;
        while (cur)
        {
            if (s.count(cur->val))
            {
                if (cur == head)
                {
                    head = cur->next;
                }
                before->next = cur->next;
                cur = cur->next;
            }
            else
            {
                cur = cur->next;
                before = before->next;
            }
        }
        delete tmp;
        return head;
    }

    /*
     *   date:    07/09/24
     *   problem: https://leetcode.com/problems/linked-list-in-binary-tree/
     */
    bool isPathFromNode(ListNode *head, TreeNode *node)
    {
        if (!head)
        {
            return true;
        }
        if (!node)
        {
            return false;
        }
        if (head->val == node->val)
        {
            return isPathFromNode(head->next, node->left) || isPathFromNode(head->next, node->right);
        }
        else
        {
            return false;
        }
    }
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *cur;
        while (!q.empty())
        {
            cur = q.front();
            q.pop();
            if (isPathFromNode(head, cur))
                return true;
            q.push(cur->left);
            q.push(cur->right);
        }
        return false;
    }

    /*
     *   date:    08/09/24
     *   problem: https://leetcode.com/problems/split-linked-list-in-parts/
     */
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> res;
        res.push_back(head);
        int lengthList = 0;
        ListNode *cur = head;
        while (cur)
        {
            lengthList++;
            cur = cur->next;
        }
        int mod = lengthList % k;
        int div = lengthList / k;
        cur = head;
        int cnt;

        for (int i = 0; i < k - 1; i++)
        {
            cnt = 0;
            if (i < mod)
            {
                while (cnt < div)
                {
                    cnt++;
                    cur = cur->next;
                }
                res.push_back(cur->next);
                cur->next = nullptr;
            }
            else
            {
                while (cnt < div - 1)
                {
                    cnt++;
                    cur = cur->next;
                }
                if (!cur)
                {
                    res.push_back(nullptr);
                }
                else
                {
                    res.push_back(cur->next);
                    cur->next = nullptr;
                }
            }
            cur = res.back();
        }
        return res;
    }

    /*
     *   date:    09/09/24
     *   problem: https://leetcode.com/problems/spiral-matrix-iv/
     */
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int top_row = 0, bot_row = m - 1, left_col = 0, right_col = n - 1;
        while (head)
        {
            for (int j = left_col; j <= right_col && head; j++)
            {
                res[top_row][j] = head->val;
                head = head->next;
            }
            top_row++;
            for (int i = top_row; i <= bot_row && head; i++)
            {
                res[i][right_col] = head->val;
                head = head->next;
            }
            right_col--;
            for (int j = right_col; j >= left_col && head; j--)
            {
                res[bot_row][j] = head->val;
                head = head->next;
            }
            bot_row--;
            for (int i = bot_row; i >= top_row && head; i--)
            {
                res[i][left_col] = head->val;
                head = head->next;
            }
            left_col++;
        }

        return res;
    }

    /*
     *   date:    10/09/24
     *   problem: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
     */
    int gcd(int a, int b)
    {
        while (a && b)
        {
            if (a > b)
                a %= b;
            else
                b %= a;
        }
        return a ^ b;
    }

    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *cur = head;
        while (cur)
        {
            if (cur->next)
            {
                ListNode *new_node = new ListNode(gcd(cur->next->val, cur->val), cur->next);
                cur->next = new_node;
                cur = new_node->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
    /*
     *   date:    11/09/24
     *   problem: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
     */
    int minBitFlips(int start, int goal)
    {
        bitset<32> binary(start ^ goal);
        return binary.count();
    }

    /*
     *   date:    12/09/24
     *   problem: https://leetcode.com/problems/count-the-number-of-consistent-strings/
     */
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        unordered_map<char, bool> dic;
        for (char c : allowed)
        {
            dic[c] = true;
        }
        int res = 0;
        for (auto word : words)
        {
            bool flag = true;
            for (char c : word)
            {
                if (!dic.count(c))
                {
                    flag = false;
                    break;
                }
            }
            res += flag;
        }
        return res;
    }

    /*
     *   date:    13/09/24
     *   problem: https://leetcode.com/problems/xor-queries-of-a-subarray/
     */
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> xorArr(arr.size());
        int tmp = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            tmp ^= arr[i];
            xorArr[i] = tmp;
        }
        vector<int> res;
        for (auto query : queries)
        {
            if (query[0] == 0)
            {
                res.push_back(xorArr[query[1]]);
            }
            else
            {
                res.push_back(xorArr[query[1]] ^ xorArr[query[0] - 1]);
            }
        }
        return res;
    }

    /*
     *   date:    14/09/24
     *   problem: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
     */
    int longestSubarray(vector<int> &nums)
    {
        // Find the maximum value in the array
        int max_value = *max_element(nums.begin(), nums.end());

        // Initialize the length of the longest subarray with the maximum value
        int longest = 1;

        // Initialize the index for iterating through the array
        int i = 0;

        // Iterate through the array
        while (i < nums.size())
        {
            // If the current element is the maximum value, find the length of the subarray
            if (nums[i] == max_value)
            {
                int cnt = 1;
                int j = i + 1;

                // Count the length of the subarray with the maximum value
                while (j < nums.size() && nums[j] == max_value)
                    if (nums[i] == max_value)
                    {
                        int cnt = 1;
                        int j = i + 1;
                        while (j < nums.size() && nums[j] == max_value)
                        {
                            j++;
                            cnt++;
                        }
                        longest = max(longest, cnt);
                        i = j;
                    }
                    else
                    {
                        i++;
                    }
            }
        }
        return longest;
    }
    /*
     *   date:    16/09/24
     *   problem: https://leetcode.com/problems/minimum-time-difference/
     */
    bool cmp(string &a, string &b)
    {
        int a_hour = stoi(a.substr(0, 2));
        int a_minute = stoi(a.substr(3, 2));
        int b_hour = stoi(b.substr(0, 2));
        int b_minute = stoi(b.substr(3, 2));
        if (a_hour > b_hour)
            return false;
        else if (a_hour < b_hour)
            return true;
        else
            return a_minute < b_minute;
    }
    int diff(string &a, string &b)
    {
        int a_hour = stoi(a.substr(0, 2));
        int a_minute = stoi(a.substr(3, 2));
        int b_hour = stoi(b.substr(0, 2));
        int b_minute = stoi(b.substr(3, 2));
        int diff = (b_hour - a_hour) * 60 + (b_minute - a_minute);
        return diff;
    }
    int findMinDifference(vector<string> &timePoints)
    {
        sort(timePoints.begin(), timePoints.end(), cmp);
        int minDiff = 10e5;
        for (int i = 0; i < timePoints.size() - 1; i++)
        {
            // cout << timePoints[i] << ' ';
            minDiff = min(minDiff, diff(timePoints[i], timePoints[i + 1]));
        }
        // cout << diff(timePoints[timePoints.size() - 1], timePoints[0]) + 24 * 60;
        minDiff = min(minDiff, diff(timePoints[timePoints.size() - 1], timePoints[0]) + 24 * 60);
        return minDiff;
    }
    /*
     *   date:    17/09/24
     *   problem: https://leetcode.com/problems/uncommon-words-from-two-sentences/
     */
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> mp;
        size_t old_pos = 0;
        size_t pos = s1.find(' ');
        while (pos != string::npos)
        {
            mp[s1.substr(old_pos, pos - old_pos)]++;
            old_pos = pos + 1;
            pos = s1.find(' ', pos + 1);
        }
        mp[s1.substr(old_pos, s1.size() - old_pos + 1)]++;
        old_pos = 0;
        pos = s2.find(' ');
        while (pos != string::npos)
        {
            mp[s2.substr(old_pos, pos - old_pos)]++;
            old_pos = pos + 1;
            pos = s2.find(' ', pos + 1);
        }
        mp[s2.substr(old_pos, s2.size() - old_pos + 1)]++;
        vector<string> res;
        for (auto [k, v] : mp)
        {
            // cout << k << ' ' << v << '\n';
            if (v == 1)
                res.push_back(k);
        }
        return res;
    }
    /*
    *   date:    01/12/24
    *   problem: https://leetcode.com/problems/check-if-n-and-its-double-exist/
    */
    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] * 2 == arr[j] || arr[j] * 2 == arr[i]) {
                    return true;
                }
            }
        }
        return false;
    }
    /*
    *   date:    02/12/24
    *   problem: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
    */
    int isPrefixOfWord(string sentence, string searchWord) {
        string s;
        stringstream ss(sentence);
        vector<string> words;
        while (getline(ss, s, ' ')) {
            words.push_back(s);
        }
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(searchWord) == 0) {
                return i + 1;
            }
        }
        return -1;
    }
    /*
    *   date:    03/12/24
    *   problem: https://leetcode.com/problems/adding-spaces-to-a-string/
    */
    string addSpaces(string s, vector<int>& spaces) {
        string res = s.substr(0, spaces[0]) + " ";
        for (int i = 1; i < spaces.size(); i++) {
            res += s.substr(spaces[i - 1], spaces[i] - spaces[i - 1]) + " ";
        }
        res += s.substr(spaces.back(), s.size() - spaces.back());
        return res;
    }
    /*
    *   date:    04/12/24
    *   problem: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/
    */
    char next_char(char c) {
        return char((int(c) - int('a') + 1) % 26 + int('a'));
    }
    bool canMakeSubsequence(string str1, string str2) {
        if (str2.length() > str1.length()) return false;
        int i = 0, j = 0;
        while (j < str2.length() && i < str1.length()) {
            cout << i << j << endl;
            while (str1[i] != str2[j] && next_char(str1[i]) != str2[j] && i < str1.length()) {
                i++;
            }
            if (i == str1.length()) continue;
            i++;
            j++;
        }
        
        return j == str2.length();
    }

    // More clean code
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        for (; i < str1.length() && j < str2.length();) {
            char c = str1[i] == 'z' ? 'a' : str1[i] + 1;
            if (str1[i] == str2[j] || c == str2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return j == str2.length();
    }
};