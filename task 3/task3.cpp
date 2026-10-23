#include <iostream>
int tonum(char* ptr);
int main(int argc, char* argv[]){
    int n = tonum(argv[1]);
    double* mas1 = new double[n];
    double* mas2 = new double[n];
    for (int i = 0; i < n; i++){
        std::cin >> mas1[i];
    }
    for (int i = 0; i < n; i++){
        std::cin >> mas2[i];
    }
    double sum = 0;
    for (int i = 0; i < n; i++){
        sum += mas1[i] * mas2[i];
    }
    std::cout << sum << std::endl;
    delete[] mas1;
    delete[] mas2;
    return 0;
}
int tonum(char* ptr){
    int n = 0;
    while(*ptr != '\0'){
        n *= 10;
        n += *ptr - '0';
        ptr++;
    }
    return n;
}