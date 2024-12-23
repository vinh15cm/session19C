#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

int currentLength = 5;

// In danh sach sinh vien
void printStudents(Student students[], int length) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < length; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", 
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

// Them sinh vien
void addStudent(Student students[], int *length) {
    if (*length >= MAX) {
        printf("\nDanh sach sinh vien da day.\n");
        return;
    }
    Student newStudent;
    newStudent.id = *length + 1;
    printf("Nhap ten: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Nhap tuoi: ");
    scanf("%d", &newStudent.age);
    printf("Nhap so dien thoai: ");
    scanf(" %[^\n]", newStudent.phoneNumber);
    students[*length] = newStudent;
    (*length)++;
    printf("\nThem sinh vien thanh cong!\n");
}

// Sua thong tin sinh vien
void editStudent(Student students[], int length) {
    int id;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);
    for (int i = 0; i < length; i++) {
        if (students[i].id == id) {
            printf("Nhap ten moi: ");
            scanf(" %[^\n]", students[i].name);
            printf("Nhap tuoi moi: ");
            scanf("%d", &students[i].age);
            printf("\nSua thong tin thanh cong!\n");
            return;
        }
    }
    printf("\nKhong tim thay sinh vien co ID %d.\n", id);
}

// Xoa sinh vien
void deleteStudent(Student students[], int *length) {
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    for (int i = 0; i < *length; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *length - 1; j++) {
                students[j] = students[j + 1];
            }
            (*length)--;
            printf("\nXoa sinh vien thanh cong!\n");
            return;
        }
    }
    printf("\nKhong tim thay sinh vien co ID %d.\n", id);
}

// Tim kiem sinh vien
void searchStudent(Student students[], int length) {
    char name[50];
    printf("Nhap ten sinh vien can tim: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < length; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("\nSinh vien tim thay:\n");
            printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", 
                   students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
            return;
        }
    }
    printf("\nKhong tim thay sinh vien co ten %s.\n", name);
}

// Sap xep danh sach sinh vien
void sortStudentsByName(Student students[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("\nDa sap xep sinh vien theo ten.\n");
}

int main() {
    Student students[MAX] = {
        {1, "Nguyen Van C", 20, "0123456789"},
        {2, "Le Thi B", 21, "0987654321"},
        {3, "Tran Van A", 22, "0345678910"},
        {4, "Hoang Thi E", 19, "0567891234"},
        {5, "Pham Van D", 23, "0789123456"}
    };

    int choice;
    while (1) {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printStudents(students, currentLength);
                break;
            case 2:
                addStudent(students, &currentLength);
                break;
            case 3:
                editStudent(students, currentLength);
                break;
            case 4:
                deleteStudent(students, &currentLength);
                break;
            case 5:
                searchStudent(students, currentLength);
                break;
            case 6:
                sortStudentsByName(students, currentLength);
                printStudents(students, currentLength);
                break;
            case 7:
                printf("\nThoat chuong trinh.\n");
                return 0;
            default:
                printf("\nLua chon khong hop le. Vui long chon lai.\n");
        }
    }
}

