#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;
/*
20. Valid Parentheses (easy) : https://leetcode.com/problems/valid-parentheses/
32. Longest Valid Parentheses (Hard) : https://leetcode.com/problems/longest-valid-parentheses/ 
42. Trapping Rain Water (Hard) : https://leetcode.com/problems/trapping-rain-water/
71. Simplify Path (Medium) : https://leetcode.com/problems/simplify-path/
*/

class Solution {
public:
    bool isValid(string s) {
        string open = "({[";
        string close = ")}]";
        stack<char> str;
        for (int i = 0; i < s.size(); i++) {
            int index = open.find(s[i]);
            if (index != -1) str.push(s[i]);//open parantethesis
            else {
                if (str.empty() || str.top() != open[close.find(s[i])] ) return false;
                str.pop();
            }
        }
        return str.empty();
    }

    int longestValidParentheses(string s) {
        stack<int> st;
        int len = 0, maxLen = 0;
        st.push(-1);
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else {
                st.pop();
                if (st.empty()) st.push(i);
                else {
                    len = i - st.top();
                    if ( len > maxLen) maxLen = len;
                }
            }
        }
        return maxLen;
    }

    int trap(vector<int>& height) {
        stack<int> st;
        int curr = 0; int ans = 0;
        while (curr < height.size()) {
            while (!st.empty() && height[curr] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                int dist = curr - st.top() - 1;
                int h = min(height[curr], height[st.top()]) - height[top];
                ans += dist * h;
            }
            st.push(curr++);
        }
        return ans;
    }

    string simplifyPath(string path) {
        stack<string>dir;
        string name = "";
        for (auto i : path) {
            if (i == '/' && name.size()) {
                if (name == ".." && dir.size()) dir.pop();
                else if (name != "." && name != "..") dir.push(name);
                name = "";
            }
            else if(i != '/') name += i;
        }
        if (name.size()) {
            if (name == ".." && dir.size()) dir.pop();
            else if (name != "." && name != "..") dir.push(name);
            name = "";
        }
        if (dir.empty()) return "/";
        while (dir.size()) {
            string top = dir.top();
            dir.pop();
            name = '/' + top + name;
        }
        return name;
    }
};

int main() {
	return 0;
}