#include "blood.h"

void registerUser() {
    U *u = (U*) malloc(sizeof(U));
    FILE *fp = fopen(USER_FILE, "a");
    if (fp == NULL) { printf("File Failed To Open\n"); free(u); return; }
    printf("\n                     Registration::  \n\n");

    getchar();
    printf("Name(Short): ");
    fgets(u->Name, sizeof(u->Name), stdin);
    u->Name[strcspn(u->Name, "\n")] = '\0';

    printf("Age: ");
    scanf("%d", &u->Age);

    printf("Phone Num: ");
    scanf("%19s", u->Phone_num);

    printf("Password: ");
    scanf("%19s", u->Password);

    fprintf(fp, "%s %d %s %s\n", u->Name, u->Age, u->Phone_num, u->Password);
    fclose(fp);
    free(u);
    printf("\n\n            Registration successful!\n");
}

int loginUser(char *username) {
    U u;
    char name[50], pass[20];
    FILE *fp;
    int flag = 0;

    printf("\n                     Login:    \n\n");

    getchar();
    printf("Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = '\0';

    fp = fopen(USER_FILE, "r");
    if (fp == NULL) {
        printf("File Failed To Open Or No User Registered Yet!\n");
        return 0;
    }

    while (fscanf(fp, "%49s %d %19s %19s", u.Name, &u.Age, u.Phone_num, u.Password) == 4) {
        if (strcmp(name, u.Name) == 0 && strcmp(pass, u.Password) == 0) {
            strcpy(username, name);
            flag = 1;
            break;
        }
    }
    fclose(fp);

    if (!flag) printf("Invalid username or password! Please try again \n");
    else       printf("      Login successful  \n");

    return flag;
}

void changePassword(const char *username) {
    U u;
    FILE *fp = fopen(USER_FILE, "r");
    if (!fp) { printf("File open failed!\n"); return; }

    int found = 0;
    while (fscanf(fp, "%49s %d %19s %19s",
                  u.Name, &u.Age, u.Phone_num, u.Password) == 4) {
        if (strcmp(u.Name, username) == 0) { found = 1; break; }
    }
    fclose(fp);

    if (!found) { printf("User not found!\n"); return; }

    char oldpass[20], newpass[20];
    int attempts = 0, ok = 0;

    while (attempts < 3) {
        printf("\nEnter old password: ");
        scanf("%19s", oldpass);

        if (strcmp(oldpass, u.Password) == 0) { ok = 1; break; }
        attempts++;
        if (attempts < 3) printf("Wrong password! Try again.\n");
    }

    if (!ok) {
        printf("Too many wrong attempts. Password not changed.\n");
        return;
    }

    printf("Enter new password: ");
    scanf("%19s", newpass);

    fp = fopen(USER_FILE, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        printf("File open failed!\n");
        if (fp) fclose(fp);
        if (temp) fclose(temp);
        return;
    }

    U cur;
    while (fscanf(fp, "%49s %d %19s %19s",
                  cur.Name, &cur.Age, cur.Phone_num, cur.Password) == 4) {
        if (strcmp(cur.Name, username) == 0) {
            strcpy(cur.Password, newpass);
        }
        fprintf(temp, "%s %d %s %s\n",
                cur.Name, cur.Age, cur.Phone_num, cur.Password);
    }

    fclose(fp);
    fclose(temp);
    remove(USER_FILE);
    rename("temp.txt", USER_FILE);

    printf("Password updated successfully!\n");
}
