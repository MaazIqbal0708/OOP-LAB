#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
    string ticketID;
    string passengerName;
    float price;
    string date;
    string destination;
    bool reservation;
public:
    Ticket(string id, string name, float p, string d, string dest) 
        : ticketID(id), passengerName(name), price(p), date(d), destination(dest), reservation(false) {}
    
    virtual void reserve() {
        reservation = true;
        cout << "Ticket reserved for " << passengerName << endl;
    }
    
    virtual void cancel() {
        reservation = false;
        cout << "Reservation cancelled for " << passengerName << endl;
    }
    
    virtual void displayTicketInfo() {
        cout << "Ticket ID: " << ticketID << "\nPassenger: " << passengerName << "\nDate: " << date << "\nDestination: " 
            << destination << "\nPrice: Rs." << price << "\nStatus: " << (reservation ? "Reserved" : "Available") << endl;
    }
};

class FlightTicket : public Ticket {
    string airlineName;
    string flightNumber;
    string seatClass;
public:
    FlightTicket(string id, string name, float p, string d, string dest, string airline, string flight, string seat) 
        : Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flight), seatClass(seat) {}
    
    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << "\nFlight: " << flightNumber << "\nClass: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
    string trainNumber;
    string coachType;
    string departureTime;
public:
    TrainTicket(string id, string name, float p, string d, string dest, string train, string coach, string time) 
        : Ticket(id, name, p, d, dest), trainNumber(train), coachType(coach), departureTime(time) {}
    
    void reserve() override {
        Ticket::reserve();
        cout << "Seat is auto assigned in " << coachType << " coach on train " << trainNumber << endl;
    }
};

class BusTicket : public Ticket {
    string busCompany;
    string seatNumber;
public:
    BusTicket(string id, string name, float p, string d, string dest, string company, string seat) 
        : Ticket(id, name, p, d, dest), busCompany(company), seatNumber(seat) {}
    
    void cancel() override {
        Ticket::cancel();
        cout << "75% refund processed for last minute canellation" << endl;
    }
};

class ConcertTicket : public Ticket {
    string artistName;
    string venue;
    string seatType;
public:
    ConcertTicket(string id, string name, float p, string d, string dest, string artist, string v, string seat) 
        : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(seat) {}
    
    void displayTicketInfo() override {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << "\nVenue: " << venue << "\nSeat Type: " << seatType << endl;
    }
};

int main() {

    FlightTicket ft("A001", "Maaz", 30000, "11-08-2025", "Karchi-Skardu", "PIA", "PK123", "Business");
    TrainTicket tt("B001", "Burair", 3000, "08-08-2025", "Karachi-Islamabad", "Allama Iqbal Express", "AC", "12:00");
    BusTicket bt("C001", "Zahran", 2500, "10-09-2024", "Karachi-Lahore", "Sleeper Bus", "12A");
    ConcertTicket ct("D001", "Ali", 6000, "12-12-2025", "Karachi", "Ali Zafar", "Ziauddin", "VIP");

    ft.reserve();
    ft.displayTicketInfo();
    cout << endl;

    tt.reserve();
    tt.displayTicketInfo();
    cout << endl;

    bt.reserve();
    bt.cancel();
    bt.displayTicketInfo();
    cout << endl;

    ct.reserve();
    ct.displayTicketInfo();
    
    return 0;
}
