#include "global.h"
#include "storeinfo.h"



unordered_map < string, struct buyer > buyerDB;    // customer email mapping to complete customer details of that email
unordered_map < string, struct seller > sellerDB;  // seller email mapping to complete seller details of that email
vector < struct item > items;                      // all items in store of all sellers


void buyerRegister() {
  struct buyer user;

  cout << "enter email" << endl;
  cin >> user.email;

  cout << "enter password" << endl;
  cin >> user.password;

  cout << "name" << endl;
  cin >> user.name;

  if (buyerDB.find(user.email) == buyerDB.end()) {
  //  buyerDB[user.email] = user;
    buyerDB.insert({user.email,user});
    cout << "account created successfully" << endl;
    
  } else {
    cout << "account already exists" << endl;
  }
}

int index_product(string name){
  // find index of that product name 
  int itemId=-1;
        for(int i=0;i<items.size();i++){
         if(items[i].name==name){
           itemId=i;
         }
       }
        return itemId;
}


int selleritem_index(string sellerID,string productname){ //product name
     int n=sellerDB[sellerID].goods.size();
               for(int i=0;i<n;i++){
                 if(sellerDB[sellerID].goods[i].name==productname){
                    return i;
                 }
               }
               return -1;
}

void buyerLogin() {
  string email, password;

  cout << "enter email" << endl;
  cin >> email;

  cout << "enter password" << endl;
  cin >> password;

  if (buyerDB.find(email) != buyerDB.end() && buyerDB[email].password == password) {
    cout << "logged in successfully" << endl;
    

    while (1) {
      cout << "view items 1"<<endl;
      cout << "placeorder 2"<<endl;
      cout << "view cart 3"<<endl;
      cout << "view wishlist 4" << endl;
      cout << "logout 5"<<endl;

      int inp1;
      cin >> inp1;

      if (inp1 == 1) {
         cout<<endl;
         cout<<"-----------------------------------"<<endl;
        cout << "item-id name price quantity seller" << endl;
        for (int i = 0; i < items.size(); i++) {
          cout << i + 1 <<" "<< items[i].name << " " << items[i].price << " " <<items[i].qnty << " " << items[i].sellerid << endl;
        }
        
        cout<<"--------------------------------"<<endl;
      }
       else if (inp1 == 2) {
        cout << "itemname qty" << endl;
        string name;
        int  itemId,qty;
        cin >> name >> qty;
        
        itemId=index_product(name);
          // seller has required stock or not
          if(itemId==-1){
              cout << "item not available" << endl;
              break;
          }
          else{
          
          struct order border;
          border.item = items[itemId];
          border.quantity = qty;
          border.price = items[itemId].price * qty;
          cout<<"Want to buy/wishlist the item??"<<endl;
          string s;
          cin>>s;
          if(s=="buy"){
          
               string sellerID=items[itemId].sellerid; //sellerid of product seller
               // search for product in this seller available goods and check stock
               int ind=selleritem_index(sellerID,name);
               int idx=index_product(name);
               int stock=sellerDB[sellerID].goods[ind].qnty;
               if(stock>=qty){
                  items[itemId].qnty = items[itemId].qnty-qty;
                  sellerDB[sellerID].goods[ind].qnty = (sellerDB[sellerID].goods[ind].qnty)-qty;
                  buyerDB[email].orders.push_back(border);
                  
                   /*struct cust c;
                   c.name=buyerDB[email].name;
                   c.itemname=items[itemId].name;
                   c.qty=qty;
                   c.total=(items[itemId].price*qty);
                   cust[items[itemId].sellerid].push_back(c);*/
              }
               else{
                  cout<<"Insufficient Stock!!"<<" Available stock: "<<stock<<endl;
               }
               
              
               
          }
          else if(s=="wishlist"){
             border.quantity = 1;
             border.price = items[itemId].price;
             buyerDB[email].wishlist.push_back(border);
          }
          else{
           cout<<"invalid..pls enter buy/wishlist"<<endl;
          }
         
          
          
          // customer details who bought a particular seller items
          
        }
       }
        
       else if (inp1 == 3) { // cart
         cout<<endl;
         cout<<"--------------------------------"<<endl;
        cout << "name qty price seller" << endl;
        for (int i = 0; i < buyerDB[email].orders.size(); i++) {
          cout << buyerDB[email].orders[i].item.name << " " << buyerDB[email].orders[i].quantity << " ";
          cout << buyerDB[email].orders[i].price << " " << buyerDB[email].orders[i].item.sellerid<<endl;
        }
         
         cout<<"--------------------------------"<<endl;
      } 
      
      else if(inp1 == 4){ //wishlist
          cout<<endl;
          cout<<"--------------------------------"<<endl;
         cout << "name price seller" << endl;
         for (int i = 0; i < buyerDB[email].wishlist.size(); i++) {
          cout << buyerDB[email].wishlist[i].item.name << " ";
          cout << buyerDB[email].wishlist[i].price << " " << buyerDB[email].wishlist[i].item.sellerid<<endl;
        }
         
        cout<<"--------------------------------"<<endl;
      }
      
      else if (inp1 == 5) {
        cout << "Thankyou"<<" "<<buyerDB[email].name<<"!! "<<"Logging out of store"<<endl;
        break;
      } else {
        cout << "invalid input"<<endl;
      }

    }

    
  } 
  else {
    cout << "invalid credentials/account doesnot exist please create your account" << endl;
    
  }
}

