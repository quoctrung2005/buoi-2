#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

const int MAX_SIZE = 20;

void createRandomArray(int a[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100;
    }
}


void printArray(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


int isPrime(int number) {
    if (number < 2) {
        return 0; // Không ph?i s? nguyên t?
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return 0; // Không ph?i s? nguyên t?
        }
    }
    return 1; // Là s? nguyên t?
}


void findPrimesLessThan(int n) {
    int foundPrime = 0;
    printf("Cac so nguyen to nho hon %d: ", n);
    for (int i = 2; i < n; ++i) {
        if (isPrime(i)) {
            printf("%d ", i);
            foundPrime = 1;
        }
    }
    if (!foundPrime) {
        printf("Khong ton tai so nguyen to nao nho hon %d.", n);
    }
    printf("\n");
}


int sumOfFirstDigitOdd(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int firstDigit = abs(a[i]);
        while (firstDigit >= 10) {
            firstDigit /= 10;
        }
        if (firstDigit % 2 != 0) {
            sum += a[i];
        }
    }
    return sum;
}


void countOccurrences(int a[], int n) {
    printf("So lan xuat hien cua cac phan tu trong mang:\n");
    for (int i = 0; i < n; ++i) {
        int count = 1;
        if (a[i] != -1) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] == a[j]) {
                    count++;
                    a[j] = -1;
                }
            }
            printf("%d xuat hien %d lan\n", a[i], count);
        }
    }
}


void sortEvenOdd(int a[], int n) {
    int evenCount = 0;
    int oddCount = 0;
    int even[MAX_SIZE], odd[MAX_SIZE];

    // Phân lo?i ph?n t? ch?n và l?
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            even[evenCount++] = a[i];
        }
        else {
            odd[oddCount++] = a[i];
        }
    }


    for (int i = 0; i < evenCount - 1; ++i) {
        for (int j = i + 1; j < evenCount; ++j) {
            if (even[i] > even[j]) {
                int temp = even[i];
                even[i] = even[j];
                even[j] = temp;
            }
        }
    }


    for (int i = 0; i < oddCount - 1; ++i) {
        for (int j = i + 1; j < oddCount; ++j) {
            if (odd[i] < odd[j]) {
                int temp = odd[i];
                odd[i] = odd[j];
                odd[j] = temp;
            }
        }
    }


    int index = 0;
    for (int i = 0; i < evenCount; ++i) {
        a[index++] = even[i];
    }
    for (int i = 0; i < oddCount; ++i) {
        a[index++] = odd[i];
    }
}


void longestDecreasingSubarray(int a[], int n) {
    int maxLen = 1;
    int currentLen = 1;
    int endIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            currentLen++;
        }
        else {
            if (currentLen > maxLen) {
                maxLen = currentLen;
                endIndex = i - 1;
            }
            currentLen = 1;
        }
    }


    if (currentLen > maxLen) {
        maxLen = currentLen;
        endIndex = n - 1;
    }


    printf("Day con giam dai nhat trong mang la: ");
    for (int i = endIndex - maxLen + 1; i <= endIndex; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


int secondSmallest(int a[], int n) {
    if (n < 2) {
        printf("Mang khong du so phan tu de tim so nho thu 2.\n");
        return -1;
    }

    int first, second;
    first = second = INT_MAX;

    for (int i = 0; i < n; ++i) {
        if (a[i] < first) {
            second = first;
            first = a[i];
        }
        else if (a[i] < second && a[i] != first) {
            second = a[i];
        }
    }

    return second;
}


int containsDigits(int number, int x) {
    while (x > 0) {
        int digit = x % 10;
        int found = 0;
        int temp = number;
        while (temp > 0) {
            if (temp % 10 == digit) {
                found = 1;
                break;
            }
            temp /= 10;
        }
        if (!found) {
            return 0;
        }
        x /= 10;
    }
    return 1;
}


void sortEvenAscending(int a[], int n) {
    int evenIdx = 0;
    int temp[MAX_SIZE];


    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            temp[evenIdx++] = a[i];
        }
    }


    for (int i = 0; i < evenIdx - 1; ++i) {
        for (int j = i + 1; j < evenIdx; ++j) {
            if (temp[i] > temp[j]) {
                int swap = temp[i];
                temp[i] = temp[j];
                temp[j] = swap;
            }
        }
    }


    int idx = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            a[i] = temp[idx++];
        }
    }
}


void sortOddEven(int a[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {

        while (a[left] % 2 != 0 && left < right) {
            left++;
        }

        while (a[right] % 2 == 0 && left < right) {
            right--;
        }

        if (left < right) {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
            left++;
            right--;
        }
    }
}


void displayMenu(int a[], int n) {
    int choice;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Liet ke cac so nguyen to nho hon n\n");
        printf("2. Tinh tong cac phan tu co chu so dau la chu so le\n");
        printf("3. Liet ke so lan xuat hien cua cac phan tu trong mang\n");
        printf("4. Sap xep mang co so chan tang dan, so le giam dan\n");
        printf("5. Tim day con giam dai nhat trong mang\n");
        printf("6. Tim so nho thu 2 trong mang\n");
        printf("7. Tim cac phan tu chua cac chu so cua x\n");
        printf("8. Sap xep mang sao cho cac phan tu chan tang dan, cac phan tu le giu nguyen vi tri\n");
        printf("9. Sap xep mang: so le o dau mang, so chan o cuoi mang\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");

        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap vao so nguyen n: ");
            int num;
            scanf_s("%d", &num);
            findPrimesLessThan(num);
            break;
        case 2:
            printf("Tong cac phan tu co chu so dau la chu so le: %d\n", sumOfFirstDigitOdd(a, n));
            break;
        case 3:
            countOccurrences(a, n);
            break;
        case 4:
            sortEvenOdd(a, n);
            printf("Mang sau khi sap xep co so chan tang dan, so le giam dan: ");
            printArray(a, n);
            break;
        case 5:
            longestDecreasingSubarray(a, n);
            break;
        case 6:
            printf("So nho thu 2 trong mang la: %d\n", secondSmallest(a, n));
            break;
        case 7:
            printf("Nhap so x (2 chu so): ");
            int x;
            scanf_s("%d", &x);
            printf("Cac phan tu trong mang chua cac chu so cua %d:\n", x);
            for (int i = 0; i < n; ++i) {
                if (containsDigits(a[i], x)) {
                    printf("%d ", a[i]);
                }
            }
            printf("\n");
            break;
        case 8:
            sortEvenAscending(a, n);
            printf("Mang sau khi sap xep cac so chan tang dan, giu nguyen vi tri cac so le: ");
            printArray(a, n);
            break;
        case 9:
            sortOddEven(a, n);
            printf("Mang sau khi sap xep so le o dau, so chan o cuoi: ");
            printArray(a, n);
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (choice != 0);
}

int main() {
    int a[MAX_SIZE];
    int n = 15 + rand() % 100;

    createRandomArray(a, n);
    printf("Mang ngau nhien da tao: ");
    printArray(a, n);

    displayMenu(a, n);

    return 0;
}