#include <stdio.h>
#define MAX 50
int roomNumber[MAX]={0};
float rentPerDay[MAX];
int daysStayed[MAX];
int count = 0;

/*
So basically here when the booking is added, the count variable is added by 1
and then we ask the user for the number of days he is going to stay. 
We initialize a flag variable as 0 to check if rooms are available. Then we
are going to iterate through the roomNumber array such that we find a room
where the value is not 1. That means the room is available. When we find the
avaiable room we we set that index value to 1 in the roomNUmber array and 
daysStayed array. Then we update the correspondiung index of the RentPerDay 
array to the rent calculated as 300 times the number of days spent considering 
the discount mentioned in the question. Once we find the room, we set the flag
to 1. If the flag is still 0 after the loop is done, that means there are
no available rooms. 
*/

/* Function to Add Booking */
void addBooking(){
    printf("How many days are you going to stay? ");
    int days;
    scanf("%d", &days);
    int flag=0;
    int roomno;
    for (int i=0; i<50; i++) {
        if (roomNumber[i]==1) {
            continue;
        }
        else {
            roomNumber[i]=1;
            daysStayed[i]=days;
                if (days>3) rentPerDay[i]=days*300*0.8;
                else rentPerDay[i]=days*300;
            flag = 1;
            roomno=i;
            break;
        }
    }
    if (flag==0) printf("Booking Unavailable\n");
    else printf("Room added successfully.\nYour Room Number is %d and your Rent is %f\n", roomno, rentPerDay[roomno]);
    count+=1;
}

/*
Here we iterate through the roomNumber array, finding all values which are 1,
to get the booked rooms, and we print the corresponding Days Stayed and
Rent Due using the same index as the room number.
*/

/* Function to Display All Bookings */
void displayBookings(){
    printf("Displaying All Bookings:\n\n");
    for (int i=0; i<50; i++) {
        if (roomNumber[i]==1) {
            printf("Room Number: %d, Days Stayed: %d, Due Rent: %.2f\n",
            i,daysStayed[i], rentPerDay[i]);
        }
    }
}

/*
Here we just ask the user to input their room number and then return the
corresponding room rent using that as index.
*/

/* Function to Calculate Total Bill */
float calculateBill(){
    int roomNo;
    printf("Enter your Room Number: ");
    scanf("%d", &roomNo);
    if (roomNumber[roomNo] == 1) {
        return rentPerDay[roomNo];
    }
}

/*
Here we just ask the user to input their room number as input and then
we set the correspoing value in that index of all the array to 0.
*/

/* Function to Cancel Booking */
void cancelBooking(){
    int roomNo;
    printf("Enter Room Number: ");
    scanf("%d", &roomNo);
    roomNumber[roomNo]=0;
    rentPerDay[roomNo]=0;
    daysStayed[roomNo]=0;
    count-=1;
    printf("Room cancelled successfully!!!\n");
}

/* Main Function */
int main() {
    int choice;

    do {
        printf("\n--- Hotel Booking Management System ---\n");
        printf("1. Add Booking\n");
        printf("2. View Bookings\n");
        printf("3. Calculate Total Bill\n");
        printf("4. Cancel Booking\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                addBooking();
                break;
            
            case 2:
                displayBookings();
                break;
        
            case 3:
                printf("Total Bill = %.2f\n", calculateBill());
                break;
            case 4:
                cancelBooking();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    
    } while(choice != 5);
    
    return 0;
}