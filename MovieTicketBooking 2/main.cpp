#include <iostream>
#include <string>
using namespace std;

// Stores information about one movie.
class Movie
{
private:
    int id;
    string name;
    string genre;
    int ticketPrice;

public:
    // Constructor
    Movie(int movieId, string movieName, string movieGenre, int price)
    {
        id = movieId;
        name = movieName;
        genre = movieGenre;
        ticketPrice = price;
    }

    void displayMovie()
    {
        cout << "Movie ID: " << id << endl;
        cout << "Movie: " << name << endl;
        cout << "Genre: " << genre << endl;
        cout << "Ticket price: Rs. " << ticketPrice << endl;
    }

    string getName()
    {
        return name;
    }

    int getTicketPrice()
    {
        return ticketPrice;
    }
};

// Displays all available movies.
void displayMovies(Movie movies[], int size)
{
    cout << "\n========== AVAILABLE MOVIES ==========\n";

    for (int i = 0; i < size; i++)
    {
        cout << "\nMovie " << i + 1 << endl;
        movies[i].displayMovie();
        cout << "--------------------------------------\n";
    }
}

int main()
{
    const int SIZE = 3;

    // An array of Movie objects.
    Movie movies[SIZE] = {
        Movie(101, "Interstellar", "Sci-Fi", 169),
        Movie(102, "Inception", "Sci-Fi", 148),
        Movie(103, "The Dark Knight", "Action", 152)
    };

    int choice;

    do
    {
        cout << "\n======================================\n";
        cout << "       MOVIE TICKET BOOKING SYSTEM\n";
        cout << "======================================\n";
        cout << "1. View Movies\n";
        cout << "2. Book Tickets\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayMovies(movies, SIZE);
            break;

        case 2:
        {
            int movieNumber;
            int numberOfTickets;

            displayMovies(movies, SIZE);

            cout << "Enter movie number (1-" << SIZE << "): ";
            cin >> movieNumber;

            if (movieNumber >= 1 && movieNumber <= SIZE)
            {
                cout << "Enter number of tickets: ";
                cin >> numberOfTickets;

                if (numberOfTickets > 0)
                {
                    int total = movies[movieNumber - 1].getTicketPrice()
                                * numberOfTickets;

                    cout << "\n========== BOOKING SUMMARY ==========\n";
                    cout << "Movie: "
                         << movies[movieNumber - 1].getName() << endl;
                    cout << "Number of tickets: " << numberOfTickets << endl;
                    cout << "Price per ticket: Rs. "
                         << movies[movieNumber - 1].getTicketPrice() << endl;
                    cout << "Total amount: Rs. " << total << endl;
                    cout << "Booking summary generated successfully.\n";
                }
                else
                {
                    cout << "Please enter at least one ticket.\n";
                }
            }
            else
            {
                cout << "Invalid movie number. Please try again.\n";
            }

            break;
        }

        case 3:
            cout << "Thank you for using the Movie Ticket Booking System!\n";
            break;

        default:
            cout << "Invalid choice. Please select 1, 2, or 3.\n";
        }

    } while (choice != 3);

    return 0;
}
