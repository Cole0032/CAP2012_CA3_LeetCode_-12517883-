#include <string>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentStr = "";
        int currentNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                // Accumulate multi-digit numbers (e.g., "12[a]")
                currentNum = currentNum * 10 + (c - '0');
            } 
            else if (c == '[') {
                // Save current context before entering nested bracket
                countStack.push(currentNum);
                stringStack.push(currentStr);
                
                // Reset for the inner substring
                currentNum = 0;
                currentStr = "";
            } 
            else if (c == ']') {
                // Retrieve the repeat count and outer string prefix
                int repeatTimes = countStack.top();
                countStack.pop();
                
                string prevStr = stringStack.top();
                stringStack.pop();
                
                // Append repeated currentStr to the outer prefix
                for (int i = 0; i < repeatTimes; ++i) {
                    prevStr += currentStr;
                }
                currentStr = prevStr;
            } 
            else {
                // Regular lowercase letter
                currentStr += c;
            }
        }

        return currentStr;
    }
};
