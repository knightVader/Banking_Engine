#include<iostream>
#include<windows.h>
#include "customerFunc.h"
#include "managerFunc.h"

using namespace std;

int main(){

    while(1){
        cout<<"Welcome to SDLC Bank :)"<<endl;
        cout<<"1. Manager\n2. Customer\nEnter: ";
        int x;
        cin>>x;
        if(x==1){
           fillDatainVec();
           datafromFile();
           MvalidateID();
        }
        else if(x==2){
            while(2){
                cout<<"\n1. Bank\n2. ATM\n3. Exit\nEnter: ";
                int n;
                cin>>n;

                if(n == 1){
                    fillDatainVector();
                    while(1){
                        cout<<"\n1. Create New Account\n2. Deposit Money\n3. Exit\nEnter: ";
                        int a;
                        cin>>a;
                        if(a==1){
                            accountCreation();
                        }
                        else if(a==2){
                            depositMoney();
                        }
                        else if(a==3){
                            break;
                        }
                        else{
                            cout<<"Wrong Choice, Try Again";
                        }
                    }
                }
                else if(n == 2){
                    fillDatainVector();
                    validateID();
                    break;
                }
                else if(n == 3){
                    cout<<"\n ----------Thank You----------";
                    Sleep(3000);
                    clearConsole();
                    break;
                }
                else{
                    cout<<"Wrong Choice, Try Again.";
                }
            }
        }
        else{
            cout<<"Wrong Choice, Try agaain.";
        }
    }

    return 0;
}