void sellerRegister() {
  struct seller user;

  cout << "enter email" << endl;
  cin >> user.email;

  cout << "enter password" << endl;
  cin >> user.password;

  cout << "name" << endl;
  cin >> user.name;

  if (sellerDB.find(user.email) == sellerDB.end()) {
    sellerDB[user.email] = user;
    cout << "account created successfully" << endl;

    
  } else {
    cout << "account already exists" << endl;
   
  }
}

void sellerLogin() {
  string email, password;

  cout << "enter username" << endl;
  cin >> email;

  cout << "enter password" << endl;
  cin >> password;

  if (sellerDB.find(email) != sellerDB.end() && sellerDB[email].password == password) {
    cout << "logged in successfully" << endl;

    while (1) {
      cout << "add items 1" << endl;
      cout << "view items 2" << endl;
      cout << "logout 3" << endl;

      int inp1;
      cin >> inp1;

      if (inp1 == 1) {
        cout << "enter item details in the below format" << endl;
        cout << "item-name price qnty" << endl;

        struct item sitem;

        cin >> sitem.name >> sitem.price >> sitem.qnty;
        sitem.sellerid = email;

        items.push_back(sitem);
        sellerDB[email].goods.push_back(sitem);
      } 
      else if (inp1 == 2) {
        cout<<"|    All item list available    |"<<endl;
        cout<<"--------------------------------"<<endl;
        cout << "name price quantity" << endl;
        for (int i = 0; i < sellerDB[email].goods.size(); i++) {
          cout << sellerDB[email].goods[i].name << " " << sellerDB[email].goods[i].price <<" " << sellerDB[email].goods[i].qnty << endl;

        }
         cout<<"--------------------------------"<<endl;
      } 
      else if (inp1 == 3) {
        cout << "Thankyou"<<" "<<sellerDB[email].name<<"!! "<<"Logging out of store"<<endl;
        break;
      } else {
        cout << "invalid input";
      }

    }


  } else {
    cout << "invalid credentials" << endl;
   
  }
}


void showcustomers(){
   cout<<"|       list of all customers        |"<<endl;
  cout<<"--------------------------------"<<endl;
  for (auto i = buyerDB.begin(); i != buyerDB.end(); i++){
             cout<<(i->second).name<<" ";
    }
    cout<<endl;
    cout<<"--------------------------------"<<endl;
}

