#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int phan_nguyen;
    int tu_so;
    int mau_so;
} HonSo;


HonSo tao_hon_so_ngau_nhien() {
    HonSo hs;
    hs.phan_nguyen = rand() % 21 - 10; // Tạo phần nguyên từ -10 đến 10
    hs.tu_so = rand() % 10 + 1; // Tạo tử số từ 1 đến 10
    hs.mau_so = rand() % 9 + 1; // Tạo mẫu số từ 1 đến 9
    return hs;
}


void xuat_hon_so(HonSo hs) {
    if (hs.phan_nguyen != 0) {
        printf("%d %d/%d", hs.phan_nguyen, hs.tu_so, hs.mau_so);
    }
    else {
        printf("%d/%d", hs.tu_so, hs.mau_so);
    }
}


int so_sanh_hon_so(HonSo a, HonSo b) {
    int mau_chung = a.mau_so * b.mau_so;
    int trai = (a.phan_nguyen * mau_chung) + (a.tu_so * b.mau_so);
    int phai = (b.phan_nguyen * mau_chung) + (b.tu_so * a.mau_so);
    return trai - phai;
}


void hon_so_sang_phan_so(HonSo hs, int* tu_so, int* mau_so) {
    *tu_so = hs.phan_nguyen * hs.mau_so + hs.tu_so;
    *mau_so = hs.mau_so;
}


HonSo phan_so_sang_hon_so(int tu_so, int mau_so) {
    HonSo hs;
    hs.phan_nguyen = tu_so / mau_so;
    hs.tu_so = tu_so % mau_so;
    hs.mau_so = mau_so;
    return hs;
}


HonSo tong_hon_so(HonSo a, HonSo b) {
    int tu_a, tu_b, mau_chung;
    hon_so_sang_phan_so(a, &tu_a, &mau_chung);
    tu_b = b.tu_so * a.mau_so + b.phan_nguyen * a.mau_so * b.mau_so;
    HonSo tong = phan_so_sang_hon_so(tu_a + tu_b, mau_chung);
    return tong;
}


HonSo hieu_hon_so(HonSo a, HonSo b) {
    int tu_a, tu_b, mau_chung;
    hon_so_sang_phan_so(a, &tu_a, &mau_chung);
    tu_b = b.tu_so * a.mau_so + b.phan_nguyen * a.mau_so * b.mau_so;
    HonSo hieu = phan_so_sang_hon_so(tu_a - tu_b, mau_chung);
    return hieu;
}


HonSo tich_hon_so(HonSo a, HonSo b) {
    int tu_a, tu_b, mau_chung;
    hon_so_sang_phan_so(a, &tu_a, &mau_chung);
    tu_b = b.tu_so * a.mau_so + b.phan_nguyen * a.mau_so * b.mau_so;
    HonSo tich = phan_so_sang_hon_so(tu_a * tu_b, mau_chung * b.mau_so);
    return tich;
}


HonSo thuong_hon_so(HonSo a, HonSo b) {
    int tu_a, tu_b, mau_chung;
    hon_so_sang_phan_so(a, &tu_a, &mau_chung);
    tu_b = b.tu_so * a.mau_so + b.phan_nguyen * a.mau_so * b.mau_so;
    HonSo thuong = phan_so_sang_hon_so(tu_a * b.mau_so, mau_chung * tu_b);
    return thuong;
}

void interchange_sort(HonSo arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (so_sanh_hon_so(arr[i], arr[j]) > 0) {
                HonSo temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selection_sort(HonSo arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (so_sanh_hon_so(arr[j], arr[min_idx]) < 0) {
                min_idx = j;
            }
        }
        HonSo temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}



int partition(HonSo arr[], int low, int high) {
    HonSo pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (so_sanh_hon_so(arr[j], pivot) < 0) {
            i++;
            HonSo temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    HonSo temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
void quick_sort(HonSo arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

int main() {
    srand(time(NULL));
    int n = 10;
    HonSo b[10];

    for (int i = 0; i < n; i++) {
        b[i] = tao_hon_so_ngau_nhien();
    }

    printf("Danh sach hon so:\n");
    for (int i = 0; i < n; i++) {
        xuat_hon_so(b[i]);
        printf("\n");
    }

    interchange_sort(b, n);
    printf("\nDanh sach sau khi sap xep tang dan bang InterchangeSort:\n");
    for (int i = 0; i < n; i++) {
        xuat_hon_so(b[i]);
        printf("\n");
    }

    selection_sort(b, n);
    printf("\nDanh sach sau khi sap xep tang dan bang SelectionSort:\n");
    for (int i = 0; i < n; i++) {
        xuat_hon_so(b[i]);
        printf("\n");
    }

    quick_sort(b, 0, n - 1);
    printf("\nDanh sach sau khi sap xep tang dan bang QuickSort:\n");
    for (int i = 0; i < n; i++) {
        xuat_hon_so(b[i]);
        printf("\n");
    }

    return 0;
}
