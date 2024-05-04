void merge(int list[], int start, int end) {
    int mid = (start + end) / 2, n = end - start + 1;
    int ptr[] = {start, mid + 1}, mrg_list[n], i;
    for (i = 0; i < n; i++) {
        if (list[ptr[0]] < list[ptr[1]]) {
            mrg_list[i] = list[ptr[0]++];
            if (ptr[0] > mid) {
                while (ptr[1] <= end) {
                    mrg_list[++i] = list[ptr[1]++];
                }
            }
        } else {
            mrg_list[i] = list[ptr[1]++];
            if (ptr[1] > end) {
                while (ptr[0] <= mid) {
                    mrg_list[++i] = list[ptr[0]++];
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        list[start++] = mrg_list[i];
    }
}
void mergeSortRec(int list[], int start, int end) {
    if (end <= start)
        return;
    int mid = (start + end) / 2;
    mergeSortRec(list, start, mid);
    mergeSortRec(list, mid + 1, end);
    merge(list, start, end);
}
void mergeSort(int list[], int n) {
    mergeSortRec(list, 0, n - 1);
}
