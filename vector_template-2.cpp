#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
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
        // void SetQuantity(int quan) {quantity = quan;} //ADDED THIS IN SO I CAN SET THE QUANTITY FOR INCREASE QUANTITY FUNCTION
        // void SetExpiration(T exp) {expiration = exp;}
        // void SetCatagory(T cat) {category = cat;}
        // T GetName() {return name;}
        // int GetQuantity() {return quantity;}
};
template<typename T> class Inventory {
    public:
        // Write Your code 
        // Inventory() {
        //    std::vector<Item<std::string>> inventory = items;
        // }
        std::vector<Item<std::string>> items;
        void addNewItem(Item<std::string> added_item) {
            // for (Item<std::string> new_item : items) {
            //     if(new_item == added_item) {
            //         std::cout << "Item is already present in inventory" << std::endl;
            //     }
            //     else {
            //         items.push_back(added_item);
            //     } <-- CAUSING INVALID OPERANDS TO BINARY EXPRESSION COMPILE ERROR, TRYING STD::FIND, REVISIT RANGED FOR LOOP IF IT DOESNT WORK OUT
           
            // std::vector<Item<std::string>>::iterator it = std::find(items.begin(), items.end(), added_item);
            // if(it != items.end()) {
            //     std::cout << "Item is already present in inventory" << std::endl;
            // }
            // items.push_back(added_item); //CAUSING ISSUES
            for (int i = 0; i < items.size(); i++) {
                if (added_item.name == items[i].name) {
                    std::cout << "Item is already present in inventory" << std::endl;
                }
            }
            items.push_back(added_item);
            }
         
        void increaseQuantity(T itemname, int quantity) {
            for(int i = 0; i < items.size(); i++) {
                if(items[i].name == itemname) {
                    items[i].quantity = items[i].quantity + quantity;
                    // items[i].SetQuantity(new_quantity);
                }
            
        } 
        }
        void updateItem(T itemname, T expiration, T category, int quantity)  {
            for(int i = 0; i < items.size(); i++) {
                if(items[i].name == itemname) {
                items[i].expiration = expiration;
                items[i].category = category;
                items[i].quantity = quantity;
                }
                // else {
                //     std::cout << "item not found" << std::endl;
                // }
                if(items[i].name != itemname && i == items.size()-1){
                    std::cout << "item not found" << std::endl;
                }
            }
        }
        void removeItem(T itemname) {
            for(int i = 0; i < items.size(); i++) {
                if(items[i].name == itemname) {
                    items.erase(items.begin()+i);
                }
            //     else {
            //         std::cout << "Item not found" << std::endl;
                
            // }
                if(items[i].name != itemname && i == items.size()-1){
                    std::cout << "Item not found" << std::endl;
                }
            }
        }
        int Total() {
            int total = items.size();
            return total;
        }
        void searchItem(T itemname) {
        //    Item<std::string> found_item(itemname, "0", "0", 0);
            for(int i = 0; i < items.size(); i++) {
                if(items[i].name == itemname) {
                    std::cout << "Query for " << items[i].name << std::endl << "Item = "<< items[i].name << std::endl
                              << "Expiration Date = " << items[i].expiration << std::endl << "category = " << items[i].category
                              << std::endl << "quantity = " << items[i].quantity << std::endl;
                }
                if(items[i].name != itemname && i == items.size()-1){
                    std::cout << "Item not found!!" << std::endl;
                }
            }
            // return found_item;
        }
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
        // T GetCWID() {return CWID;}
        // T GetDate() {return ap_date;}
        // T GetTime() {return ap_time;}
};
template<typename T>class AppointmentSystem{
        public:
        // Write Your code 
        // AppointmentSystem(){
        //     std::vector<Appointment<std::string>> appointment_system = ap;
        // }
        std::vector<Appointment<std::string>> ap;
        void schedule(Appointment<std::string> app) {
            // std::vector<Appointment<std::string>>::iterator it = std::find(ap.begin(), ap.end(), cwid);
            //     if (it != ap.end()) {
            //         std::cout << "You have already scheduled an appointment!!!" << std::endl;
            //     }
            //     ap.push_back(cwid); //CAUSING ISSUES
            for(int i = 0; i < ap.size(); i++){
                if(ap[i].CWID == app.CWID) {
                    std::cout << "You have already scheduled an appointment!!!" << std::endl;
                }
                ap.push_back(app);
            }
        }
        int Total_appointments(T date, T time) {
            int app_count = 0;
            // std::vector<Appointment<std::string>>::iterator it_date = std::find(ap.begin(), ap.end(), date);
            // std::vector<Appointment<std::string>>::iterator it_time = std::find(ap.begin(), ap.end(), time);
            //     if (it_date != ap.end()) {
            //     // app_count++; 
            //     if (it_time != ap.end()) {
            //         app_count++;
            //     }
            //     }
            
            // return app_count; //CAUSING ISSUES
            for(int i = 0; i < ap.size(); i++){
                if(ap[i].ap_date == date && ap[i].ap_time == time) {
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