/*
 *Programmer: Layyana Junaid
 *Date: 31st January 2024
 *Description: event management system
 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Event {
    string name;
    string date;
    string venue;
    string organizer;
};

void addEvent(vector<Event>& events) {
    Event newEvent;
    cout << "Enter event name: ";
    getline(cin, newEvent.name);
    cout << "Enter event date (dd/mm/yyyy): ";
    getline(cin, newEvent.date);
    cout << "Enter event venue: ";
    getline(cin, newEvent.venue);
    cout << "Enter event organizer: ";
    getline(cin, newEvent.organizer);
    events.push_back(newEvent);
}

void displayEvents(const vector<Event>& events) {
    cout << "| Event Name | Date | Venue | Organizer |" << endl;
    for (const Event& event : events) {
        cout << " | " << event.name << " | " << event.date << " | " << event.venue << " | " << event.organizer << " | " << endl;
    }
}

void searchEvents(const vector<Event>& events, const string& searchDate) {
    bool found = false;
    for (const Event& event : events) {
        if (event.date == searchDate) {
            cout << "Event Name: " << event.name << endl;
            cout << "Event Date: " << event.date << endl;
            cout << "Event Venue: " << event.venue << endl;
            cout << "Event Organizer: " << event.organizer << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No events found for the specified date." << endl;
    }
}

int main() {
    int numEvents;
    cout << "Enter total number of events to manage: ";
    cin >> numEvents;
    vector<Event> events;
    events.reserve(numEvents);
    for (int i = 0; i < numEvents; i++) {
        addEvent(events);
    }
    int choice;
    while (true) {
        cout << "1. Display all events" << endl;
        cout << "2. Search for events" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                displayEvents(events);
                break;
            case 2: {
                string searchDate;
                cout << "Enter date to search (dd/mm/yyyy): ";
                getline(cin, searchDate);
                searchEvents(events, searchDate);
                break;
            }
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}