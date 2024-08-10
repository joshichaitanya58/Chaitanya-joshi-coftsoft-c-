#include <iostream>

using namespace std;

int main()
 {
    
    double num1, num2, result;
    char operation;
    
    
    cout << "Simple Calculator" << endl;
    cout << "Select operation:" << endl;
    cout << "a. Addition (+)" << endl;
    cout << "b. Subtraction (-)" << endl;
    cout << "c. Multiplication (*)" << endl;
    cout << "d. Division (/)" << endl;
    cout << "Enter your choice (a/b/c/d): ";
    
    
    cin >> operation;
    
    
    if (operation == 'a' || operation == '+' || 
        operation == 'b' || operation == '-' || 
        operation == 'c' || operation == '*' || 
        operation == 'd' || operation == '/') {
        
        
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        
        
        switch (operation) 
        {
            case 'a':
            case '+':
                result = num1 + num2;
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
                
            case 'b':
            case '-':
                result = num1 - num2;
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
                
            case 'c':
            case '*':
                result = num1 * num2;
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
                
            case 'd':
            case '/':
                
                if (num2 != 0) 
                {
                    result = num1 / num2;
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                } else 
                {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
                
            default:
                cout << "Error: Invalid operation." << endl;
                break;
        }
    } else
     {
        cout << "Error: Invalid choice of operation." << endl;
    }
    
    return 0;
}