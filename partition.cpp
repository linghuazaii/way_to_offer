#include "partition.h"

int rand_range(int start, int end, int seed) {
    if (start < end) {
        int temp;
        temp = start;
        start = end;
        end = temp;
    }
    srand(seed);
    return (start + rand() / (RAND_MAX / (end - start + 1) + 1));
}

void swap_i(int &l, int &r) {
    int temp = l;
    l = r;
    r = temp;
}

int partition(int *data, int length, int start, int end) {
    if (data == NULL || length <= 0 || start < 0 || end >= length)
        return -1;

    int index = rand_range(start, end);
    swap_i(data[index], data[end]);
    int small = start - 1;
    for (index = start; index < end; ++index) {
        if (data[index] < data[end]) {
            ++small;
            if (small != index)
                swap_i(data[index], data[small]);
        }
    }
    ++small;
    swap_i(data[small], data[end]);

    return small;
}

#if 0
int main(int argc, char **argv) {
    return 0;
}
#endif
