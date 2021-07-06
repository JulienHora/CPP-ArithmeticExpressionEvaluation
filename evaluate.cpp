#include "evaluate.h"

int OperatorPrecedence(char Operator)
{
    switch (Operator)
    {
        case '+' :
        case '-' : return 1;
        case '*' : 
        case '/' : return 2;
        
        default : return 0;
    }
}

template <typename any>
int ExecuteOperation(any A, any B, char Operator)
{
    switch(Operator)
    {
        case '+': return A + B;
        case '-': return A - B;
        case '*': return A * B;
        case '/': return A / B;
        default: return 0;
    }
}
 
int Evaluate(string Expression)
{
    int Index;
    
    stack <int> Values; // Stack container for values.
    stack <char> Operators; // Stack container for operators.
     
    for(Index = 0; Index < Expression.length(); Index++)
    {
        
        if(Expression[Index] == ' ') continue; // If the current token is a whitespace, continue (pass).

        else if(Expression[Index] == '(') Operators.push(Expression[Index]); // If the current token is a parentheses opening, push it to the Operators stack.

        else if(isdigit(Expression[Index])) // If the current token is a number, push it to the Values stack.
        {
            int Value = 0;

            while(Index < Expression.length() && isdigit(Expression[Index])) // If more than one digit in number, loop on the number token until storing the entire number.
            {
                Value = (Value * 10) + (Expression[Index] - '0');
                Index++;
            }
             
            Values.push(Value);

            // Since we need to increment Index in the for loop, 
            // we also need to decrement Index to fix the offset 
            // induced by the while loop.
            Index--;
        }
         
        else if(Expression[Index] == ')') // If the current token is a parentheses closure, resolve the expression within the parentheses.
        {
            while(!Operators.empty() && Operators.top() != '(')
            {
                int Value2 = Values.top();
                Values.pop();
                 
                int Value1 = Values.top();
                Values.pop();
                 
                char Operator = Operators.top();
                Operators.pop();
                 
                Values.push(ExecuteOperation(Value1, Value2, Operator));
            }
             
            // Ejecting the parentheses opening.
            if(!Operators.empty()) Operators.pop();
        }
         
        else // If current token is an operator.
        {
            // While the top of the Operator stack has a greater or same precedence than the current operator token,
            // execute the operation with the top of the Operator stack on the two elements in the Values stack.
            while(!Operators.empty() && OperatorPrecedence(Operators.top()) >= OperatorPrecedence(Expression[Index]))
            {
                int Value2 = Values.top();
                Values.pop();
                 
                int Value1 = Values.top();
                Values.pop();
                 
                char Operator = Operators.top();
                Operators.pop();
                 
                Values.push(ExecuteOperation(Value1, Value2, Operator));
            }
            
            Operators.push(Expression[Index]); // Push current token to the Operators stack.
        }
    }
    
    while(!Operators.empty()) // The totality of the expression has been parsed, execute remaining operations with remaining Operators and Values.
    {
        int Value2 = Values.top();
        Values.pop();
                 
        int Value1 = Values.top();
        Values.pop();
                 
        char Operator = Operators.top();
        Operators.pop();
                 
        Values.push(ExecuteOperation(Value1, Value2, Operator));
    }
     
    // Returning the top of the Values stack, which now contains the result.
    return Values.top();
}