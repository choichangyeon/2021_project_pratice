#include "Node.h"
#include <iostream>
#include <string>
#include <cmath>

int cnt = 1, size = 1;
node *insert(node *BST);
int which(int val, node *BST);
int find_node(int target, int num, node *BST);
void del(int target, node *BST);
void postorder(int no, node *BST);
void inorder(int no, node *BST);
void preorder(int no, node *BST);

int main(){

    std::string cmd;

    node *BST = new node[size];

    while(true){
        std::cin >> cmd;

        if (cmd == "insert"){
            BST = insert(BST);
            std::cout << "++++++++++++++++\n";
            for (int n = 0; n < size; n++){
                if (!BST[n].fill)
                    std::cout << "[ ] ";
                else
                    std::cout << BST[n].val << " ";
            }
            std::cout << "\n++++++++++++++++\n";
            std::cout << "******************\n";
            for (int n = 0; n < size; n++){
                if (BST[n].l_child == -1)
                    std::cout << "[ ] ";
                else
                    std::cout << BST[n].l_child << " ";
            }
            std::cout << "\n******************\n";
            std::cout << "&&&&&&&&&&&&&&&&&&&&\n";
            for (int n = 0; n < size; n++){
                if (BST[n].r_child == -1)
                    std::cout << "[ ] ";
                else
                    std::cout << BST[n].r_child << " ";
            }
            std::cout << "\n&&&&&&&&&&&&&&&&&&&&\n";
            
        }
            
        else if (cmd == "del"){
            int target;
            std::cin >> target;
            int node;
            node = find_node(target, 0, BST);
            if (node < 0)
                std::cout << "None val\n";
            else
                del(node, BST);
            std::cout << "++++++++++++++++\n";
            for (int n = 0; n < size; n++){
                if (!BST[n].fill)
                    std::cout << "[ ] ";
                else
                    std::cout << BST[n].val << " ";
            }
            std::cout << "\n++++++++++++++++\n";
            std::cout << "******************\n";
            for (int n = 0; n < size; n++){
                if (BST[n].l_child == -1)
                    std::cout << "[ ] ";
                else
                    std::cout << BST[n].l_child << " ";
            }
            std::cout << "\n******************\n";
            std::cout << "&&&&&&&&&&&&&&&&&&&&\n";
            for (int n = 0; n < size; n++){
                if (BST[n].r_child == -1)
                    std::cout << "[ ] ";
                else
                    std::cout << BST[n].r_child << " ";
            }
            std::cout << "\n&&&&&&&&&&&&&&&&&&&&\n";
        }

        else if(cmd == "postorder"){
            postorder(0, BST);
        }

        else if(cmd == "inorder"){
            inorder(0, BST);
        }

        else if(cmd == "preorder"){
            preorder(0, BST);
        }
            
        else{
            std::cout << "error\n";
        }
    }
}

node *insert(node *BST){
    int val, temp = size;
    std::cin >> val;
    int i = 0, check = -1;
    bool a = true;
    while(a){
        if (BST[i].fill){
            if (BST[i].val < val){
                i = i*2 + 2;
                check = 1;
            }
            else{
                i = i*2 + 1;
                check = 0;
            }
        }
        else{
            BST[i].set(val, i+1, 1);
            if (check == 0)
                BST[i/2].l_set(val);
            else if (check == 1)
                BST[i/2 - 1].r_set(val);
            
            break;
        }
        
        if (i > size - 1){
            cnt++;
            temp = pow(2, cnt) - 1;
            node *flash = new node[temp];

            for (int n = 0; n < size; n++){
                flash[n].set(BST[n].val, BST[n].no, BST[n].fill);
                flash[n].l_set(BST[n].l_child);
                flash[n].r_set(BST[n].r_child);
            }
                

            delete[] BST;
            BST = flash; //주소 복사 부분에서 애먹었음 ㅠ
            size = temp;
        }
    }
    return BST; //처음에는 size 값만 리턴하려고 했는데 size를 전역으로 두고 BST를 리턴함 (근데 결국 BST도 전역이 됐다는 슬픈 사실... => 바꾸는 중)
}

int which(int val, node *BST){
    int check = -1;
    int i = 0;
    while(true){
        if (BST[i].val < val){
            i = i*2 + 2;
            check = 1; //r_c
        }
        else if (BST[i].val > val){
            i = i*2 + 1;
            check = 0; //l_c
        }
        else
            break;
    }
    return check;
}

int find_node(int target, int num, node *BST){ //node 번호 반환
    if (target > BST[num].val && BST[num].fill == 1)
        find_node(target, num*2 + 2, BST);
    else if (target < BST[num].val && BST[num].fill == 1)
        find_node(target, num*2 + 1, BST);
    else if (target == BST[num].val && BST[num].fill == 1)
        return num; //실제 배열의 인덱스 보내기
    else
        return -1;
    
        
}

void del(int target, node *BST){ //실제 인덱스가 target임
    //target이 node 번호가 아닌 val이 되도록 다시 짜기 --> 해결 
    int left_big = 0, right_small = 0;
    int num;

    num = target*2 + 1;
    while(BST[num].fill == 1){
        left_big = num; //node 번호 
        num = num*2 + 2;
    }
    
    num = target*2 + 2;
    while(BST[num].fill == 1){
        right_small = num; //node 번호
        num = num*2 + 1;
    }
    
    //del을 실행하면 재귀해야해서 함수의 인자값으로 배열의 주소값을 넣을 때 오류가 생길 것 같아서 BST를 전역으로 뒀음
    //근데 먼저 set을 하고 배열을 인자에 넣으면 굳이 전역으로 두지 않아도 될 것 같음 -> 해결

    int check = which(BST[target].val, BST); //지우려는 타겟이 왼쪽 자식인지 오른쪽 자식인지 판단
    int temp;
    if(left_big != 0){
        temp = BST[left_big].val;
        del(left_big, BST); //타겟에 올라가진 노드를 del하는 코드
        BST[target].set(temp, target + 1, 1); //왼쪽에서 가장 큰 값으로 설정
    }
    else if (right_small != 0){
        temp = BST[right_small].val;
        del(right_small, BST); //타겟에 올라가진 노드를 del하는 코드
        BST[target].set(temp, target + 1, 1); //오른쪽에서 가장 작은 값으로 설정
    }
    else{
        BST[target].set(-1, 0, 0); //자식이 없다면
    }

    if (check == 0) //l_c
        BST[target/2].l_set(BST[target].val);
    else if (check == 1) //r_c
        BST[target/2 - 1].r_set(BST[target].val);
}

void postorder(int no, node *BST){ //후위 순위 - left right root
    if (2*no + 1 <= size) //자식이 존재한다면!!
        postorder(2*no + 1, BST);
    if (2*no + 2 <= size)
        postorder(2*no + 2, BST);
    if (BST[no].fill == 1)
        std::cout << BST[no].val << "\n";
}

void inorder(int no, node *BST){ //중위 순위 - left root right
    if (2*no + 1 <= size)
        inorder(2*no + 1, BST);
    if (BST[no].fill == 1)
        std::cout << BST[no].val << "\n";
    if (2*no + 2 <= size)
        inorder(2*no + 2, BST);
}

void preorder(int no, node *BST){ //전위 순위 - root left right
    if (BST[no].fill == 1)
        std::cout << BST[no].val << "\n";
    if (2*no + 1 <= size) 
        preorder(2*no + 1, BST);
    if (2*no + 2 <= size)
        preorder(2*no + 2, BST);
}