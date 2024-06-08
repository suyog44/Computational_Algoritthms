#include <stdio.h>
#include <stdlib.h>

struct list_head{
	int data;
	struct list_head *next;	
};

struct list_head *head = NULL;

struct list_head * create_node(void){
	struct list_head *node_addr = (struct list_head *)malloc(sizeof(struct list_head));
	if(node_addr != NULL){
		return node_addr;
	}
	else{
		printf("New node creation failed!\n");
		return NULL;
	}
}

static int insert_node(int data){
	struct list_head *new = create_node();
	if(new != NULL){
		new->data = data;
		new->next = head;
		head=new;
		return 0;
	}
	else{
		printf("Node insertion failed!\n");
		return -1;
	}
}

static void display_nodes(struct list_head *head){
	while(head->next !=NULL){
		printf("data: %d -> ", head->data);
		head = head->next;
	}
	if(head->next==NULL){
		printf("data: %d", head->data);
	}
}

int main(int argc, char **argv)
{
	int arr[5] = {1,2,3,4,5};
	for(int i=0; i<sizeof(arr)/sizeof(arr[0]);i++) insert_node(arr[i]);
	display_nodes(head);
	return 0;
}
