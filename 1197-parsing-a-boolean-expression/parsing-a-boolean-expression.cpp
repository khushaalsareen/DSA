class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> operato;
        stack<char> operand;

        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '&' || expression[i] == '|' || expression[i] == '!') {
                operato.push(expression[i]);
            }
            else if (expression[i] == '(') {
                // Indicate the beginning of a new sub-expression
                operand.push('(');
            }
            else if (expression[i] == 't' || expression[i] == 'f') {
                operand.push(expression[i]);
            }
            else if (expression[i] == ')') {
                // Evaluate the expression within the parentheses
                char op = operato.top();
                operato.pop();

                bool res = (op == '&') ? true : (op == '|') ? false : true;
                while (operand.top() != '(') {
                    char top = operand.top();
                    operand.pop();
                    bool value = (top == 't');

                    if (op == '&') {
                        res &= value;
                    }
                    else if (op == '|') {
                        res |= value;
                    }
                    else if (op == '!') {
                        res = !value;
                    }
                }
                operand.pop(); // Pop the '('

                // Push the result of the sub-expression
                operand.push(res ? 't' : 'f');
            }
        }

        // The final result should be on top of the operand stack
        return operand.top() == 't';
    }
};