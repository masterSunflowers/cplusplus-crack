/*
 *  author:  masterSunflowers
 *  email:   lvdthieu@gmail.com
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // https://leetcode.com/problems/contains-duplicate/
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;
        for (auto num : nums)
        {
            if (s.count(num))
            {
                return true;
            }
            else
            {
                s.insert(num);
            }
        }
        return false;
    }

    // https://leetcode.com/problems/valid-anagram/
    bool isAnagram(string s, string t)
    {
        map<char, int> character;
        for (int i = 0; i < s.size(); i++)
            character[s[i]]++;
        for (int i = 0; i < t.size(); i++)
            character[t[i]]--;
        for (auto [k, v] : character)
        {
            if (v != 0)
                return false;
        }
        return true;
    }

    // https://leetcode.com/problems/two-sum/
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> places;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] * 2 == target && places.count(nums[i]) == 1)
                return {places[nums[i]], i};
            places[nums[i]] = i;
        }
        map<int, int>::iterator l = places.begin();
        map<int, int>::reverse_iterator r = places.rbegin();
        while (l->first != r->first)
        {
            int sum = l->first + r->first;
            if (sum == target)
                return {l->second, r->second};
            else if (sum > target)
                r++;
            else
                l++;
        }
        return {};
    }

    // https://leetcode.com/problems/group-anagrams/
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(s);
        }
        vector<vector<string>> res;
        for (auto [k, v] : mp)
        {
            res.push_back(v);
        }
        return res;
    }

    // https://leetcode.com/problems/top-k-frequent-elements/
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int num : nums)
            mp[num]++;
        vector<pair<int, int>> vect(mp.begin(), mp.end());
        sort(vect.begin(), vect.end(), cmp);
        int cnt = 0;
        vector<int> res;
        for (auto item : vect)
        {
            res.push_back(item.first);
            cnt++;
            if (cnt == k)
                break;
        }
        return res;
    }

    // https://leetcode.com/problems/encode-and-decode-strings/
    string charToHex(char c)
    {
        stringstream ss;
        ss << hex << setw(2) << setfill('0') << static_cast<int>(static_cast<unsigned char>(c));
        return ss.str();
    }
    string encode(vector<string> &strs)
    {
        string codes;
        for (auto str : strs)
        {
            string code = "";
            for (char c : str)
            {
                code += charToHex(c);
            }
            codes += code + '|';
        }
        return codes;
    }

    vector<string> decode(string s)
    {
        cout << s << '\n';
        vector<string> plaintexts;
        size_t old_pos = 0;
        size_t pos = s.find('|');
        while (pos != string::npos)
        {
            string plaintext = "";
            for (int i = old_pos; i < pos; i += 2)
            {
                unsigned long hexValue = std::stoul(s.substr(i, 2), nullptr, 16);
                plaintext += static_cast<char>(hexValue);
            }
            plaintexts.push_back(plaintext);
            old_pos = pos + 1;
            pos = s.find('|', old_pos);
        }
        return plaintexts;
    }
};

int main()
{
    Solution sol;
    vector<string> test = {"neet", "code", "love", "you"};
    string code = sol.encode(test);
    vector<string> plaintexts = sol.decode(code);
    for (auto plaintext : plaintexts)
    {
        cout << plaintext << ' ';
    }
    return 0;
}
