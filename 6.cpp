/* This file is auto-generated.Edit it at your own peril.*/
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <termios.h>
#include <inttypes.h>
#include <errno.h>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/mman.h>
#include <sched.h>
#include <malloc.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
using namespace std;

/**
  根据前序，中序创建二叉树
**/

int g_preorder[] = {
    1,2,4,7,3,5,6,8
};
int g_inorder[] = {
    4,7,2,1,5,3,8,6
};

typedef struct tree_node {
    int val;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

tree_node * create_tree_imp(int *start_pre, int *end_pre, int *start_in, int *end_in) {
    tree_node *root = new tree_node;
    root->val = start_pre[0];
    root->left = root->right = NULL;

    if (start_pre == end_pre) {
        if (start_in == end_in && *start_pre == *start_in)
            return root;
    }

    int *root_index = start_in;
    while (root_index <= end_in && *root_index != root->val)
        ++root_index;

    int left_len = root_index - start_in;
    int *left_end_pre = start_pre + left_len;
    if (left_len > 0)
        root->left = create_tree_imp(start_pre + 1, left_end_pre, start_in, root_index - 1);
    if (left_len < end_pre - start_pre)
        root->right = create_tree_imp(left_end_pre + 1, end_pre, root_index + 1, end_in);

    return root;
}

tree_node * create_tree(int *preorder, int *inorder, int n) {
    if (preorder == NULL || inorder == NULL || n <= 0)
        return NULL;
    return create_tree_imp(preorder, preorder + n - 1, inorder, inorder + n - 1);
}

void post_order_print(tree_node * root) {
    if (root == NULL)
        return;

    post_order_print(root->left);
    post_order_print(root->right);
    cout << root->val << " ";
}

int main(int argc, char **argv) {
    tree_node *tree = create_tree(g_preorder, g_inorder, 8);
    post_order_print(tree);
    cout << endl;

    return 0;
}

