#include <iostream>
#include<vector>
using namespace std;


#include<vector>
#include <unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include<cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> theStack = stack<char>();
        queue<char> theQueue = queue<char>();

        for (char c : s) {
            if (isalnum(c) ){
                char lowerCase = isalpha(c) * tolower(c) + !isalpha(c) * c;
                theStack.push(lowerCase);
                theQueue.push(lowerCase);
            }
        }
        

        while (theStack.size() != 0) {
            if (theStack.top() != theQueue.front()) {
                return false;
            }
            theStack.pop();
            theQueue.pop();

        }

        cout << s << " is s" << endl;;
        return true;
    }
};



int main() {
	cout << "Hello World!" << endl;
    string str = "race a car";
    int toUser = 333;
    Solution mySol;
    cout << mySol.isPalindrome(str);

    

 
}