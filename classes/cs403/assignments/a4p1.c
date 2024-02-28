int compareDoubles(const void *a, const void *b) {
    double x = *(double *)a;
    double y = *(double *)b;
    if (x < y) {
        return -1;
    } else if (x > y) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    double arr[] = {5.0, 7.5, 1.2, 8.5, -9.3};
    qsort(arr, 5, sizeof(double), compareDoubles);
    for (int i = 0; i < 5; i++) {
        printf("%f\n", arr[i]);
    }
    return 0;
}