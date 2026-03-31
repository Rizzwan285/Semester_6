#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Here i have made the functions such that we are initializign 3 wards, without
taking user input. I have defined all the functions for the questions as follows
Im sorry i dont have any time left for more comments.
*/

struct Patient {
    int patient_id;
    char name[50];
    int age;
    char admission_date[20];
    char disease[50];
};

struct Ward {
    int ward_id;
    char ward_name[50];
    int total_beds;
    int occupied_beds;
    int admitted_patients[50];
};

struct WaitingList {
    int ward_id;
    int waiting_count;
    int waiting_patients[50];
};

struct Patient patient_db[100];
int patient_count = 0;
struct Ward wards[10];
int ward_count = 0;
struct WaitingList wait_lists[10];

void initializeWards() {
    ward_count = 3;
    wards[0].ward_id = 1014;
    strcpy(wards[0].ward_name, "General");
    wards[0].total_beds = 2;
    wards[0].occupied_beds = 0;
    wait_lists[0].ward_id = 101;
    wait_lists[0].waiting_count = 0;

    wards[1].ward_id = 102;
    strcpy(wards[1].ward_name, "ICU");
    wards[1].total_beds = 1;
    wards[1].occupied_beds = 0;
    wait_lists[1].ward_id = 102;
    wait_lists[1].waiting_count = 0;

    wards[2].ward_id = 103;
    strcpy(wards[2].ward_name, "Pediatric");
    wards[2].total_beds = 5;
    wards[2].occupied_beds = 0;
    wait_lists[2].ward_id = 103;
    wait_lists[2].waiting_count = 0;
}

int findWardIndex(int ward_id) {
    for (int i = 0; i < ward_count; i++) {
        if (wards[i].ward_id == ward_id) return i;
    }
    return -1;
}

int isAlreadyAdmitted(int p_id, int w_idx) {
    for (int i = 0; i < wards[w_idx].occupied_beds; i++) {
        if (wards[w_idx].admitted_patients[i] == p_id) return 1;
    }
    return 0;
}

