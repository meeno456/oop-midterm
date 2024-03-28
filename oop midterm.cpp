#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
    class Reservation {
    public:
        string customerName;
        int timeSlot;
        int numofpeople;

        Reservation(string name, int slot, int size)
            : customerName(name), timeSlot(slot), numofpeople(size) {}
    };
    class Restaurant {
    private:
       map<int, bool> timeSlots;
        vector<Reservation> reservations;

    public:
Restaurant() {

            for (int i = 14; i <= 23; ++i) {
                timeSlots[i] = true;
            }
        }
        void TimeSlots() {
            cout << "These are the available time slots\n";
            for (const auto& slot : timeSlots) {
                if (slot.second) {
                    cout << slot.first << ":00 pm\n";
                }
            }
        }



    void makeReservation(const string& name, int time, int size) {
        if (timeSlots.find(time) != timeSlots.end() && timeSlots[time]) {
            reservations.emplace_back(name, time, size);
            timeSlots[time] = false;
            cout << "This reservation has been made for: " << name << " at " << time << ":00 pm for " << size << " people.\n";
        }
        else {
            cout << "Our apologies but that time slot is not available. Please choose a different time.\n";
        }
    }
};

    int main() {
    Restaurant myRestaurant;
    int choice = 0;

    while (choice != 3) {
        cout << "\n ^^Restaurant Reservation System^^ \n";
        cout << "1. View Time Slots\n";
        cout << "2. Make a Reservation\n";
        cout << "3. Exit\n";
        cout << "choose an option: ";
        cin >> choice;

        if (choice == 1) {
            myRestaurant.TimeSlots();
        }
        else if (choice == 2) {
            string name;
            int time, size;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter a suitable time slot (16 to 23): ";
            cin >> time;
            cout << "Enter the number of people with you: ";
            cin >> size;
            myRestaurant.makeReservation(name, time, size);
        }
        else if (choice == 3) {
            cout << "thank you for using our system, you may exit\n";
        }
        else {
            cout << "This choice is not available, please try again\n";
        }
    }

    return 0;
}