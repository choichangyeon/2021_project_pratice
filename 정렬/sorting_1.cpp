#include <iostream>

void buble_sort(int loops){
    int arr[loops];
    int temp;
    
    for (int i = 0; i < loops; i++){
        std::cin >> temp;
        arr[i] = temp;
    }

    for (int m = 0; m < loops - 1; m++){
        for (int n = m + 1; n < loops; n++){
            if (arr[m] > arr[n]){
                temp = arr[m];
                arr[m] = arr[n];
                arr[n] = temp;
            }
        }
    }

    for (int k = 0; k < loops; k++)
        std::cout << arr[k] << std::endl;
}

int main(){
    int loops;
    std::cin >> loops;

    buble_sort(loops);

}