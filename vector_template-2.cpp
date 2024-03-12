// Name: Kevin Henderson
// CWID: 885395855
// Git repository Link:
// https://github.com/KevinHendersonCSUF/Vector-Project-CPSC-131.git
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

template <typename T> class Item {
public:
  T name;
  T expiration;
  T category;
  int quantity;
  Item(T n, T e, T c, int q) {
    name = n;
    expiration = e;
    category = c;
    quantity = q;
  }
};
template <typename T> class Inventory {
public:
  // Write Your code
  std::vector<Item<std::string>> items;
  bool addNewItem(Item<std::string> added_item) {
    bool present = false;
    for (int i = 0; i < items.size(); i++) {
      if (added_item.name == items[i].name) {
        std::cout << "Item is already present in inventory" << std::endl;
        present = true;
        return present;
      }
    }
    if (present == false) {
      items.push_back(added_item);
    }
    return present;
  }

  void increaseQuantity(T itemname, int quantity) {
    for (int i = 0; i < items.size(); i++) {
      if (items[i].name == itemname) {
        items[i].quantity = items[i].quantity + quantity;
      }
    }
  }
  bool updateItem(T itemname, T expiration, T category, int quantity) {
    bool found = false;
    for (int i = 0; i < items.size(); i++) {
      if (items[i].name == itemname) {
        items[i].expiration = expiration;
        items[i].category = category;
        items[i].quantity = quantity;
        found = true;
        return true;
      }
    }
    if (found == false) {
      std::string msg = "item not found";
      std::cout << msg << std::endl;
    }
    return found;
  }
  bool removeItem(T itemname) {
    bool found = false;
    for (int i = 0; i < items.size(); i++) {
      if (items[i].name == itemname) {
        items.erase(items.begin() + i);
        found = true;
        return found;
      }
    }
    if (found == false) {

      std::cout << "Item not found" << std::endl;
    }
    return found;
  }
  int Total() {
    int total = items.size();
    std::cout << "Total Number of items in inventory = " << total << std::endl;
    return total;
  }
  bool searchItem(T itemname) {
    bool found = false;
    for (int i = 0; i < items.size(); i++) {
      if (items[i].name == itemname) {
        std::cout << "Query for " << items[i].name << std::endl
                  << "Item = " << items[i].name << std::endl
                  << "Expiration Date = " << items[i].expiration << std::endl
                  << "category = " << items[i].category << std::endl
                  << "quantity = " << items[i].quantity << std::endl;
        found = true;
      }
    }
    if (found == false) {
      std::string msg = "Item not found!!";
    }
    return found;
  }
  void displayItems() {
    std::cout << "-------Inventory-------" << std::endl;
    std::cout << std::left << std::setw(20) << "Name" << std::setw(15)
              << "Expiration" << std::setw(15) << "Quantity" << std::setw(10)
              << "Category" << std::endl;
    for (int i = 0; i < items.size(); i++) {
      std::cout << std::left << std::setw(20) << items[i].name << std::setw(15)
                << items[i].expiration << std::setw(15) << items[i].quantity
                << std::setw(15) << items[i].category << std::endl;
    }
  }
};
template <typename T> class Appointment {
public:
  T c_name;
  T ap_date;
  T ap_time;
  T CWID;
  Appointment(T n, T d, T t, T cw) {
    c_name = n;
    ap_date = d;
    ap_time = t;
    CWID = cw;
  }
};
template <typename T> class AppointmentSystem {
public:
  // Write Your code
  std::vector<Appointment<std::string>> ap;
  void schedule(Appointment<std::string> app) {
    for (int i = 0; i < ap.size(); i++) {
      if (ap[i].CWID == app.CWID) {
        std::cout << "You have already scheduled an appointment!!!"
                  << std::endl;
      }
    }
    ap.push_back(app);
  }
  int Total_appointments(T date, T time) {
    int app_count = 0;
    for (int i = 0; i < ap.size(); i++) {
      if (ap[i].ap_date == date && ap[i].ap_time == time) {
        app_count++;
      }
    }
    std::cout << "Total Appointments = " << app_count << std::endl;
    return app_count;
  }
  void removeRecent() { ap.pop_back(); }
  void display() {
    std::cout << "-------Appointments-------" << std::endl;
    std::cout << std::left << std::setw(20) << "Name" << std::setw(15) << "Date"
              << std::setw(15) << "Time" << std::setw(15) << "CWID"
              << std::endl;
    for (int i = 0; i < ap.size(); i++) {
      std::cout << std::left << std::setw(20) << ap[i].c_name << std::setw(15)
                << ap[i].ap_date << std::setw(15) << ap[i].ap_time
                << std::setw(15) << ap[i].CWID << std::endl;
    }
  }
};
int main() {
  // Remove comments and run following test cases
  Inventory<std::string> i1;
  Item<std::string> I1("Protien Bar", "05/09/2023", "Snacks", 4);
  i1.addNewItem(I1);
  Item<std::string> I2("Milk", "05/12/2023", "Regular", 2);
  i1.addNewItem(I2);
  Item<std::string> I3("Cerels", "09/12/2023", "Snacks", 5);
  i1.addNewItem(I3);
  i1.displayItems();
  i1.updateItem("Milk", "09/24/2023", "Regular", 3);
  i1.displayItems();
  i1.increaseQuantity("Cerels", 10);
  i1.displayItems();
  try {
    i1.updateItem("bar", "09/12/2023", "Snacks", 3);
  } catch (const char *msg) {
    std::cout << msg << std::endl;
  }
  i1.displayItems();
  i1.updateItem("Cerels", "09/27/2023", "Regular", 4);
  i1.displayItems();
  i1.Total();
  try {
    i1.removeItem("Bread");
  } catch (const char *msg) {
    std::cout << msg << std::endl;
  }
  try {
    i1.removeItem("Milk");
  } catch (const char *msg) {
    std::cout << msg << std::endl;
  }
  i1.displayItems();
  try {
    i1.searchItem("Cerels");
  } catch (const char *msg) {
    std::cout << msg << std::endl;
  }
  Appointment<std::string> a1("John Bob", "09/12/2023", "9:30AM", "889456723");
  Appointment<std::string> a2("Jim Lee", "09/12/2023", "10:30AM", "883476923");
  Appointment<std::string> a3("Chris Lynn", "09/12/2023", "12:00PM",
                              "879455714");
  Appointment<std::string> a4("Arnav Shah", "09/12/2023", "12:00PM",
                              "879459583");
  AppointmentSystem<std::string> s1;
  s1.schedule(a1);
  s1.schedule(a2);
  s1.schedule(a3);
  s1.schedule(a4);
  s1.display();
  s1.Total_appointments("09/12/2023", "12:00PM");
  Appointment<std::string> a5("Chris Lynn", "09/12/2023", "12:00PM",
                              "879455714");
  s1.schedule(a4);
  s1.removeRecent();
  s1.display();
  return 0;
}