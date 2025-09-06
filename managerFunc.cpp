#include<iostream>
#include "customerFunc.h"
#include<fstream>
#include<string>
#include<vector>
#include<windows.h>

using namespace std;

string inputID;

class node{
    public:
    string id;
    int password;

    node(string id, int password){
        this->id=id;
        this->password=password;
    }
};

vector <node>Managers;

//! node to store data of customers
class nodeC{
    public:
    string id;
    int pin;
    float balance;

    nodeC(string id, int pin, float balance){
        this->id=id;
        this->pin=pin;
        this->balance=balance;
    }
};

vector <nodeC>Customers; //! vector of nodes for customers

//! function for filling the data of customers from the file into the node and storing in the vector
void fillDatainVec(){
    Customers.clear();
    string id;
    int pin;
    float balance;

    ifstream file;
    file.open("customerData.txt");

    while(file >> id >> pin >> balance){
        Customers.push_back(nodeC(id, pin, balance));
    }

    file.close();
}

//! function to write updated data back to the file of customers
void writeFile(){
    ofstream file;
    file.open("customerData.txt");

    int len = Customers.size();
    int i=0;
    while(i<len){
        file << Customers[i].id <<" "<< Customers[i].pin <<" "<< Customers[i].balance << endl;
        i++;
    }

    file.close();
}

//! function fetch data from file
void datafromFile(){
    Managers.clear();
    string id;
    int pass;
    ifstream file;
    file.open("managerData.txt");
    while(file >> id >> pass){
        Managers.push_back(node(id, pass));
    }
    file.close();
}

//! function to write data to file
void datainFile(){
    ofstream file;
    file.open("managerData.txt");
    for(int i=0;i<Managers.size();i++){
        file << Managers[i].id <<" "<< Managers[i].password <<endl;
    }
    file.close();
}

//! fucntion for total money calculation
void totalMoney(){
    float money=0;
    for(int i=0;i<Customers.size();i++){
        money=money+Customers[i].balance;
    }
    cout<<"Total Money in Bank is: "<<money;
}

//! fucntion for total accounts calculation
void totalAccounts(){
    cout<<"Total Accounts in Bank are: "<<Customers.size();
}

//! function for password change
void passwordChange(){
    cout<<"Enter the new PassWord: ";
    int temp;
    cin>>temp;
    for(int i=0;i<Managers.size();i++){
        if(Managers[i].id == inputID){
            Managers[i].password = temp;
            datainFile();
            cout<<"Your PassWord has been successfully changed.";
            return;
        }
    }
}

//! function to delete an account
void deleteAccount(){
    string temp;
    bool flag = false;
    cout<<"Enter the ID of the Account: ";
    cin>>temp;

    ofstream file;
    file.open("customerData.txt");
    for(int i=0;i<Customers.size();i++){
        if(Customers[i].id == temp){
            flag = true;
            continue;
        }
        else{
            file << Customers[i].id <<" "<< Customers[i].pin <<" "<< Customers[i].balance << endl;
        }
    }
    
    if(flag){
        fillDatainVec();
        cout<<"The Account Has Been Deleted From The Bank.";
    }
    else{
        cout<<"You Entered the wrong ID, No such account exists in the Bank.\nTry Again\n";
        deleteAccount();
    }
    file.close();
    return;
}

//! manager options function
void managerOptions(){
    while(1){
        cout<<"\n\n1. Total Money In Bank\n2. Total Accounts In Bank\n3. Delete an Account\n4. Change Your Password\n5. Exit\nEnter: ";
        int op;
        cin>>op;
        if(op==1){
            totalMoney();
        }
        else if(op==2){
            totalAccounts();
        }
        else if(op==3){
            deleteAccount();
        }
        else if(op==4){
            passwordChange();
        }
        else if(op==5){
            cout<<endl<<"----------Thank You----------"<<endl;
            Sleep(3000);
            clearConsole();
            break;
        }
        else{
            cout<<"Wrong Choice, Try Again.";
        }
    }
}

//! function to validate pin
int count=3;
void MvalidatePIN(){
    if(count==0){
        count=3;
        clearConsole();
        return;
    }

    int pass;
    bool flag = false;
    cout<<"Enter your PassWord: ";
    cin>>pass;
    for(int i=0;i<Managers.size();i++){
        if(Managers[i].id == inputID){
            if(Managers[i].password == pass){
                flag = true;
                break;
            }
        }
    }

    if(flag){
        cout<<"Welcome Manager Sir :)";
        managerOptions();
    }
    else{
        count--;
        cout<<"Wrong PassWord Entered, You have "<<count<<" chances left.\n";
        MvalidatePIN();
    }
}

//! function to validate id
void MvalidateID(){
    cout<<"Please Enter Your ID: ";
    cin>>inputID;
    bool flag = false;
    for(int i=0;i<Managers.size();i++){
        if(Managers[i].id == inputID){
            flag = true;
            break;
        }
    }

    if(flag){
        MvalidatePIN(); 
    }
    else{
        cout<<"Id do not exists, Try Again."<<endl;
        return;
    }
}