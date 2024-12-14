#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Creation of Classes
class User {
private:
    //Encapsulated User Attributes
    int userID;
    string name, location;
public:
    //Set Methods to allow modification of user attributes.
    void setUserID(int ID) {
        userID=ID;
    }
    void setName(string nomen) {
        name=nomen;
    }
    void setLocation(string loc) {
        location=loc;
    }
    //Get Methods to retrieve user attributes
    int getUserID() {
        return userID;
    }
    string getName() {
        return name;
    }
    string getLocation() {
        return location;
    }
};
class Rider: public User {
private:
    int numberPassengers;
    string destination;
public:
    void setNumberPassengers(int nPass) {
        numberPassengers = nPass;
    }
    void setDestination(string dLoc) {
        destination = dLoc;
    }

    int getNumberPassengers() {
        return numberPassengers;
    }
    string getDestination() {
        return destination;
    }
};
class Driver: public User {
private:
    int numberSeats;
    string vehicleType;
    bool isAssigned; // tracking for driver assigned to trip
public:
    void setNumberSeats(int nSeat) {
        numberSeats = nSeat;
    }
    void setVehicleType(string vehicle) {
        vehicleType = vehicle;
    }
    void setIsAssigned(bool assigned) {
        isAssigned = assigned;
    }
    int getNumberSeats() {
        return numberSeats;
    }
    string getVehicleType() {
        return vehicleType;
    }
    bool getIsAssigned() {
        return isAssigned;
    }
    string getStringIsAssigned() {//Allows for system to produce a output that can be used in the string section
        string output;
        if(isAssigned==true) {
            output = "Yes";
        }
        else {
            output="No";
        }
        return output;
    }
};
class Trip {//Used Trip instead of ride to reduce chance of confusing "Rider" and "Ride"
private:
    int tripID,riderID,driverID;
    string dest;
public:
    // Constructor
    Trip(int tID, int rID, int dID, string destT) : tripID(tID), riderID(rID), driverID(dID), dest(destT){}//Constructor to allow for the creation of trip in one swoop rather than individual setter functions
    // Getter functions
    int getTripID() const { return tripID; }
    int getRiderID() const { return riderID; }
    int getDriverID() const { return driverID; }
    string getTripDestination() { return dest; }
};

//Global Variables//
int menuItem;
bool exitProgram = false;
int nextDriverID = 200; // User ID tracker. We wish for driver ids to start in the 200s
int nextRiderID = 100; // User ID tracker. We wish for rider ids to start in the 100s
int nextTripID = 0; // Trip ID tracker. We wish for trip ids to start in the 00s
//Function Declaration
void topMenu();//Menu to allow for selection of other features
string stringInputHandler();//Handles sanitization and checking of all user-input strings
int intInputHandler();//Handles sanitization and checking of all user-input integers
void registerDriver();///Function to register one or more drivers
vector<Driver> driverList; // storage for multiple driver objects
void registerRider();//Function to register one or more riders.
vector<Rider> riderList; // storage for multiple rider objects
void displayDriver();//Displays all registered drivers
void displayRider();//Displays all registered riders
void requestRide();// Allows for administrator to match drivers to riders and create trips
vector<Trip> tripList; // storage for multiple trips
void displayTrips();//Displays all in progress trips.