void showsellers(){
 cout<<"|       list of all sellers        |"<<endl;
  cout<<"--------------------------------"<<endl;
  for (auto i = sellerDB.begin(); i != sellerDB.end(); i++){
             cout<<(i->second).name<<" ";
   }
   cout<<endl;
   cout<<"--------------------------------"<<endl;
}

void showallproducts(){
    cout<<"|       list of all products in store       |"<<endl;
   cout<<"-----------------------------------"<<endl;
   for (auto i = sellerDB.begin(); i != sellerDB.end(); i++){
             for(int j=0;j<(i->second).goods.size();j++){
                if((i->second).goods[j].qnty>0){
                    cout<<"sellerid: "<<(i->first)<<" "<<"name:"<<(i->second).goods[j].name<<" ";
                    cout<<"price:"<<(i->second).goods[j].price<<" "<<"quantity:"<<(i->second).goods[j].qnty<<endl;
                }
               
             }
          }
           cout<<endl;
   cout<<"--------------------------------------"<<endl;
}

void ending(){
   ofstream file;
   file.open("store.txt");
   
   int n=buyerDB.size();
   file<<n<<endl;
   
    for (auto i = buyerDB.begin(); i != buyerDB.end(); i++){
             file<<(i->first)<<" "<<(i->second).password<<" "<<(i->second).name<<endl;
             int x=(i->second).wishlist.size();
             file<<x<<endl;
             for(int j=0;j<x;j++){
                 item pro;
                 pro = (i->second).wishlist[j].item;
                 file<< pro.name << " "<< (i->second).wishlist[j].price<<" "<<pro.sellerid<<endl;
             }
             int y=(i->second).orders.size();
             file<<y<<endl;
             for(int j=0;j<y;j++){
                 file<<(i->second).orders[j].item.name<< " " << (i->second).orders[j].quantity << " " << (i->second).orders[j].price << " " << (i->second).orders[j].item.sellerid<<endl;
             }
    }
     
   int m=sellerDB.size();
   file<<m<<endl;
   
    for (auto i = sellerDB.begin(); i != sellerDB.end(); i++){
             file<<(i->first)<<" "<<(i->second).password<<" "<<(i->second).name<<endl;
             int x=(i->second).goods.size();
             file<<x<<endl;
             for(int j=0;j<x;j++){
                 item pro;
                 pro = (i->second).goods[j];
                 file<< pro.name << " "<< pro.price<<" "<<pro.sellerid<<" "<<pro.qnty<<endl;
             }
             
    }
   
   file.close();
}

void starting(){
   ifstream file;
   file.open("store.txt");
   
   int n;
   file>>n;
   
   for(int i=0;i<n;i++){
      buyer person;
      string email,name,password;
      file>>email;
      file>>password;
      file>>name;
      
      int w_size;
      file>>w_size;
      for(int j=0;j<w_size;j++){
         order ord;
         item it;
        
         file>>it.name;
         file>>ord.price;
         file>>it.sellerid;
         
          ord.item=it;
         person.wishlist.push_back(ord);
      }
      
      int cart_size;
      file>>cart_size;
      for(int j=0;j<cart_size;j++){
         order ord;
         item it;
         file>>it.name;
         file>>ord.quantity;
         file>>ord.price;
         file>>it.sellerid;
         ord.item=it;
         person.orders.push_back(ord);
      }
      
      person.email=email;
      person.name=name;
      person.password=password;
      buyerDB.insert({email,person});
   
   }
   
   int m;
   file>>m;
   
   for(int i=0;i<m;i++){
      seller person;
      
     string email,name,password;
      file>>email;
      file>>password;
      file>>name;
      
      int good_size;
      file>>good_size;
      
      for(int j=0;j<good_size;j++){
         item it;
         file>>it.name;
         file>>it.price;
         file>>it.sellerid;
         file>>it.qnty;
         items.push_back(it);
          person.goods.push_back(it);
      }
      
     person.email=email;
      person.name=name;
      person.password=password;
       sellerDB.insert({email,person});
   
   }
   
   
   file.close();


}
