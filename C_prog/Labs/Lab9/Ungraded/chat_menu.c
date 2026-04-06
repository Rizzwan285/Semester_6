#include <stdio.h>
#include <string.h>

struct Message {
    int msg_id;
    char sender[50];
    char content[200];
};

struct Message msgs[100];
int msg_count = 0;

int findMsg(int id) {
    for (int i = 0; i < msg_count; i++) {
        if (msgs[i].msg_id == id) return i;
    }
    return -1;
}

void addMessage() {
    printf("Enter ID: ");
    scanf("%d", &msgs[msg_count].msg_id);

    printf("Enter Sender: ");
    scanf("%s", msgs[msg_count].sender);

    getchar();
    printf("Enter Message: ");
    fgets(msgs[msg_count].content, 200, stdin);

    msg_count++;
}

void deleteMessage() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    int idx = findMsg(id);
    if (idx == -1) return;

    for (int i = idx; i < msg_count - 1; i++) {
        msgs[i] = msgs[i + 1];
    }

    msg_count--;
}

void searchSender() {
    char name[50];
    printf("Enter sender: ");
    scanf("%s", name);

    for (int i = 0; i < msg_count; i++) {
        if (strcmp(msgs[i].sender, name) == 0) {
            printf("%d: %s\n", msgs[i].msg_id, msgs[i].content);
        }
    }
}

void displayMessages() {
    for (int i = 0; i < msg_count; i++) {
        printf("%d %s %s",
               msgs[i].msg_id,
               msgs[i].sender,
               msgs[i].content);
    }
}

void countWords() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    int idx = findMsg(id);
    if (idx == -1) return;

    int count = 0;
    char *token = strtok(msgs[idx].content, " ");

    while (token) {
        count++;
        token = strtok(NULL, " ");
    }

    printf("Words = %d\n", count);
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Add 2.Delete 3.Search 4.Display 5.CountWords 6.Exit\n");
        scanf("%d", &choice);

        if (choice == 6) break;

        switch (choice) {
            case 1: addMessage(); break;
            case 2: deleteMessage(); break;
            case 3: searchSender(); break;
            case 4: displayMessages(); break;
            case 5: countWords(); break;
        }
    }

    return 0;
}