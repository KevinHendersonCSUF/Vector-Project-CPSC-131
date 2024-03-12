#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
#include <algorithm>
template <typename T> class Item{
    public:
        T name;
        T expiration;
        T category;
        int quantity;
        Item(T n, T e, T c, int q){
            name = n;
            expiration = e;
            category = c;
            quantity = q;
        }
};
template<typename T> class Inventory {
    public:
        // Write Your code 
        Inventory() {
           std::vector<T> inventory = items;
        }
        std::vector<T> items;
        void addNewItem(T added_item) {
            for (T new_item : items) {
                if(new_item == added_item) {
                    std::cout << "Item is already present in inventory" << std::endl;
                }
                else {
                    items.push_back(added_item);
                }
            }
        } 
        void increaseQuantity(T itemname, int quantity) {
            typename std::vector<T>::iterator it = std::find(items.begin(), items.end(), itemname);
                if (it != items.end()) {
                    items[it].push_back(quantity);
                }
            
        } 
        void updateItem(T itemname, T expiration, T quantity, T category)  {
           typename std::vector<T>::iterator it = std::find(items.begin(), items.end(), itemname);
                if (it != items.end()) {
                    // items.push_back(expiration);
                    // items.push_back(quantity);
                    // items.push_back(category);
                    T updated_item{itemname, expiration, quantity, category};
                    items.push_back(updated_item); //<-- UNSURE IF GOOD
                }
                else {
                    std::cout << "item not found" << std::endl;
                }
            }
        void removeItem(T itemname) {
            // for (T search : items) {
                typename std::vector<T>::iterator it = std::find(items.begin(), items.end(), itemname);
                if (it != items.end()) {
                    items.erase(*it);
                }
                else {
                    std::cout << "Item not found" << std::endl;
                // }
            }
        }
        int Total() {
            int total = items.size();
            return total;
        }
        T searchItem(T itemname) {
            typename std::vector<T>::iterator it = std::find(items.begin(), items.end(), itemname);
                if (it != items.end()) {
                    return *it;
                }
                std::cout << "Item not found!!" << std::endl;
            } // USE FIND FOR THE OTHER FOR LOOPS
        
        void displayItems(){
            std::cout<<"-------Inventory-------"<<std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Expiration"<<std::setw(15)<<"Quantity"<<std::setw(10)<<"Category"<<std::endl;
            for(int i=0; i<items.size();i++){
                std::cout<<std::left << std::setw(20)<<items[i].name<<std::setw(15)<<items[i].expiration<<std::setw(15)<<items[i].quantity<<std::setw(15)<<items[i].category<<std::endl;
            }
        }
};
template<typename T>class Appointment{
    public: 
        T c_name;
        T ap_date;
        T ap_time;
        T CWID;
        Appointment(T n, T d, T t, T cw){
            c_name = n;
            ap_date = d;
            ap_time = t;
            CWID = cw; 
        }
};
template<typename T>class AppointmentSystem{
        public:
        // Write Your code 
        AppointmentSystem(){
            std::vector<T> appointment_system = ap;
        }
        std::vector<T> ap;
        void schedule(T cwid) {
            typename std::vector<T>::iterator it = std::find(ap.begin(), ap.end(), cwid);
                if (it != ap.end()) {
                    std::cout << "You have already scheduled an appointment!!!" << std::endl;
                }
                ap.push_back(cwid);
            
        }
        int Total_appointments(T date, T time) {
            int app_count = 0;
            typename std::vector<T>::iterator it_date = std::find(ap.begin(), ap.end(), date);
            typename std::vector<T>::iterator it_time = std::find(ap.begin(), ap.end(), time);
                if (it_date != ap.end()) {
                // app_count++; 
                if (it_time != ap.end()) {
                    app_count++;
                }
                }
            
            return app_count;
        }
        void removeRecent() {
            ap.pop_back();
        }
        void display(){
            std::cout<<"-------Appointments-------"<<std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Date"<<std::setw(15)<<"Time"<<std::setw(15)<<"CWID"<<std::endl;
            for(int i=0; i<ap.size();i++){
                std::cout<<std::left << std::setw(20)<<ap[i].c_name<<std::setw(15)<<ap[i].ap_date<<std::setw(15)<<ap[i].ap_time<<std::setw(15)<<ap[i].CWID<<std::endl;
            }
        }
};
int main(){
    // Remove comments and run following test cases
    Inventory<std::string> i1;
    Item<std::string> I1("Protien Bar","05/09/2023","Snacks",4);
    i1.addNewItem(I1);
    Item<std::string> I2("Milk","05/12/2023","Regular",2);
    i1.addNewItem(I2);
    Item<std::string> I3("Cerels","09/12/2023","Snacks",5);
    i1.addNewItem(I3);
    i1.displayItems();
    i1.updateItem("Milk","09/24/2023","Regular",3);
    i1.displayItems();
    i1.increaseQuantity("Cerels",10);
    i1.displayItems();
    try{
        i1.updateItem("bar","09/12/2023","Snacks",3);
    }
    catch(const char* msg){
        std::cout <<msg << std::endl;
    }
    i1.displayItems();
    i1.updateItem("Cerels","09/27/2023","Regular",4);
    i1.displayItems();
    i1.Total();
    try{
        i1.removeItem("Bread");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    try{
        i1.removeItem("Milk");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    i1.displayItems();
    try{
        i1.searchItem("Cerels");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    Appointment<std::string> a1("John Bob","09/12/2023","9:30AM","889456723");
    Appointment<std::string> a2("Jim Lee","09/12/2023","10:30AM","883476923");
    Appointment<std::string> a3("Chris Lynn","09/12/2023","12:00PM","879455714");
    Appointment<std::string> a4("Arnav Shah","09/12/2023","12:00PM","879459583");
    AppointmentSystem<std::string> s1;
    s1.schedule(a1);
    s1.schedule(a2);
    s1.schedule(a3);
    s1.schedule(a4);
    s1.display();
    s1.Total_appointments("09/12/2023","12:00PM");
    Appointment<std::string> a5("Chris Lynn","09/12/2023","12:00PM","879455714");
    s1.schedule(a4);
    s1.removeRecent();
    s1.display();
}