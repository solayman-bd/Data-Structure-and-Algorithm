//infix to post fix using stack
//Rules i must keep in mind that-
//(1) Two operators of the same priority can not stay together
//(2) Highest Priority operator will not stay in the stack when lowest priority operator will be instead
//(3) Pop all the operators from the stack and place them in the postfix
#include <bits/stdc++.h>
using namespace std;

/*
bool isOperand(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
    {
        return true;
    }
    return false;
}
*/

bool isOperand(char c)
{
    return isalnum(c); //used built in function to check alpha numeric char
}

int getPriority(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return -1;
    }
}

string infixToPostfix(string infix)
{
    string postfix = "";
    stack<char> operators;
    operators.push('N');
    int length = infix.length();
    for (int i = 0; i < length; i++)
    {
        if (isOperand(infix[i]))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            operators.push('(');
        }
        else if (infix[i] == ')')
        {
            while (operators.top() != 'N' && operators.top() != '(')
            {
                char c = operators.top();
                operators.pop();
                postfix += c;
            }
            if (operators.top() == '(')
            {
                operators.pop();
            }
        }
        else
        {
            while (operators.top() != 'N' && getPriority(infix[i]) <= getPriority(operators.top()))
            {
                char c = operators.top();
                operators.pop();
                postfix += c;
            }
            operators.push(infix[i]);
        }
    }
    while (operators.top() != 'N')
    {
        char c = operators.top();
        operators.pop();
        postfix += c;
    }
    return postfix;
}
double evaluatePostfix(string postfix)
{
    stack<double> operands;
    int length = postfix.length();
    for (int i = 0; i < length; i++)
    {
        if (isOperand(postfix[i]))
        {
            operands.push(postfix[i] - '0');
        }
        else
        {
            double op1 = operands.top();
            operands.pop();
            double op2 = operands.top();
            operands.pop();
            switch (postfix[i])
            {
            case '+':
                operands.push(op2 + op1);
                break;
            case '-':
                operands.push(op2 - op1);
                break;
            case '*':
                operands.push(op2 * op1);
                break;
            case '/':
                operands.push(op2 / op1);
                break;
            }
        }
    }
    return operands.top();
}

int main()
{
    string infix;
    cin >> infix;
    string postfix= infixToPostfix(infix);
    double ans= evaluatePostfix(postfix);
    cout << ans << endl;
    return 0;
}
