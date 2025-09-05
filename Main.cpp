#include<iostream>
#include<string>
#include <cstdlib>
#include<vector> 
#include<fstream>
#include<windows.h> // include to make the code sleep

using namespace std;

string inID; //! will store the id entered by the user

int Wcount = 3; //! to count number of times wrong pin entered

void atmOptions(); //! prototype

//! node to store each set of data
class node{
    public:
    string id;
    int pin;
    float balance;

    node(string id, int pin, float balance){
        this->id=id;
        this->pin=pin;
        this->balance=balance;
    }
};

vector <node>Users; //! vector of nodes

//! function to clear the console works for different os
void clearConsole(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//! function for filling the data from the file into the node and storing in the vector
void fillDatainVector(){
    string id;
    int pin;
    float balance;

    ifstream file;
    file.open("customerData.txt");

    while(file >> id >> pin >> balance){
        Users.push_back(node(id, pin, balance));
    }

    file.close();
}

//! function to write updated data back to the file
void writeToFile(){
    ofstream file;
    file.open("customerData.txt");

    int len = Users.size();
    int i=0;
    while(i<len){
        file << Users[i].id <<" "<< Users[i].pin <<" "<< Users[i].balance << endl;
        i++;
    }

    file.close();
}

//! function to check the balance
void checkBalance(){
    string id;
    int pin;
    float balance;

    ifstream file;
    file.open("customerData.txt");

    while(file >> id >> pin >> balance){
        if(id == inID){
            cout<<"Balance: "<<balance<<endl;
            file.close();
            return;
        }
    }

    file.close();
}

//! function to withdraw money
void withdrawMoney(){
    float amount;
    cout<<"Enter the Amount: ";
    cin>>amount;

    int len = Users.size();
    for(int i=0;i<len;i++){
        if(Users[i].id == inID){
            if(amount > Users[i].balance){
                cout<<"Sorry! Not Enough Balance."<<endl;
                return; //* if some problem arises then add atmOptions func here
            }
            else{
                float temp = Users[i].balance - amount;
                Users[i].balance = temp;
                cout<<"Amount Successfully debited from your Account."<<endl;

                writeToFile();

                return;
            }
        }
    }
}

//! function to change the atm pin
void changePIN(){
    cout<<"Enter the new PIN: ";
    int p;
    cin>>p;

    for(int i=0;i<Users.size();i++){
        if(Users[i].id == inID){
            Users[i].pin = p;
            writeToFile();
            cout<<"Your PIN has been Updated"<<endl;
            return;
        }
    }
}

//! function to present atm operations
void  atmOptions(){
    int op;
    while(1){
        cout<<endl<<"1. Withdraw\n2. Check Balance\n3. Change PIN\n4. EXIT"<<endl;
        cout<<"Enter your Choice"<<endl;
        cin>>op;
        switch(op){
            case 1: {
                withdrawMoney();
            }
            break;
            case 2: {
                checkBalance();
            }
            break;
            case 3: {
                changePIN();
            }
            break;
            case 4: {
                cout<<endl<<"----------Thank You----------"<<endl;
                Sleep(5000);
                inID="0";
                clearConsole();
                return;
            }
            break;
            default :{
                cout<<"Wrong choice Entered, Enter Again"<<endl;
            }
        }
    }
}

//! function to validate the pin directly from the file
void validatePIN(){

    int upin;
    cout<<"Enter Your ATM PIN: ";
    cin>>upin;

    string id;
    int pin;
    float balance;

    bool flag=false;

    ifstream file;
    file.open("customerData.txt");
    while(file >> id >> pin >> balance){
        if(inID == id){
            if(pin == upin){
                flag=true;
                break;
            }
        }
    }

    if(flag){
        file.close();
        atmOptions();
    }
    else{
        cout<<"WRONG PIN ENTERED"<<endl;
        Wcount-=1;
        if(Wcount==0){
            clearConsole();
            return;
        }
        cout<<"You have "<<Wcount<<" chances left."<<endl;
        validatePIN();
        return;
    }
}

//! function to validate the entered id directly from the file
void validateID(){

    cout<<"Enter the ATM ID: ";
    cin>>inID;

    string id;
    int pin;
    float balance;

    bool flag=false;

    ifstream file;
    file.open("customerData.txt");

    while(file >> id >> pin >> balance){
        if(id == inID) {
            flag=true;
            break;
        }
    }

    if(flag){
        file.close();
        validatePIN();
    }
    else{
        cout<<"ID is not present in the database."<<endl<<"TRY AGAIN."<<endl;
        return;
    }

    return;
}



int main(){

    fillDatainVector();

    while(1){
        validateID();
    }

    return 0;
}