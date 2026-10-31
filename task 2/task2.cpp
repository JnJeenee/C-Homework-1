#include <iostream>
int tonum(char* ptr);
int Evklid(int num1, int num2);
int main(int argc, char* argv[]){
    if (argc != 2) return 1;
    int n = tonum(argv[1]);
    int* arr = new int[n]; 
    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    int k;
    std::cin >> k;
    k = ((k%n) + n) % n;
    int nod = Evklid(n,k);
    for (int i = 0; i < nod; i++){
        int current = arr[i];
        int pos = i;
        do{
            int next = (pos + k) % n;
            int temp = arr[next];
            arr[next] = current;
            current = temp;
            pos = next;
        } while (pos != i);
    }
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << std::endl;
    }
    for (int i = 0; i < n; i++){
        if(i != 0){
            std::cout << " " << arr[i];
        }
        else{
            std::cout << arr[i];
        }
    }
    std::cout << std::endl;
    delete[] arr;
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
int Evklid(int num1, int num2){
    while (num2 != 0){
        int r = num1%num2;
        num1 = num2;
        num2 = r;
    }
    return num1;
}