void admitPatient() {
    struct Patient p;
    int w_id;
    printf("Enter Patient ID: ");
    scanf("%d", &p.patient_id);
    printf("Enter Name: ");
    scanf("%s", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Admission Date: ");
    scanf("%s", p.admission_date);
    printf("Enter Disease: ");
    scanf("%s", p.disease);
    printf("Enter Ward ID: ");
    scanf("%d", &w_id);

    int w_idx = findWardIndex(w_id);
    if (w_idx == -1) {
        printf("Invalid Ward ID\n");
        return;
    }

    patient_db[patient_count++] = p;

    if (isAlreadyAdmitted(p.patient_id, w_idx)) {
        printf("Patient already in this ward\n");
        return;
    }

    if (wards[w_idx].occupied_beds < wards[w_idx].total_beds) {
        wards[w_idx].admitted_patients[wards[w_idx].occupied_beds++] = p.patient_id;
        printf("Patient Admitted\n");
    } else {
        wait_lists[w_idx].waiting_patients[wait_lists[w_idx].waiting_count++] = p.patient_id;
        printf("Ward full. Added to waiting list\n");
    }
}

void dischargePatient(int p_id, int w_id) {
    int w_idx = findWardIndex(w_id);
    if (w_idx == -1) return;
    int found = -1;
    for (int i = 0; i < wards[w_idx].occupied_beds; i++) {
        if (wards[w_idx].admitted_patients[i] == p_id) {
            found = i;
            break;
        }
    }
    if (found != -1) {
        for (int i = found; i < wards[w_idx].occupied_beds - 1; i++) {
            wards[w_idx].admitted_patients[i] = wards[w_idx].admitted_patients[i + 1];
        }
        wards[w_idx].occupied_beds--;

        if (wait_lists[w_idx].waiting_count > 0) {
            int next_p = wait_lists[w_idx].waiting_patients[0];
            wards[w_idx].admitted_patients[wards[w_idx].occupied_beds++] = next_p;
            for (int i = 0; i < wait_lists[w_idx].waiting_count - 1; i++) {
                wait_lists[w_idx].waiting_patients[i] = wait_lists[w_idx].waiting_patients[i + 1];
            }
            wait_lists[w_idx].waiting_count--;
            printf("Waiting patient %d admitted automatically\n", next_p);
        }
        printf("Discharge successful\n");
    }
}

void wardReport() {
    int w_id;
    printf("Enter Ward ID: ");
    scanf("%d", &w_id);
    int w_idx = findWardIndex(w_id);
    if (w_idx == -1) return;
    printf("\nWard: %s | ID: %d | Beds: %d/%d\n", wards[w_idx].ward_name, wards[w_idx].ward_id, wards[w_idx].occupied_beds, wards[w_idx].total_beds);
    printf("Admitted Patients:\n");
    for (int i = 0; i < wards[w_idx].occupied_beds; i++) {
        int pid = wards[w_idx].admitted_patients[i];
        for (int j = 0; j < patient_count; j++) {
            if (patient_db[j].patient_id == pid) {
                printf("- ID: %d, Name: %s\n", patient_db[j].patient_id, patient_db[j].name);
            }
        }
    }
    printf("Waiting Count: %d\n", wait_lists[w_idx].waiting_count);
}

void searchPatient() {
    int p_id;
    printf("Enter Patient ID: ");
    scanf("%d", &p_id);
    for (int i = 0; i < patient_count; i++) {
        if (patient_db[i].patient_id == p_id) {
            printf("Name: %s, Age: %d, Disease: %s\n", patient_db[i].name, patient_db[i].age, patient_db[i].disease);
            for (int j = 0; j < ward_count; j++) {
                for (int k = 0; k < wards[j].occupied_beds; k++) {
                    if (wards[j].admitted_patients[k] == p_id) {
                        printf("Status: Admitted in %s\n", wards[j].ward_name);
                        return;
                    }
                }
                for (int k = 0; k < wait_lists[j].waiting_count; k++) {
                    if (wait_lists[j].waiting_patients[k] == p_id) {
                        printf("Status: In Waiting List for %s\n", wards[j].ward_name);
                        return;
                    }
                }
            }
            printf("Status: Not currently in any ward\n");
            return;
        }
    }
    printf("Patient not found\n");
}

void transferPatient() {
    int p_id, old_w_id, new_w_id;
    printf("Enter Patient ID: ");
    scanf("%d", &p_id);
    printf("Enter Current Ward ID: ");
    scanf("%d", &old_w_id);
    printf("Enter New Ward ID: ");
    scanf("%d", &new_w_id);

    int old_idx = findWardIndex(old_w_id);
    int new_idx = findWardIndex(new_w_id);

    if (old_idx == -1 || new_idx == -1) return;

    dischargePatient(p_id, old_w_id);

    if (wards[new_idx].occupied_beds < wards[new_idx].total_beds) {
        wards[new_idx].admitted_patients[wards[new_idx].occupied_beds++] = p_id;
        printf("Transferred and Admitted\n");
    } else {
        wait_lists[new_idx].waiting_patients[wait_lists[new_idx].waiting_count++] = p_id;
        printf("New ward full. Transferred to waiting list\n");
    }
}

int main() {
    initializeWards();
    int choice;
    while (1) {
        printf("\n1. Admit\n2. Discharge\n3. Ward Report\n4. Search\n5. Transfer\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 6) break;
        switch (choice) {
            case 1: admitPatient(); break;
            case 2: {
                int pid, wid;
                printf("ID: "); scanf("%d", &pid);
                printf("Ward ID: "); scanf("%d", &wid);
                dischargePatient(pid, wid);
                break;
            }
            case 3: wardReport(); break;
            case 4: searchPatient(); break;
            case 5: transferPatient(); break;
        }
    }
    return 0;
}