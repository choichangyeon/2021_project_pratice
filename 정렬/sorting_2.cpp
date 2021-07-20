#include <iostream>

void heapify(int *list, int size, int index){
    int max, l_index, r_index;
    max = index;
    l_index = 2 * index + 1;
    r_index = 2 * index + 2;

    if (l_index < size && list[l_index] > list[max]){
        max = l_index;
    }
    if (r_index < size && list[r_index] > list[max]){
        max = r_index;
    }
    if (max != index){
        int temp = list[index];
        list[index] = list[max];
        list[max] = temp;
        heapify(list, size, max);
    }
}

int *heap_sort(int loops){
    int *heap = new int[loops];
    int temp;

    for (int i = 0; i < loops; i++){
        std::cin >> temp;
        heap[i] = temp;
    }

    for (int i = loops / 2 - 1; i >= 0 ; i--)
        heapify(heap, loops, i);
    
    
    
    for (int i = loops - 1; i > 0; i--){
        temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        heapify(heap, i, 0);
    }
    return heap;
}


int main(){
    int loops;
    std::cin >> loops;

    int *ans = NULL;

    ans = heap_sort(loops);
    
    for (int i = 0; i < loops; i++)
        std::cout << ans[i] << '\n';
}

// void merge_sort(int loops){
//     int a;
//     bool odd;
//     if(loops % 2 == 1){
//         a = (loops / 2) + 1;
//         odd = true;
//     }
//     else{
//         a = loops / 2;
//         odd = false;
//     }
        
    

//     // int l_1[a], l_2[b];

//     // for (int i = 0; i < a; i++)
//     //     std::cin >> l_1[i];
//     // for (int i = 0; i < b; i++)
//     //     std::cin >> l_2[i];
    
//     int heap[loops];

//     for (int i = 0; i < loops; i++)
//         std::cin >> heap[i];
    

    
// }