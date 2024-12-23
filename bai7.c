#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

// Ham in danh sach sinh vien
void printStudents(Student students[], int length) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < length; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", 
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

// Ham xoa sinh vien
void deleteStudentById(Student students[], int *currentLength, int id) {
    int found = -1;
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("\nKhong tim thay sinh vien voi ID %d.\n", id);
        return;
    }

    // Di chuyen cac phan tu sau vi tri can xoa
    for (int i = found; i < *currentLength - 1; i++) {
        students[i] = students[i + 1];
    }

    (*currentLength)--;
    printf("\nDa xoa sinh vien voi ID %d.\n", id);
}

int main() {
    // Khoi tao mang sinh vien
    Student students[50] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Le Thi B", 21, "0987654321"},
        {3, "Tran Van C", 22, "0345678910"},
        {4, "Hoang Thi D", 19, "0567891234"},
        {5, "Pham Van E", 23, "0789123456"}
    };
    int currentLength = 5;

    // In danh sach sinh vien ban dau
    printStudents(students, currentLength);

    // Xoa sinh vien theo ID
    int idToDelete;
    printf("\nNhap ID sinh vien muon xoa: ");
    scanf("%d", &idToDelete);
    deleteStudentById(students, &currentLength, idToDelete);

    // In danh sach sinh vien sau khi xoa
    printStudents(students, currentLength);

    return 0;
}

