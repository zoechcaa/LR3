#include <iostream>
#include <stack>
#include <string>

int main (){

    std::stack <int> valStack;
    std::string exp = "3 7 - 9 * 2 + 0 /";
    std::cout << exp << std::endl;
    int left, right;
    std::string c = "";
    for (const char &s : exp){
        if(isdigit(s)){
            c += s;
        }
        else{
            if(c != ""){
                valStack.push(std::stod(c));
                c = "";

            if(valStack.size() > 1){
                right = valStack.top();
                valStack.pop();
                left = valStack.top();
                valStack.pop();
            }
        }

        switch (s){
            case '+': valStack.push(left + right); break;
            case '-': valStack.push(left - right); break;
            case '*': valStack.push(left * right); break;
            case '/':
                try{
                    if(right == 0)
                    throw std::invalid_argument("devision by zero");
                    valStack.push(left / right);
                    }
                    catch(std::invalid_argument in){
                        std::cout << "error: " << in.what() << std::endl;
                    }
                    break;
            case ' ': break;
            default:
                std::cout << "incorrect input: " << s << std::endl; break;
            }
        }
    }

    if(valStack.size() > 1){
        std::cout << "incorrect expression" << std::endl;
    }
    else{
        std::cout << "result: " << valStack.top() <<std::endl;
    }
    return 0;
}
