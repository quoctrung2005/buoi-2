#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void nhap(int a[]);
void taoMangNgauNhienchan(int** a, int* n, int minSize);
void taoMangNgauNhien(int** a, int* n, int minSize);
int ls(int arr[], int n, int x);
void interchangeSort(int arr[], int n);
int bs(int a[], int n, int x);
void selectionSort(int arr[], int size);
int partition(int a[], int l, int r);
void quicksort(int a[], int l, int r);

int main() {
    int choice;
    int* a = NULL;
    int n = 0;
    int b[4];

    srand(time(NULL)); // Seed for random numbers

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap mang\n");
        printf("2. Tao mang ngau nhien chua so chan\n");
        printf("3. Tao mang ngau nhien\n");
        printf("4. Tim kiem tuyen tinh\n");
        printf("5. Sap xep mang (Interchange Sort)\n");
        printf("6. Tim kiem nhi phan (da sap xep)\n");
        printf("7. Sap xep mang (Selection Sort)\n");
        printf("8. Sap xep mang (Quick Sort)\n");
        printf("0. Thoat\n");
        printf("===============\n");
        printf("Chon chuc nang: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            nhap(b);
            printf("Mang da nhap:\n");
            for (int i = 0; i < 4; i++) {
                printf("%d ", b[i]);
            }
            break;
        case 2:
            free(a); // Free previous array, if any
            taoMangNgauNhienchan(&a, &n, 15);
            printf("Mang ngau nhien chua so chan co %d phan tu:\n", n);
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            break;
        case 3:
            free(a); // Free previous array, if any
            taoMangNgauNhien(&a, &n, 15);
            printf("Mang ngau nhien co %d phan tu:\n", n);
            for (int i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            break;
        case 4:
            if (n > 0) {
                int x;
                printf("Nhap gia tri can tim: ");
                scanf_s("%d", &x);
                int pos = ls(a, n, x);
                if (pos != -1) {
                    printf("Tim thay tai vi tri %d\n", pos);
                }
                else {
                    printf("Khong tim thay gia tri %d\n", x);
                }
            }
            else {
                printf("Mang chua duoc khoi tao.\n");
            }
            break;
        case 5:
            if (n > 0) {
                interchangeSort(a, n);
                printf("Mang sau khi sap xep (Interchange Sort):\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", a[i]);
                }
            }
            else {
                printf("Mang chua duoc khoi tao.\n");
            }
            break;
        case 6:
            if (n > 0) {
                int x;
                printf("Nhap gia tri can tim: ");
                scanf_s("%d", &x);
                int result = bs(a, n, x);
                if (result != -1) {
                    printf("Tim thay gia tri %d trong mang.\n", x);
                }
                else {
                    printf("Khong tim thay gia tri %d trong mang.\n", x);
                }
            }
            else {
                printf("Mang chua duoc khoi tao.\n");
            }
            break;
        case 7:
            selectionSort(b, 4);
            printf("Mang sau khi sap xep (Selection Sort):\n");
            for (int i = 0; i < 4; i++) {
                printf("%d ", b[i]);
            }
            break;
        case 8:
            quicksort(b, 0, 3);
            printf("Mang sau khi sap xep (Quick Sort):\n");
            for (int i = 0; i < 4; i++) {
                printf("%d ", b[i]);
            }
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }

    } while (choice != 0);

    free(a); 
    return 0;
}

void nhap(int a[]) {
    for (int i = 0; i < 4; i++) {
        printf("Nhap gia tri cho mang: ");
        scanf_s("%d", &a[i]);
    }
}

void taoMangNgauNhienchan(int** a, int* n, int minSize) {
    *n = minSize + rand() % 16;
    *a = (int*)malloc(*n * sizeof(int));
    if (*a == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    for (int i = 0; i < *n; i++) {
        (*a)[i] = (rand() % 50) * 2;
    }
}

void taoMangNgauNhien(int** a, int* n, int minSize) {
    *n = minSize + rand() % 16;
    *a = (int*)malloc(*n * sizeof(int));
    if (*a == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    for (int i = 0; i < *n; i++) {
        (*a)[i] = (rand() % 100);
    }
}

int ls(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

void interchangeSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int bs(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x)
            return 1;
        else if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void selectionSort(int arr[], int size) {
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int partition(int a[], int l, int r) {
    int i = l - 1, pivot = a[r];
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            ++i;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    ++i;
    int tmp = a[i];
    a[i] = a[r];
    a[r] = tmp;
    return i;
}

void quicksort(int a[], int l, int r) {
    if (l < r) {
        int pos = partition(a, l, r);
        quicksort(a, l, pos - 1);
        quicksort(a, pos + 1, r);
    }
}
