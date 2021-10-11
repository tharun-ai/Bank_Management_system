
/* 
 
 Author:Tharun Voora
 */

#include <bits/stdc++.h>
#include<fstream>
using namespace std;
//Created Userdefined type of Bank type for each user 
string check();
class Bank{
  //Datamembers are stored in private for the principle of Encapsulation
  float amount=20003;
  string acc_hol_name;
  string type_acc;
  int  acc_num;
  public:
  Bank(){}
  //Declaring Constructors for Intialising the Objects
  //Constructor for existed  accounts
  Bank(string acc_hol_name,string type_acc,float amount,int acc_num){
    this->amount=amount;
    this->type_acc=type_acc;
    this->acc_hol_name=acc_hol_name;
    this->acc_num=acc_num;
  }
  //Constructor for NewlY created accounts;
  Bank(string acc_hol_name,string type_acc,int acc_num){
    this->type_acc=type_acc;
    this->acc_hol_name=acc_hol_name;
    this->acc_num=acc_num;
    cout<<"New Account was created"<<endl;
  }
  
  //Functions Defined for gettingusername
  bool  getname(string username){
    return this->acc_hol_name==username? true:false;
  }
  //Functions Defined for gettingamount of the User
  float   getamount(){
    return this->amount;
  }
  int getacn_1(){
    return acc_num;
  }
  ////Functions Defined for debit amount of the User
  void  debit(float user_amount){
  float k=(this->amount)-user_amount;
  amount=k;
  }
  ////Functions Defined for accountype of the User
  void typeaccount(){
    cout<<this->type_acc;
  }
  ////Functions Defined for deposit of the User
  void deposit(Bank k,float useramunt){
    float j=k.getamount()+useramunt;
    this->amount=j;
  }
  ////Functions Defined for details  of the User
   void checkdetails(){
    cout<<"Amount was "<<this->amount<<endl;
    cout<<"Your Account type:"<<type_acc<<endl;
    cout<<"Account holder name:"<<acc_hol_name<<endl;
    cout<<"Your Account Number"<<acc_num<<endl;
  }
  void setaccount(){
    cout<<"Enter Your Nmae"<<endl;
    string name;
    cin>>name;
    this->acc_hol_name=name;
    cout<<"Enter Your Account type";
    string ac=check();
    this->type_acc=ac;

  }
  
};
//functions for asking new user to specify the Account type
string  check(){
  cout<<"Enter  type of account"<<endl;
  string user_type;
    cout<<" Press S.Savings C.Curent"<<endl;
    char c;
    cin>>c;
    switch(c){
      case 'S':
      return "Savings";
      break;
      case 'C':
      return "Current";
      break;
      default:
      cout<<"Invalid option";
      return "NULL";
      break;
    }
    return user_type;
}

//Converting Id to string type to reduce the memory consumption
string itos(int id){
  string k="";
  while(id){
     int rem=id%10;
     int  l=rem+'0';
     k.push_back(l);
     id=id/10;
  }
  reverse(k.begin(),k.end());
  return k;
}
//function for deleting the user account 
void delete_account(vector<Bank>c,int id){
   ifstream file;
    Bank k;
    fstream file1;
   file1.open("temp.dat",ios::out);
    file.open( "abcdf.dat",ios::in  );
    for(int i=0;i<c.size();i++){
      file.read((char*)&c[i],c.size()*sizeof(Bank));
      if(id==c[i].getacn_1()){
       
      }
      else{
        file1.write((char*)&c[i],c.size()*sizeof(Bank));
      }
    }
     file.close();
	file1.close();
	remove("abcdf.dat");
	rename("temp.dat","abcdf.dat");
	cout<<"\n\nRecord Deleted ..";

}
void upload1(vector<Bank> B,Bank k,int i){
  fstream file;
  file.open("abcdf.dat",ios::out);
  //int i=B.size()-1;
    file.write((char*)&B[i],B.size()*sizeof(Bank));
  file.close();
  cout<<"Uploading Completed";

}
//Function for uploading the detials of the function into file
void upload(vector<Bank>B){
  fstream file;
  file.open("abcdf.dat",ios::out);
  for(int i=0;i<B.size();i++){
    file.write((char*)&B[i],B.size()*sizeof(Bank));
  }
  file.close();
  cout<<"Uploading Completed";
}
//function for if user enter acc_num enters the acc_num 
//check whether it is their or not
void display(vector<Bank>c,int id){
    fstream file;
    Bank k;
    file.open( "abcdf.dat",ios::in  );
    for(int i=0;i<c.size();i++){
      file.read((char*)&c[i],c.size()*sizeof(Bank));
      if(id==c[i].getacn_1()){
        c[i].checkdetails();
        break;
      }
    }
   file.close();
  }
