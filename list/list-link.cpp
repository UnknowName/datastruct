/*
    线性表的链表实现
    version: 1
    Tags: 学渣第一式
*/
#include <iostream>
using namespace std;

typedef struct {
    int data;
} Node;

typedef struct linklist {
    Node data;
    struct linklist *next;
} LinkList;

// 初始化链表
LinkList* init_linklist(){
    LinkList *head;
    head = (LinkList *)malloc(sizeof(LinkList));
    if (!head) {
        printf("Memory malloc failed\n");
        exit(1);
    };
    head -> next = NULL;
    return head;
};

// 获取当前链表长度
int get_length(LinkList *head){
    int i = 0;
    while (head -> next != NULL){
        i += 1;
        head = head -> next;
    };
    return i;
};

// 链表插入运算，在第i个节点前插入node
int insert_linklist(LinkList *head, int i, Node node){
    // 获取当前链表的长度并进行合法检查
    int len = get_length(head);
    LinkList *tmp = head;
    // 初始化待添加的节点
    LinkList *link_node = (LinkList *)malloc(sizeof(LinkList));
    if (i > 0 && i <= len + 1){
        printf("I valid\n");
        // 在I之前插入节点，所以要找到它前面的一个结点，修改它的next指向待添加结点
        int j = 0;
        while( j != i - 1){
            j += 1;
            tmp = tmp -> next;
        };
        link_node -> data = node;
        link_node -> next = tmp -> next;
        tmp -> next = link_node;
        return 1;
    }else{
        printf("Error I invalid\n");
        return 0;
    };
};

// 遍历线性链表
void show_linklist(LinkList *head){
    printf("start for items\n");
    while (head -> next != NULL){
        head = head -> next;
        Node data = head -> data;
        int num = data.data;
        printf("num is %d\n", num);
    };
};

// 删除操作
int delete_linklist(LinkList *head, int i){
    // 对i限制不能少于0
    if (i <= 0 ){
        printf("I invalid\n");
        return 1;
    };
    // 定位i的前一个节点
    int j = 0;
    LinkList *del_node = head, *pre_node;
    while (head -> next != NULL){
        pre_node = head;
        if (j == i - 1 && pre_node -> next != NULL){
            pre_node = head;
            del_node = pre_node -> next;
            pre_node -> next = del_node -> next;
            free(del_node);
            printf("find it\n");
            return 1;
        };
        head = head -> next;
        j += 1;
    };
    printf("Not find\n");
    return 0;
};

int main(){
    LinkList *linklist;
    linklist = init_linklist();
    int len = get_length(linklist);
    printf("Current linklist length is %d\n",len);
    // 插入
    Node add_node = {20}, add_node2 = {30};
    insert_linklist(linklist, 1, add_node2);
    insert_linklist(linklist, 2, add_node);
    len = get_length(linklist);
    printf("length is %d\n", len);
    // 删除前查找链表内容
    show_linklist(linklist);
    delete_linklist(linklist, 2);
    // 删除后再次查找里面内容
    show_linklist(linklist);
};