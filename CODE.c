#include <stdio.h>
#include <stdlib.h>

// Constants
#define NUM_MOVIES 3
#define MAX_SEATS 50

// Movie structure to store movie information
struct Movie {
    char title[50];
    int availableSeats;
};

// Function to display available movies
void displayMovies(struct Movie movies[]) {
    printf("Available Movies:\n");
    for (int i = 0; i < NUM_MOVIES; ++i) {
        printf("%d. %s\n", i + 1, movies[i].title);
    }
}

// Function to display seating arrangement
void displaySeating(int seats[]) {
    printf("Seating Arrangement:\n");
    for (int i = 0; i < MAX_SEATS; ++i) {
        printf("%c ", (seats[i] == 0) ? '_' : 'X');
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

// Function to check seat availability
int checkAvailability(int seats[], int numSeats) {
    for (int i = 0; i < MAX_SEATS; ++i) {
        int consecutiveEmpty = 0;
        while (i < MAX_SEATS && seats[i] == 0) {
            ++consecutiveEmpty;
            ++i;
            if (consecutiveEmpty == numSeats) {
                return i - numSeats;
            }
        }
    }
    return -1; // Not enough consecutive seats
}

// Function to book tickets
void bookTicket(int seats[], int startSeat, int numSeats) {
    for (int i = startSeat; i < startSeat + numSeats; ++i) {
        seats[i] = 1; // Mark seats as booked
    }
}

// Function to handle payment
void processPayment() {
    // Placeholder for payment processing logic
    printf("Payment successful! Tickets booked.\n");
}

int main() {
    int choice, tickets;

    struct Movie movies[NUM_MOVIES] = {
        {"Avengers: Endgame", MAX_SEATS},
        {"The Shawshank Redemption", MAX_SEATS},
        {"The Godfather", MAX_SEATS}
    };

    int seats[MAX_SEATS] = {0}; // 0 represents an empty seat

    printf("Welcome to the Movie Ticket Booking System!\n");

    // Display available movies
    displayMovies(movies);

    // Get user input for movie choice
    printf("\nEnter the number corresponding to the movie you want to watch: ");
    scanf("%d", &choice);

    // Display seating arrangement
    displaySeating(seats);

    // Get user input for the number of tickets
    printf("\nEnter the number of tickets you want to book: ");
    scanf("%d", &tickets);

    // Check seat availability
    int startSeat = checkAvailability(seats, tickets);
    if (startSeat != -1) {
        // Seats are available, book tickets
        bookTicket(seats, startSeat, tickets);

        // Display updated seating arrangement
        printf("\nSeating arrangement after booking:\n");
        displaySeating(seats);

        // Process payment
        processPayment();
    } else {
        printf("\nSorry, there are not enough consecutive seats available.\n");
    }

    return 0;
}