//Defining the function for modifying the details of given account_num
void modify_account(vector<Bank>b,int i,int n)
{
	bool found=false;
  //Bank b[i];
	fstream File;
    File.open("abcdf.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
  
	while(!File.eof() && found==false)
	{
		File.read((char *)(&b[i]), sizeof(Bank)*b.size());
		if(b[i].getacn_1()==n)
		{
			b[i].checkdetails();
			cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
			b[i].setaccount();
      //upload(b);
			int pos=(-1)*static_cast<int>(sizeof(Bank)*b.size());
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write((char*) (&b[i]), sizeof(Bank)*b.size());
		    cout<<"\n\n\t\t\tRecord Updated";
		    found=true;
		  }
	}
      File.close();
  
//	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}
//Function for asking user to select the service which he wants
void Services(vector<Bank>&v,int i){
  cout<<"1.Debit account "<<setw(20)<<" 2.Deposit"<<endl;
  cout<<"3.Check Balance "<<setw(20)<<"4.check details"<<endl;
  cout<<" 5.Account Number of Last Entry"<<endl;
  int k;
  cin>>k;
  float l;
  switch(k){
    case 1:
      cout<<"Enter amount be debited";
      cin>>l;
      v[i].debit(l);
      break;
    case 2:
      cout<<"Enter amount to be deposited"<<endl;
      cin>>l;
      v[i].deposit(v[i] , l);
      break;
       case 3:
       cout<<v[i].getamount();
       break;
     case 4:
      cout<<"Your details are"<<endl;
      v[i].checkdetails();
      break;
    case 5:
     cout<<"Last Entry of Account Number is:"<<
     v[v.size()-1].getacn_1()<<endl;
     break;
     case 6:
     cout<<"Invalid Option"<<endl;
     break;
  }
}
int find_index(vector<Bank>b,int id){
  for(int i=0;i<b.size();i++){
    if(b[i].getacn_1()==id){
      return i;
    }
  }
  return -1;
}
int main() {
  //Starting id for new created Bank Account;
  static int id=12347;
//Details of Bank employees
    vector<Bank> c ={Bank("Harry","Savings",20000.0,12345),Bank("Ben","Current",2000.0,12346),Bank("Steve","Savings",40000.0,12347)};
   cout<<"Welcome to Bank";
   upload(c);
  // display(c,12345);
  // modify_account(c,1,12346);
  // delete_account(c,12345);
  // Services(c,0);
  // c[0].update();
  
   //c[0].delete_it(12346);
   //asking user to  select the type of account
   string username,user_type,user_accnum;
    cout<<" Press 1.Bank Employee 2.Nrw Account"<<endl;
    int choice;
    cin>>choice;
    bool found=false;
    if(choice==1){
        cout<<"Enter your Name "<<endl;
        cin>>username;
        int i=0;
        //After Enterng his name we are checking user's name in existed records
        for(i=0;i<c.size();i++){
          if(c[i].getname(username)){
            //user Found
            //Aksing user How many transaction he wants to do
            found=true;
             cout<<"Enter how many transactions";
              int t;
              cin>>t;
              i++;
              while(t--){
                //CALLING THE SERVICES function
              Services(c,i);
              }
          }
        }
        if(i==c.size()){
          cout<<"Your Are Not Employee"<<endl;

        }
    }
    //If User was New holder
    else{
      //ASKING user to enter his name for his newly created account
    cout<<"Enter your Name "<<endl;
    cin>>username;
     string k=check();
     if(k!="NULL"){
       id=id+1;
       string l=itos(id);
       //Creating the NEW USER account by using Constructor
       Bank b={username,k,id};
       found=true;
       //Storiing his Account details in our Current database or Vector
       c.push_back(b);
       cout<<"Enter how many transactions";
      int t;
      cin>>t;
      while(t--){
        //Offering Services function to New Account holder
      Services(c,c.size()-1);
      }
      upload(c);
    }
    //If USER select innvalid option
    else{
      cout<<"NOT VALID";
    }
    }
   // cout<<c.size()<<endl;
   //If you want to check the all the details of Account holders in Bank 
   //Uncomment the 205 to 207 lines
     if(found){
     cout<<"1.Modify Account 2.Delete Your Account 3.Print All details "<<endl;
     int o;
     cin>>o;
     cout<<"Enter Your Account Number"<<endl;
     int id1;
     cin>>id1;
     if(o==1){
       int k=find_index(c,id1);
     modify_account(c,k,id1);
     }
     else if(o==3){
       for(Bank b:c){
       b.checkdetails();
     } 
     }
     else{
      delete_account(c,id1);
     }
     }
     else{
       cout<<"Thank you"<<endl;
     }
    }