int main() {
while(exitProgram==false) {//Runs until program is exited
    topMenu();
}

}
void topMenu() {
    cout << "--------------------------\n";
    cout <<"Welcome to the Main Menu. Please Select an Option "<<endl<<"1. Register New Rider"<<endl<<"2. Register New Driver"<<endl<<"3. Display Registered Riders"<<endl<<"4. Display Registered Drivers" <<endl<<"5. Schedule Ride"<<endl<<"6. Display In-Progress Trips"<<endl<<"7. Exit Program"<<endl;

    menuItem=intInputHandler();
    switch (menuItem) {
        case(1):
            registerRider();//Register rider
        break;
        case(2):
            registerDriver();//Register driver
        break;
        case(3):
            displayRider();//Display Rider
        break;
        case(4):
            displayDriver();//Display driver
        break;
        case(5):
            requestRide();//Request ride
        break;
        case(6):
            displayTrips();
        break;
        case(7):
            cout <<"Have a Nice Rest of the Day!"<<endl;
            exitProgram=true;//Sets flag to exit program
        break;
        default://If the user selects an option not on the menu we will inform them and rerun the menu.
            cout << "Sorry! That is not a valid menu option. Please enter number from 1-7"<< endl;
    }
    cout << "--------------------------\n";
}
//Overloaded Input Handlers
string stringInputHandler() {
    bool valid_input;//Variable to store if input is valid
    string output;
    do  {
        valid_input=true;
        if (cin.peek() == '\n')
            //Handles Empty line. Keeps the default value.
                //Reference found here:https://stackoverflow.com/questions/10314682/user-inputcin-default-value
        {
            valid_input=false;
            cout << "It appears you have entered an empty input!" <<endl<<
                    "Please try again"
                    << endl;
        } else if (!(cin >> output)) //Checks type compatibility
        {
            //Causes the loop to iterate again
            valid_input=false;
            cout << "It appears you have entered something other than a string. Please try again!" <<endl;
        }
        //Clears input buffer
        cin.clear();//Clears input buffer: https://stackoverflow.com/questions/22122337/while-loop-skipping-cin
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while (valid_input == false);//Repeats until valid input is passed.
    return output;
}
int intInputHandler() {
    bool valid_input;
    int output;
    do  {
        valid_input=true;
        if (cin.peek() == '\n')
            //Handles Empty line. Keeps the default value.
                //Reference found here:https://stackoverflow.com/questions/10314682/user-inputcin-default-value
        {
            valid_input=false;
            cout << "It appears you have entered an empty input!" <<endl<<
                    "Please try again"
                    << endl;
        } else if (!(cin >> output)) //Checks type compatibility
        {
            //Causes the loop to iterate again
            valid_input=false;
            cout << "It appears you have entered something other than an integer. Please try again!" <<endl;
        }
        //Clears input buffer
        cin.clear();//Clears input buffer: https://stackoverflow.com/questions/22122337/while-loop-skipping-cin
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }while (valid_input == false);
    return output;
}

// Function to register drivers
void registerDriver() {
    int num;
    cout <<"How many drivers would you like to register?"<< endl;
    num = intInputHandler();

    for(size_t i = 0; i < num ; i++) {
        Driver newDriver; // create new driver object
        int numberSeats;
        string name, location, vehicleType;

        cout <<"Enter Driver Name: ";
        name = stringInputHandler();
        newDriver.setName(name);

        newDriver.setUserID(++nextDriverID);

        cout <<"Enter Driver Location: ";
        location = stringInputHandler();
        newDriver.setLocation(location);

        cout <<"Enter Number of Seats Available: ";
        numberSeats = intInputHandler();
        newDriver.setNumberSeats(numberSeats);

        cout <<"Enter Vehicle: ";
        vehicleType = stringInputHandler();
        newDriver.setVehicleType(vehicleType);

        newDriver.setIsAssigned(false);

        driverList.push_back(newDriver); // adds new driver to the driver list

        cout <<"Driver Successfully Registered\nDriver ID: "<<newDriver.getUserID()<<"\n";
    }
}

/// function to register riders
void registerRider() {
    int num;
    cout <<"How many riders would you like to register?"<< endl;
    num = intInputHandler();

    for(size_t i = 0; i < num ; i++) {
        Rider newRider;
        int numberPassengers;
        string name, location, destination;

        newRider.setUserID(++nextRiderID);

        cout <<"Enter Rider Name: ";
        name = stringInputHandler();
        newRider.setName(name);

        cout <<"Enter Rider Location: ";
        location = stringInputHandler();
        newRider.setLocation(location);

        cout <<"Enter Rider Destination: ";
        destination = stringInputHandler();
        newRider.setDestination(destination);

        cout <<"Enter Number of Passengers: ";
        numberPassengers = intInputHandler();
        newRider.setNumberPassengers(numberPassengers);

        riderList.push_back(newRider);

        cout <<"Rider Successfully Registered\nRider ID: "<<newRider.getUserID()<<"\n";
    }
}

// function that displays rider list
void displayRider() {
    if (riderList.empty()) {
        cout << "No riders registered yet.\n";
        return;
    }

    cout << "Registered Riders:\n";
    for (size_t i = 0; i < riderList.size(); i++) {
        cout << "Rider ID: " << riderList[i].getUserID() << "\n";
        cout << "Name: " << riderList[i].getName() << "\n";
        cout << "Location: " << riderList[i].getLocation() << "\n";
        cout << "Destination: " << riderList[i].getDestination() << "\n";
        cout << "Number of Passengers: " << riderList[i].getNumberPassengers() << "\n";
        cout << "--------------------------\n";
    }
}

// function that displays driver list
void displayDriver() {
    if (driverList.empty()) {
        cout << "No drivers registered yet.\n";
        return;
    }

    cout << "Registered Drivers:\n";
    for (size_t i = 0; i < driverList.size(); i++) {
        cout << "Driver ID: " << driverList[i].getUserID() << "\n";
        cout << "Name: " << driverList[i].getName() << "\n";
        cout << "Location: " << driverList[i].getLocation() << "\n";
        cout << "Number of Seats: " << driverList[i].getNumberSeats() << "\n";
        cout << "Vehicle: " << driverList[i].getVehicleType() << "\n";
        cout << "Assigned: " << driverList[i].getStringIsAssigned() << "\n";
        cout << "--------------------------\n";
    }
}

// function to request and schedule a ride
void requestRide() {
    int riderID;
    cout <<"Enter Rider ID: ";
    riderID = intInputHandler();


    string rideDestintation;
    // Check if rider exists
    bool riderFound = false;
    int riderInd;
    for (size_t i = 0; i < riderList.size(); i++) {
        if (riderList[i].getUserID() == riderID) {
            riderFound = true;
            rideDestintation = riderList[i].getDestination();
            riderInd = i;
            break;
        }
    }

    if (!riderFound) {
        cout <<"Rider ID not found. Please register first.\n";
        return;
    }

    cout << "Available Drivers:\n";
    vector<int> availableDrivers; // Store IDs of available drivers
    for (size_t i = 0; i < driverList.size(); i++) {
        if (!driverList[i].getIsAssigned() && driverList[i].getNumberSeats() >= riderList[riderInd].getNumberPassengers()) {  // Check if the driver is available
            cout << driverList[i].getUserID() << ": " << driverList[i].getName() << ", Vehicle Type: " << driverList[i].getVehicleType() << ", Number of Seats: " << driverList[i].getNumberSeats() << ", Location: " << driverList[i].getLocation() << "\n";
            availableDrivers.push_back(driverList[i].getUserID()); // Store available driver ID
        }
    }

    if (availableDrivers.empty()) {
        cout << "No available drivers at the moment.\n";
        return;
    }

    int driverID;
    cout << "Enter the Driver ID you'd like to choose: ";
    driverID = intInputHandler();

    bool driverAvailable = false; // checks if the diver selected is available
    for (int id : availableDrivers) {
        if (id == driverID) {
            driverAvailable = true;
            break;
        }
    }

    if (!driverAvailable) {
        cout << "The selected driver is not available. Please choose another driver.\n";
        return;
    }

    for (size_t i = 0; i < driverList.size(); i++) {
        if (driverList[i].getUserID() == driverID) {
            driverList[i].setIsAssigned(true); // Mark the driver as assigned
            break;
        }
    }

    Trip newTrip(++nextTripID, riderID, driverID, rideDestintation);
    tripList.push_back(newTrip); // Store the new trip in the tripList

    cout << "Trip successfully created!\n" << "Trip ID: " << newTrip.getTripID() << "\nRider ID: " << riderID << "\nDriver ID: " << driverID << "\nDestination: " << rideDestintation << "\n";
}

// function that displays trip list
void displayTrips() {
    if (tripList.empty()) {
        cout << "No trips are running currentlu.\n";
        return;
    }

    cout << "Curent Trips:\n";
    for (size_t i = 0; i < tripList.size(); i++) {
        cout << "Trip ID: " << tripList[i].getTripID() << "\n";
        cout << "Rider ID: " << tripList[i].getRiderID() << "\n";
        cout << "Driver ID: " << tripList[i].getDriverID() << "\n";
        cout << "Destination: " << tripList[i].getTripDestination() << "\n";
        cout << "--------------------------\n";
    }
}
