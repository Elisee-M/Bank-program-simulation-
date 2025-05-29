/*
  Author: Elisee MUGIRANEZA
  https://github.com/Elisee-M
  mugiranezaelisee0@gmail.com
*/
#include <iostream>
using namespace std;

    string name, username, name1, ussd;
    int PIN, userpin, pin1, choice, depositamount, balance, withdrawamount;
 
void newuser(){
    
    cout<<"Enter the name: ";
    cin >> name;
    cout<<"Enter PIN for new user: ";
    cin >> PIN;
    username = name;
    userpin = PIN;
    cout<<"User sucesfully added!!\n";
}

void checkbalane(){
   cout<<"Dear user, your balance is: "<<balance<<endl;
}

void deposit(){
    cout<<"Enter deposit amount: ";
    cin >> depositamount;

    if(depositamount>0){
        cout<<"Deposit succesfully\n";
        balance +=depositamount;
        cout<<"New balance: "<<balance<<endl;
    } else{
        cout<<"Less balance";
    }
}

void withdraw(){
   cout<<"Enter money to withdraw: ";
   cin>>withdrawamount;
   if(withdrawamount>balance){
    cout<<"You do not have enough fund to complete this action\n";
   }else{
    balance -= withdrawamount;
    cout<<"Withdraw sucessfully!!!!\n";
    cout<<"New balance: "<<balance<<endl;
   }
}

void login(){
    cout<<"Enter username: ";
    cin>>name1;

    if(name1!=username){
        cout<<"You are not ours\n";
    }else{
        cout<<"Enter PIN: ";
        cin>>pin1;
        if(pin1!=userpin){
            cout<<"Incorrect PIN\n";
        } else{
            cout <<"Welcome!!\n";
            cout<<"1. Check balance\n 2. Deposit\n 3. Withdraw\n Choice: ";

            int userchoice;
            cin>>userchoice;
            if(userchoice==1){
                checkbalane();
            }
            else if(userchoice==2){
                deposit();
            }
            else if(userchoice==3){
                withdraw();
            }
            else{
                cout<<"Incorrect choice!!\n";
            }
        }
    }
}

int main(){
  cout<<"Enter USSD: ";
  cin>>ussd;
  if(ussd=="*300#"){
    do{
     cout<<"1. Add user\n2. Login\nChoice: ";
    
    cin>>choice;
    switch(choice){
        case 1:
            newuser();
            break;
        case 2:
            login();
            break;
         default:
            cout<<"Incorrect choice";
    }
} while (true);
} else{
    cout<<"Incorrect USSD!";
}

  return 0;
}
