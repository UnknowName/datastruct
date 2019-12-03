#include <iostream>
using namespace std;

const int SIZE=10;

typedef struct{
    int data;
} Node;

typedef struct {
    Node  datas[SIZE];
    int length;
} LineList;

void init_list(LineList *lst){
    lst -> length = 0;
};

/*列表插入，将node插入list的I的位置。成功返回1，失败返回0 */
int insert_list(LineList *lst, int i, Node node){
    //首先判断当前线性表是否已满
    if (lst -> length == SIZE){
        printf("List is full\n");
        return 0;
    };
    //再判断i的值是否合法,范围在1至lstt->length + 1之间
    if ( i > 0 && i <= lst ->length + 1 ){
        printf("valid, can insert into\n");
        for(int j = i; j > i;j--){
            lst ->datas[j] = lst -> datas[j-1];
        };
        //插入node，因为索引是从0开始，所以要减1
        lst -> datas[i -1] = node;
        lst -> length += 1;
        return 1;
    }else{
        //I不合法
        printf("I invalid\n");
        return 0;
    }
};

// 获取指定位置i的值,放入dest变量中
int get_item(LineList list, int i, Node *dest) {
    //判断i是否合法后返回
    if (i > 0 && i <= list.length){
        //将dest的值设置为节点的值
        //*dest = list.datas[i-1];
        *dest = list.datas[i-1];
        printf("Get item sccuess\n");
        return 1;
    }else{
        printf("I invalid\n");
        return 0;
    };
};

//删除指定位置i的节点
int delete_item(LineList *list, int i){
    //先判断i是否合法
    if (i > 0 && i <= list ->length) {
        for(int j = i;j <= list -> length;j++){
            list -> datas [i-1] = list -> datas[i];
        };
        list -> length -= 1;
        printf("Delete success\n");
        return 0;
    }else {
        printf("I invalid\n");
        return 0;
    };
};

int main(){
    Node node = {1}, node2 = {4}, *tmp;
    LineList list;
    // 切记定义的指针类型需要先分配内存，不然会有异常
    tmp = (Node *)malloc(sizeof(Node));
    init_list(&list);
    insert_list(&list, 1, node2);
    insert_list(&list, 2, node);
    delete_item(&list, 2);
    get_item(list,2,tmp);
};