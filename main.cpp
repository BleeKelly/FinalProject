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
    //Set Methods to allow modification of user attributes
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
public:
    void setNumberPassengers(int nPass) {
        numberPassengers = nPass;
    }
    int getNumberPassengers() {
        return numberPassengers;
    }
};
class Driver: public User {
private:
    int numberSeats;
    string vehicleType;
public:
    void setNumberSeats(int nSeat) {
        numberSeats = nSeat;
    }
    void setVehicleType(string vehicle) {
        vehicleType = vehicle;
    }
    int getNumberSeats() {
        return numberSeats;
    }
    string getVehicleType() {
        return vehicleType;
    }
};
class Trip {//Used Trip instead of ride to reduce chance of confusing "Rider" and "Ride"
private:
    int tripID,riderID,driverID;
public:

};
//Global Variables//
int menuItem;
bool exitProgram = false;
//Function Declaration
void topMenu();
string stringInputHandler();
int intInputHandler();

int main()
{

while(exitProgram==false) {
    topMenu();
}

}
void topMenu() {
    cout <<"Welcome to the Main Menu "<<endl;
    menuItem=intInputHandler();
    switch (menuItem) {
        case(1):
            func1();//PlaceholderNames
            break;
        case(2):
            func2();//PlaceholderNames
        break;
        case(3):
            func3();//PlaceholderNames
        break;
        case(4):
            func4();//PlaceholderNames
        break;
        case(5):
            func5();//PlaceholderNames
        break;
        case(6):
            cout <<"Have a Nice Rest of the Day!"<<endl;
            exitProgram=true;
        default:
            cout << "Sorry! That is not a valid menu option. Please enter number from 1-6"<< endl;
    }

}
//Overloaded Input Handlers
string stringInputHandler() {
    bool valid_input;
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
    }while (valid_input == false);
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