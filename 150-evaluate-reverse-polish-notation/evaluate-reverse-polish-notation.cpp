class Solution {

    long operand (int a, int b, char operation){
        if(operation == '+'){
            return a + b;
        } else if(operation == '-'){
            return a - b;
        } else if(operation == '*'){
            return (long)a * b;
        } 
        return a/b;
    }

public:
    int evalRPN(vector<string>& tokens) {
     stack<long> Stack;
     int tkn = tokens.size();
     for (int i = 0; i < tkn; i++){

         if(tokens[i].size() == 1 and tokens[i][0] < 48){
             long numbers1 = Stack.top();
             Stack.pop();
             long numbers2 = Stack.top();
             Stack.pop();

             string operation = tokens[i];
             long answers = operand(numbers2, numbers1, operation[0]);
             Stack.push(answers);
         } else {
             Stack.push(stol(tokens[i]));
         }
     }  
     return Stack.top();
    }
};