/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (42.81%)
 * Likes:    5951
 * Dislikes: 435
 * Total Accepted:    417.9K
 * Total Submissions: 976K
 * Testcase Example:  '"1 + 1"'
 *
 * Given a string s representing a valid expression, implement a basic
 * calculator to evaluate it, and return the result of the evaluation.
 *
 * Note: You are not allowed to use any built-in function which evaluates
 * strings as mathematical expressions, such as eval().
 *
 *
 * Example 1:
 *
 *
 * Input: s = "1 + 1"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: s = " 2-1 + 2 "
 * Output: 3
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consists of digits, '+', '-', '(', ')', and ' '.
 * s represents a valid expression.
 * '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is
 * invalid).
 * '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is
 * valid).
 * There will be no two consecutive operators in the input.
 * Every number and running calculation will fit in a signed 32-bit integer.
 *
 *
 */

// @lc code=start
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void calculate_two_stack(stack<int> &num_stack, stack<char> &opt_stack) {
    int lhs = num_stack.top();
    num_stack.pop();
    int rhs = num_stack.top();
    num_stack.pop();
    char op = opt_stack.top();
    opt_stack.pop();
    if (op == '-')
      rhs = -rhs;
    num_stack.push(lhs + rhs);
  }

  int calculate_two_stack(string s) {

    stack<int> num_stack; // put the number
    stack<char> op_stack; // put the operations

    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == ')' || s[i] == '+' || s[i] == '-') {
        op_stack.push(s[i]);
      } else if (isdigit(s[i])) {
        string num;
        num.push_back(s[i]);
        while (i - 1 >= 0 && isdigit(s[i - 1])) {
          num.insert(num.begin(), s[i - 1]);
          i--;
        }
        num_stack.push(atoi(num.c_str()));
      } else if (s[i] == '(') {
        while (op_stack.top() != ')') {
          calculate_two_stack(num_stack, op_stack);
        }
        op_stack.pop();
      }
    }
    while (!op_stack.empty()) {
      calculate_two_stack(num_stack, op_stack);
    }
    return num_stack.top();
  }

  vector<string> Parse(string &s) {
    vector<string> exp;
    for (int i = 0; i < s.size();) {
      char c = s[i];
      string token;
      if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' ||
          c == ')') {
        exp.push_back(token + c);
        i++;
        continue;
      }
      if (isdigit(c)) {
        while (isdigit(s[i])) {
          token.push_back(s[i++]);
        }
        exp.push_back(token);
        continue;
      }
      i++;
    }
    return exp;
  }

  int Priority(const string &c) {
    if (c == "*" || c == "/") {
      return 2;
    } else if (c == "+" || c == "-") {
      return 1;
    } else {
      return 0;
    }
  }

  bool isOperator(const string &c) {
    return (c == "+" || c == "-" || c == "*" || c == "/");
  }
  bool isOperator(const char &c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
  }

  vector<string> Infix2RPN(vector<string> &infix) {
    vector<string> rpn;
    stack<string> s;

    for (int i = 0; i < infix.size(); i++) {
      if (isdigit(infix[i][0])) { // number
        rpn.push_back(infix[i]);
      } else if (infix[i] == "(") {
        s.push(infix[i]);
      } else if (infix[i] == ")") {
        while (!s.empty() && s.top() != "(") {
          rpn.push_back(s.top());
          s.pop();
        }
        s.pop();
      } else if (isOperator(infix[i])) {
        while (!s.empty() && Priority(s.top()) >= Priority(infix[i])) {
          rpn.push_back(s.top());
          s.pop();
        }
        s.push(infix[i]);
      }
    }
    while (!s.empty()) {
      rpn.push_back(s.top());
      s.pop();
    }

    return rpn;
  }

  int calculate_RPN_evluation(string &s) {
    vector<string> exp = Parse(s);
    exp = Infix2RPN(exp);

    stack<int> ss;
    for (int i = 0; i < exp.size(); i++) {
      if (isdigit(exp[i][0])) {
        ss.push(atoi(exp[i].c_str()));
      }
      if (exp[i] == "+" || exp[i] == "-") {
        int rhs = ss.top();
        ss.pop();
        int lhs = ss.top();
        ss.pop();
        if (exp[i] == "-")
          rhs = -rhs;
        ss.push(lhs + rhs);
      }
    }
    return ss.top();
  }

  int calculate(string s) {
    // string str;
    // for (int i = 0; i < s.size(); i++) {
    //   if (!isspace(s[i]))
    //     str.push_back(s[i]);
    // }
    return calculate_RPN_evluation(s);
  }
};
// @lc code=end
