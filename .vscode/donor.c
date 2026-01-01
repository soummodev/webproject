#include "blood.h"

void donateBlood(char *username) {
    D *d = (D*) malloc(sizeof(D));
    FILE *fp = fopen(DONOR_FILE, "a");
    if (fp == NULL) { printf("File Failed To Open\n"); free(d); return; }

    printf("\n       Donate Blood   \n\n");
    strcpy(d->Donor_Name, username);

    printf("Blood Group: ");
    scanf("%4s", d->Blood_group);
    printf("Phone Number: ");
    scanf("%19s", d->Phone_num);
    printf("Last Donation Date (dd-mm-yyyy): ");
    scanf("%19s", d->Last_Donation_Date);

    fprintf(fp, "%s %s %s %s\n", d->Donor_Name, d->Blood_group, d->Phone_num, d->Last_Donation_Date);
    fclose(fp);
    free(d);
    printf("\nDonation recorded successfully!\n");
}

void requestBlood(char *username) {
    R *r = (R*) malloc(sizeof(R));
    FILE *fp = fopen(REQUEST_FILE, "a");
    if (fp == NULL) { printf("File Failed To Open\n"); free(r); return; }

    printf("\n       Request Blood   \n\n");
    strcpy(r->Receiver_name, username);

    printf("Blood Group: ");
    scanf("%4s", r->Blood_group);
    printf("Phone Number: ");
    scanf("%19s", r->Phone_num);
    printf("Location: ");
    scanf("%49s", r->Location);

    fprintf(fp, "%s %s %s %s\n", r->Receiver_name, r->Blood_group, r->Phone_num, r->Location);
    fclose(fp);
    free(r);
    printf("\nRequest submitted successfully!\n");
}

void viewDonors() {
    FILE *fp = fopen(DONOR_FILE, "r");
    if (fp == NULL) { printf("No donors available.\n"); return; }

    D d;
    printf("\n--- Donor List ---\n");
    while (fscanf(fp, "%49s %4s %19s %19s", d.Donor_Name, d.Blood_group, d.Phone_num, d.Last_Donation_Date) == 4) {
        printf("%s\t%s\t%s\t%s\n", d.Donor_Name, d.Blood_group, d.Phone_num, d.Last_Donation_Date);
    }
    fclose(fp);
}

void viewRequests() {
    FILE *fp = fopen(REQUEST_FILE, "r");
    if (fp == NULL) { printf("No requests available.\n"); return; }

    R r;
    printf("\n--- Blood Requests ---\n");
    while (fscanf(fp, "%49s %4s %19s %49s", r.Receiver_name, r.Blood_group, r.Phone_num, r.Location) == 4) {
        printf("%s\t%s\t%s\t%s\n", r.Receiver_name, r.Blood_group, r.Phone_num, r.Location);
    }
    fclose(fp);
}
