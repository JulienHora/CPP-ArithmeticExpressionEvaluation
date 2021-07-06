// Expressions tokens are expected to be seperated by spaces.

////////////////////////////////////////////////// INCLUDES
#include <iostream>
#include <stack>
//////////////////////////////////////////////////


////////////////////////////////////////////////// USINGS
using std::cout;
using std::stack;
using std::string;
//////////////////////////////////////////////////


////////////////////////////////////////////////// DECLARATIONS
/** Determines precedence based on the operator.
*
*   @param Operator: (char) Arithmetic operator. 
*   @return (int) Operator precedence between 0 and 1.
*/
int OperatorPrecedence(char Operator);

/** Performs a given arithmetic operation.
*
*   @param A: (int) First integer argument. 
*   @param B: (int) Second integer argument. 
*   @param Operator: (char) Arithmetic operator. 
*   @return (int) Returns the result of the operation.
*/
template <typename any>
int ExecuteOperation(any A, any B, char Operator);

/** Evaluate an arithmetic operation from a string.
*
*   @param Expression: (string) The arithmetic expression to be evaluated. 
*   @return (int) Returns the result of the operation of the arithmetic expression.
*/
int Evaluate(string Expression);

//////////////////////////////////////////////////