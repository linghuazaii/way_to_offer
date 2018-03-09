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

/***
  二维数组中的查找
  给定一个二维数组，横向和纵向都是递增的，给定一个数，判断是否在数组中存在。
***/

static int g_data[][4] = {
    {
        1,2,8,9
    },
    {
        2,4,9,12
    },
    {
        4,7,10,13,
    },
    {
        6,8,11,15
    }
};

bool shrink(int data[][4], int row, int col, int k, int &start_row, int &end_col) {
    while (end_col > 0 && data[start_row][end_col - 1] > k)
        --end_col;
    if (end_col == 0)
        return false;
    while (start_row < row && data[start_row][end_col - 1] < k)
        ++start_row;
    if (start_row == row)
        return false;

    return true;
}

bool find_k(int data[][4], int rows, int cols, int k) {
    bool ret = true;
    int _row = 0, _col = cols;
    while (_row < rows && _col > 0) {
        ret = shrink(data, rows, cols, k, _row, _col);
        if (ret == false)
            return false;
        if (data[_row][_col - 1] == k)
            return true;
    }

    return false;
}



void print(int data[][4], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << data[i][j] << "\t";
        cout << endl;
    }
}

int main(int argc, char **argv) {
    print(g_data, 4, 4);
    int k = atoi(argv[1]);
    bool ret = find_k(g_data, 4, 4, k);
    if (ret == true)
        cout << k << " is in the array!" << endl;
    else
        cout << k << " is not in the array!" << endl;

    return 0;
}

