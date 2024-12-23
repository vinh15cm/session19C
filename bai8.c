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

// Ham sap xep sinh vien theo ten
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
    // Khoi tao mang sinh vien
    Student students[5] = {
        {1, "Nguyen Van C", 20, "0123456789"},
        {2, "Le Thi B", 21, "0987654321"},
        {3, "Tran Van A", 22, "0345678910"},
        {4, "Hoang Thi E", 19, "0567891234"},
        {5, "Pham Van D", 23, "0789123456"}
    };

    int length = 5;

    // In danh sach sinh vien ban dau
    printStudents(students, length);

    // Sap xep sinh vien theo ten
    sortStudentsByName(students, length);

    // In danh sach sinh vien sau khi sap xep
    printStudents(students, length);

    return 0;
}

