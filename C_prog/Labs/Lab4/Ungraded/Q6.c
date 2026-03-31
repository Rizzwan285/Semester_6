#include <stdio.h>

// Function Prototypes (as required by the lab sheet)
float increasePrice(float price);
float cartTotal(float prices[], int n);
void applyDiscount(float prices[], int n);
float findMaxPrice(float prices[], int n);
void printPrices(float prices[], int n);

int main() {
    int n, choice, index;
    float prices[100]; // Max size of 100 products

    // 1. Take input for number of products [cite: 25]
    printf("Enter number of products: ");
    scanf("%d", &n);

    // 2. Read the prices of all products [cite: 26]
    printf("Enter product prices:\n");
    for (int i = 0; i < n; i++) {
        printf("Price for product %d: ", i);
        scanf("%f", &prices[i]);
    }

    // 3. Menu-driven logic [cite: 27, 53]
    do {
        printf("\n--- Smart Store Menu ---\n");
        printf("1. Increase price of one product by 10%%\n");
        printf("2. Calculate total cart value\n");
        printf("3. Apply flat 20 discount to all items\n");
        printf("4. Find most expensive item\n");
        printf("5. Show all prices\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // 4. Switch for menu handling [cite: 54]
        switch (choice) {
            case 1:
                printf("Enter index of product to increase (0 to %d): ", n - 1);
                scanf("%d", &index);
                // Validate product index [cite: 55]
                if (index >= 0 && index < n) {
                    // Update the array using the return value
                    prices[index] = increasePrice(prices[index]);
                    printf("Price updated successfully.\n");
                } else {
                    printf("Invalid index!\n");
                }
                break;

            case 2:
                printf("Total Cart Value: %.2f\n", cartTotal(prices, n));
                break;

            case 3:
                applyDiscount(prices, n);
                printf("Flat 20 discount applied to all items.\n");
                break;

            case 4:
                printf("Most Expensive Item Price: %.2f\n", findMaxPrice(prices, n));
                break;

            case 5:
                printPrices(prices, n);
                break;

            case 6:
                printf("Exiting Smart Store. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6); // Continue until Exit [cite: 28]

    return 0;
}

// Function 1: Increase Price (Returns updated value) [cite: 40]
float increasePrice(float price) {
    return price + (price * 0.10);
}

// Function 2: Cart Total (Returns sum) [cite: 43]
float cartTotal(float prices[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += prices[i];
    }
    return total;
}

// Function 3: Apply Discount (Flat 20 off) [cite: 45]
void applyDiscount(float prices[], int n) {
    for (int i = 0; i < n; i++) {
        prices[i] = prices[i] - 20;
        // Optional: Ensure price doesn't go negative
        if (prices[i] < 0) prices[i] = 0;
    }
}

// Function 4: Find Maximum Price [cite: 47]
float findMaxPrice(float prices[], int n) {
    float max = prices[0];
    for (int i = 1; i < n; i++) {
        if (prices[i] > max) {
            max = prices[i];
        }
    }
    return max;
}

// Function 5: Print Prices [cite: 50]
void printPrices(float prices[], int n) {
    printf("Current Prices: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", prices[i]);
    }
    printf("\n");
}