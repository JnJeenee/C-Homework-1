#include <iostream>
int len(char* num);
int main(int argc, char* argv[]){
    char* num1 = argv[1];
    char* num2 = argv[2];
    if (*num1 == '-'){
        if (*num2 != '-'){
            std::cout << "less" << std::endl;
            return 0;
        }
        else{
            num1++;
            num2++;
            if (len(num1) > len(num2)){
                std::cout << "less" << std::endl;
                return 0;
            }
            else if (len(num2) > len(num1)){
                std::cout << "greater" << std::endl;
                return 0;
            }
            else{
                while (*num1 == *num2){
                    num1++;
                    num2++;
                    if(*num1 == '.' && *num2 != '.'){
                        std::cout << "less" << std::endl;
                        return 0;
                    }
                    else if(*num1 != '.' && *num2 == '.'){
                        std::cout << "greater" << std::endl;
                        return 0;
                    }
                    else if (*num1 == '.' && *num2 == '.'){
                        num1++;
                        num2++;
                        while(*num1 == *num2){
                            num1++;
                            num2++;
                            if(*num1 == '\0' && *num2 != '\0'){
                                std::cout << "greater" << std::endl;
                                return 0;
                            }
                            else if(*num1 != '\0' && *num2 == '\0'){
                                std::cout << "less" << std::endl;
                                return 0;
                            }
                            else if(*num1 == '\0' && *num2 == '\0'){
                                std::cout << "equal" << std::endl;
                                return 0;
                            }
                        }
                    }
                    if(*num1 == '\0' && *num2 == '\0'){
                        std::cout << "equal" << std::endl;
                        return 0;
                    }
                }
                if (*num1 > *num2){
                    std::cout << "less" << std::endl;
                    return 0;
                }
                else{
                    std::cout << "greater" << std::endl;
                    return 0;
                }
            }
        }
    }
    else{
        if (*num2 == '-'){
            std::cout << "greater"<< std::endl;
            return 0;
        }
        else{
            if (*num1 == '+'){
                num1++;
            }
            if (*num2 == '+'){
                num2++;
            }
            if (len(num1) > len(num2)){
                std::cout << "greater" << std::endl;
                return 0;
            }
            else if (len(num2) > len(num1)){
                std::cout << "less" << std::endl;
            }
            else{
                while (*num1 == *num2){
                    num1++;
                    num2++;
                    
                    if(*num1 == '.' && *num2 != '.'){
                        std::cout << "greater" << std::endl;
                        return 0;
                    }
                    else if(*num1 != '.' && *num2 == '.'){
                        std::cout << "less" << std::endl;
                        return 0;
                    }
                    else if (*num1 == '.' && *num2 == '.'){
                        num1++;
                        num2++;
                        while(*num1 == *num2){
                            num1++;
                            num2++;
                            if(*num1 == '\0' && *num2 != '\0'){
                                std::cout << "less" << std::endl;
                                return 0;
                            }
                            else if(*num1 != '\0' && *num2 == '\0'){
                                std::cout << "greater" << std::endl;
                                return 0;
                            }
                            else if(*num1 == '\0' && *num2 == '\0'){
                                std::cout << "equal" << std::endl;
                                return 0;
                            }
                        }
                    }
                    if(*num1 == '\0' && *num2 == '\0'){
                        std::cout << "equal" << std::endl;
                        return 0;
                    }
                }
                if (*num1 > *num2){
                    std::cout << "greater" << std::endl;
                    return 0;
                }
                else{
                    std::cout << "less" << std::endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
int len(char* num){
    int lens = 0;
    while (*num != '\0' and *num != '.'){
        num++;
        lens++;
    }
    return lens;
}