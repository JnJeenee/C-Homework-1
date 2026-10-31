#include <iostream>
int len(char* num);
bool sign(char*& num);
int lenComparison(int len1, int len2);
int largerNum(char num1, char num2);
int floatedComparison(char* num1, char* num2);
int comparison(char* num1, char* num2);
int main(int argc, char* argv[]){
    if (argc != 3) return 1;
    char* num1 = argv[1];
    char* num2 = argv[2];
    bool minus1 = sign(num1);
    bool minus2 = sign(num2);
    if(minus1 != minus2){
        if (minus1){
            std::cout << "less" << std::endl;
            return 0;
        }
        else{
            std::cout << "greater" << std::endl;
            return 0;
        }
    }
    int res = comparison(num1, num2);
    if (minus1){
        res = -res;
    }
    if (res > 0){
        std::cout << "greater" << std::endl;
    }
    else if (res < 0){
        std::cout << "less" << std::endl;
    }
    else{
        std::cout << "equal" << std::endl;
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
bool sign(char*& num){
    if (*num == '-'){
        num++;
        return true;
    }
    else if (*num == '+'){
        num++;
        return false;
    }
    else return false;
}
int lenComparison(int len1, int len2){
    if(len1 < len2){
        return -1;
    }
    else if(len1 > len2){
        return 1;
    }
    else return 0;
}
int largerNum(char num1, char num2){
    if (num1 > num2){
        return 1;
    }
    else if(num1 < num2){
        return -1;
    }
    else return 0;
}
int floatedComparison(char* num1, char* num2){
    while(*num1 != '\0' and *num2 != '\0'){
        if (*num1 != *num2){
            return largerNum(*num1, *num2);
        }
        num1++;
        num2++;
    }
    return largerNum(*num1, *num2);
}
int comparison(char* num1, char* num2){
    int res = lenComparison(len(num1), len(num2));
    if (res != 0) return res;
    else {
        while (*num1!='.' and *num1 != '\0'){
            if (*num1 != *num2){
                return largerNum(*num1, *num2);
            }
            num1++;
            num2++;
        }
        if (*num1 == '.'){
            num1++;
        }
        if (*num2 == '.'){
            num2++;
        }
        return floatedComparison(num1,num2);
    }
}
