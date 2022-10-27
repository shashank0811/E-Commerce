#ifndef STOREINFO_H
#define STOREINFO_H


struct item {  // item details
  int qnty; // quantity available
  string name;
  int price;
  string sellerid;
};

struct order {
  struct item item;
  int quantity;
  int price;
};

struct cust{
  string name;
  string itemname;
  int qty;
  int total;
};

struct buyer {
  string email;
  string password;
  string name;
  vector<order>wishlist;
  vector<order>orders;
};

struct seller {
  string email;
  string password;
  string name;
  vector<item>goods;
};

#endif
