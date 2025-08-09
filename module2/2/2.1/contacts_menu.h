#define MAX_NAME_LEN 20
#define MAX_PHONE_NUMBER_LEN 12
#define MAX_BIRTHDAY_LEN 11
#define MAX_CONTACTS 10

typedef struct Person {
    char firstName[MAX_NAME_LEN];
    char lastName[MAX_NAME_LEN];
    int phone [MAX_PHONE_NUMBER_LEN];
    char birthday [MAX_BIRTHDAY_LEN];
    struct Work {
        char place[MAX_NAME_LEN];
        char post[MAX_NAME_LEN];
    } Work;
} Person;

void PersonInit ();
void ListPrint();
void ContactDelete();
void ContactEdit();
