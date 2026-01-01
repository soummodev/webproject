#include "blood.h"

int main() {
    int loggedIn = 0, choice;
    char username[50];
    while (1) {
        if (!loggedIn) {
            printf("\n                 BLOOD GROUP MANAGEMENT SYSTEM    \n\n");
            printf("1. Register\t\t2. Login\t\t3. Exit\n\n");
            printf("Enter choice: ");
            scanf("%d",&choice);

            if (choice == 1)
                registerUser();
            else if (choice == 2)
                loggedIn = loginUser(username);
            else if (choice == 3)
                break;
            else
                printf("Invalid choice!\n");
        } else {
            printf("\n Welcome %s \n\n", username);
            printf("1. Donate Blood\t 2. Request Blood\t3. View Donors\t4. View Requests\t5. Change Password\t6. Logout\n\n");
            printf("Enter choice: ");scanf("%d",&choice);
            if (choice == 1)
                donateBlood(username);
            else if (choice == 2)
                requestBlood(username);
            else if (choice == 3)
                viewDonors();
            else if (choice == 4)
                viewRequests();
            else if (choice == 5)
                changePassword(username);
            else if (choice == 6)
                loggedIn = 0;
            else
                printf("Invalid choice!\n");
        }
    }

    printf("\n\nThank you for using our system made by Julfikar,Soummo&Deepon\n");
    return 0;
}
