#include "blood.h"

int isEligibleSimple(const char *lastDonation) {
    int d=0, m=0, y=0;
    if (sscanf(lastDonation, "%d-%d-%d", &d,&m,&y) != 3) return 1;
    int totalNow  = TODAY_YEAR*12 + TODAY_MONTH;
    int totalLast = y*12 + m;
    if (totalNow - totalLast > 3) return 1;
    if (totalNow - totalLast == 3 && TODAY_DAY >= d) return 1;
    return 0;
}

int loaduser(const char *name, U *out) {
    FILE *fp = fopen(USER_FILE, "r");
    if (fp==NULL) return 0;
    U u;
    while (fscanf(fp, "%49s %d %19s %19s", u.Name, &u.Age, u.Phone_num, u.Password) == 4) {
        if (strcmp(name, u.Name) == 0) {
            if (out) *out = u;
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
    //i have changed 
}
