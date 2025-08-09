#include <stdio.h>
#include <string.h>
#include "abonents_menu.h"

struct Person contacts[MAX_CONTACTS];
int counter = 0;

void PersonInit () {
    if (counter >= MAX_CONTACTS) {
        printf("Телефонная книга переполнена!\n\n");
        return;
    }
    Person p;
    printf("Имя: ");
    scanf("%s", p.firstName);

    printf("Фамилия: ");
    scanf("%s", p.lastName);

    printf("Заполним остальные поля? Y/n ");
    char answer;
    while (answer != 'Y' && answer != 'n') {scanf("%c", &answer);}
    
    if (answer == 'Y') {
        printf("Телефон (формат: +7xxxxxxxxxx): ");
        scanf("%s", p.phone);

        printf("День рождения (формат: DD.MM.YYYY): ");
        scanf("%s", p.birthday);

        printf("Место работы/учебы: ");
        scanf("%s", p.Work.place);

        printf("Занимаемая должность: ");
        scanf("%s", p.Work.post);
    }

    contacts[counter] = p; 
    counter++;
    printf("Контакт успешно добавлен!\n\n");
}
void ListPrint() {
    for(int i = 0; i < counter; i ++) {
        printf("\nКонтакт %d:\n\
        Имя: %s %s\n\
        Номер телефона: %s\n\
        День рождения: %s\n\
        Место работы/учебы: %s\n\
        Занимаемая должность: %s\n\n",
        i+1, contacts[i].lastName, contacts[i].firstName,
        contacts[i].phone, contacts[i].birthday,
        contacts[i].Work.place, contacts[i].Work.post);
    }
    if (counter == 0) {
        printf("Телефонная книга пуста!\n\n");
        return;
    }
};
void ContactDelete() {
    ListPrint();
    printf("\nВыберите номер контакта который нужно удалить: ");
    int contactNum1;
    scanf("%d", &contactNum1);
    for(int k = contactNum1-1; k < counter; k++) {
        contacts[k] = contacts[k+1];
    }
    counter--;
    printf("\nКонтакт %d успешно удален!\n\n", contactNum1);
};
void ContactEdit() {
    ListPrint();
    printf("\nВыберите номер контакта который нужно изменить: ");
    int contactNum2;
    scanf("%d", &contactNum2);
    printf("\nКонтакт %d: \n    Имя: %s %s\n",
        contactNum2, contacts[contactNum2-1].lastName,
        contacts[contactNum2-1].firstName);
    printf("\n1. Фамилия\n2. Имя\n3. Номер телефона\n\
        4. День рождения\n5. Место работы/учебы\n\
        6. Занимаемая должность\n0. назад\n\
        \nВыберите поле которое нужно изменить: ");
    int choice1;
    scanf("%d", &choice1);
    switch (choice1){
            case 1: 
                printf("Введите новую фамилию: ");
                scanf("%s", contacts[contactNum2-1].lastName);
                printf("Фамилия успешно изменена!\n");
                break;
            case 2: 
                printf("Введите новое имя: ");
                scanf("%s", contacts[contactNum2-1].firstName);
                printf("Имя успешно изменено!\n");
                break;
             case 3: 
                printf("Введите новый номер телефона: ");
                scanf("%s", contacts[contactNum2-1].phone);
                printf("Номер телефона успешно изменен!\n");
                break;
            case 4: 
                printf("Введите новую дату рождения: ");
                scanf("%s", contacts[contactNum2-1].birthday);
                printf("Дата рождения успешно изменена!\n");
                break;
            case 5: 
                printf("Введите новое место работы/учебы: ");
                scanf("%s", contacts[contactNum2-1].lastName);
                printf("Место успешно изменено!\n");
                break;
            case 6: 
                printf("Введите новую должность: ");
                scanf("%s", contacts[contactNum2-1].lastName);
                printf("Должность успешно изменена!\n");
                break;   
            case 0:
                break;
            default:
                printf("\nНеверный ввод\n\n");
                break;
        }
};

int main(void) {    
    int choice = 1;
    while(choice != 0) {
        printf("1. Добавить контакт\n");
        printf("2. Вывести контакты\n");
        printf("3. Удалить контакт\n");
        printf("4. Изменить контакт\n");
        printf("0. Выход\n\n");

        printf("Введите число: ");
        scanf("%d", &choice);
        switch (choice){
            case 1: 
                PersonInit();
                break;
            case 2: 
                ListPrint();
                break;
            case 3:
                ContactDelete();
                break;
            case 4:
                ContactEdit();
                break;
            case 0: 
                return 0;
                break;
            default:
                printf("\nНеверный ввод\n\n");
                break;
        }
    }
    return 0;                       
}     