/*
Project of toystore management system which provides below functionalities.

==> Customer portal
1) View items
2) Place Order
3) View Cart (View all ordered items at one place)
4) Add product to wishlist (View all favourite items at one place)
5) Logout

==> Seller portal
1) Add items
2) View items
3) Logout

==> Admin Portal
1) Show customer details
2) Show seller details
3) Show product details

==> text file has following details
    customer's names, wishlist and cart
    seller's items and names
    
*/

#include "global.h"
#include "ques3.h"

int main() {
 
  
  starting();
  
  
  while (1) {
        cout<<"\t\t============================================"<<endl;
 	cout<<"\t\t|          WELCOME TO TOYCITY             |"<<endl;
	cout<<"\t\t============================================"<<endl;

	cout<<"\t\t     Enter 1 CUSTOMER"<<endl;
	cout<<"\t\t     Enter 2 SELLER"<<endl;
	cout<<"\t\t     Enter 3 ADMINSTRATOR"<<endl;
	cout<<"\t\t     Enter 4 EXIT PROGRAM"<<endl;

    int inp1;
    cin >> inp1;

    if (inp1 == 1) {
      
       cout<<"\t\t============================================"<<endl;
 	cout<<"\t\t|        WELCOME TO CUSTOMER PORTAL      |"<<endl;
	cout<<"\t\t============================================"<<endl;

	cout<<"\t\t     Enter 1 REGISTER"<<endl;
	cout<<"\t\t     Enter 2 LOGIN"<<endl;

      int inp2;
      cin >> inp2;

      if (inp2 == 1) {
        buyerRegister();
      } 
      else if (inp2 == 2) {
        buyerLogin();
      }
       else {
        cout << "invalid input" << endl;
      }

    } 
    else if (inp1 == 2) {

        cout<<"\t\t============================================"<<endl;
 	cout<<"\t\t|     WELCOME TO SELLER PORTAL             |"<<endl;
	cout<<"\t\t============================================"<<endl;

	cout<<"\t\t     Enter 1 REGISTER"<<endl;
	cout<<"\t\t     Enter 2 LOGIN"<<endl;

      int inp2;
      cin >> inp2;

      if (inp2 == 1) {
        sellerRegister();
      }
       else if (inp2 == 2) {
        sellerLogin();
      } 
      else {
        cout << "invalid input" << endl;
      }

    }
    else if(inp1==3){ 
    
      string key; 
      cout<<"Enter Admin Key"<<endl; 
      cin>>key;
      if(key==adminkey){
        cout<<"\t\t============================================"<<endl;
 	cout<<"\t\t|           WELCOME TO ADMIN PORTAL         |"<<endl;
	cout<<"\t\t============================================"<<endl;

	cout<<"\t\t     Enter 1 SHOW CUSTOMERS"<<endl;
	cout<<"\t\t     Enter 2 SHOW SELLERS"<<endl;
	cout<<"\t\t     Enter 3 SHOW PRODUCTS"<<endl;
        
        int inp2;
        cin >> inp2;
        if(inp2==1){
          showcustomers();
          cout<<endl;
        }
        else if(inp2==2){
          showsellers();
          cout<<endl;
        }
        else if(inp2==3){
          cout<<"Available products are : "<<endl;
          showallproducts();
          cout<<endl;
        }
        else{
         cout << "invalid input" << endl;
        }
      }
      else{
        cout<<"Incorrect adminkey"<<endl;
      }

    }
    else if (inp1 == 4) {
      ending();
      cout << "thankyou exiting the program" << endl;
      break;
    } 
    else {
      cout << "invalid input" << endl;
    }

  }
  
  return 0;
}
