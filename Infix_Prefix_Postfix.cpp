
#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}
// Infix to Postfix
string infixToPostfix(string s) {
    stack<char> st;
    string ans = "";

    for (char c : s) {
        if (isalnum(c))
            ans += c;

        else if (c == '(')
            st.push(c);

        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while (!st.empty() && st.top() != '(' &&
                  (prec(st.top()) > prec(c) ||
                  (prec(st.top()) == prec(c) && c != '^'))) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

// Infix to Prefix
string infixToPrefix(string s) {
    reverse(s.begin(), s.end());

    for (char &c : s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    stack<char> st;
    string ans = "";

    for (char c : s) {
        if (isalnum(c))
            ans += c;

        else if (c == '(')
            st.push(c);

        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while (!st.empty() && st.top() != '(' &&
                  (prec(st.top()) > prec(c) ||
                  (prec(st.top()) == prec(c) && c == '^'))) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// Postfix Evaluation
int evaluatePostfix(string s) {
    stack<int> st;

    for (char c : s) {
        if (isdigit(c))
            st.push(c - '0');

        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b);
            else if (c == '^') st.push(pow(a, b));
        }
    }

    return st.top();
}

// Prefix Evaluation
int evaluatePrefix(string s) {
    stack<int> st;

    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];

        if (isdigit(c))
            st.push(c - '0');

        else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b);
            else if (c == '^') st.push(pow(a, b));
        }
    }

    return st.top();
}

int main() {
    string infix = "2+3*4";

    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << prefix << endl;

    cout << "Postfix Answer: "
         << evaluatePostfix(postfix) << endl;

    cout << "Prefix Answer: "
         << evaluatePrefix(prefix) << endl;

    return 0;
}
