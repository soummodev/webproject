#ifndef BLOOD_H
#define BLOOD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USER_FILE "users.txt"
#define DONOR_FILE "donors.txt"
#define REQUEST_FILE "requests.txt"

#define TODAY_DAY   11
#define TODAY_MONTH 11
#define TODAY_YEAR  2025

struct user {
    char Name[50];
    int  Age;
    char Phone_num[20];
    char Password[20];
};
typedef struct user U;

struct donor {
    char Donor_Name[50];
    char Blood_group[5];
    char Phone_num[20];
    char Last_Donation_Date[20];
};
typedef struct donor D;

struct request {
    char Receiver_name[50];
    char Blood_group[5];
    char Phone_num[20];
    char Location[50];
};
typedef struct request R;

// Function prototypes
int  loaduser(const char *name, U *out);
void registerUser();
int  loginUser(char *username);
void donateBlood(char *username);
void requestBlood(char *username);
void viewDonors();
void viewRequests();
int  isEligibleSimple(const char *lastDonation);
void showMatchingDonors(const char *blood_group);
void changePassword(const char *username);

#endif
