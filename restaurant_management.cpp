#include<iostream>
#include<vector>

using namespace std;

class order{
    private:
    string food;
    int number_of_foods;
    int table_number;
    int order_number;
    friend void display(vector<order> total_orders);
    friend void change_something_in_order(order *s);
    public:
    order(string food_name,int number_of_foods1,int table_no,int order_no){
        food = food_name;
        number_of_foods = number_of_foods1;
        table_number = table_no;
        order_number = order_no;
    }

    int access_order(){
        return order_number;
    }

};

void add_order(string food_name,int number_of_foods1,int table_no,int order_no,vector<order> &total_orders){
    order s(food_name,number_of_foods1,table_no,order_no);
    total_orders.push_back(s);
}

void display(vector<order> total_orders){
    cout<<"---------All current orders--------------"<<endl;
    cout<<endl;
    for(int i=0;i<total_orders.size();i++){
        cout<<"////////////////////////////////////"<<endl;
        cout<<"Order number: "<<total_orders[i].order_number<<endl;
        cout<<"Food name: "<<total_orders[i].food<<endl;
        cout<<"Table name: "<<total_orders[i].table_number<<endl;
        cout<<"Number of same foods in the same table: "<<total_orders[i].number_of_foods<<endl;
        cout<<"//////////////////////////////////"<<endl;
    }
    cout<<"------------------------------------------"<<endl;

}

void change_something_in_order(order *s){
    char c;
    cout<<"Choose what you want to change in the order: ";
    cin>>c;
    if(c=='f'){
        string new_food;
        cout<<"enter the new food: ";
        cin>>new_food;
        s->food = new_food;
    }
    else if(c=='t'){
        int new_table;
        cout<<"enter the new table: ";
        cin>>new_table;
        s->table_number=new_table;
    }
    else if(c=='n'){
        int new_order;
        cout<<"enter the new number of foods: ";
        cin>>new_order;
        s->number_of_foods=new_order;
    }
    else{
        cout<<"Invalid input. Please try again"<<endl;
    }

}

void delete_order(vector<order> &total_orders,int order_number){
    for(int i=0;i<total_orders.size();i++){
        if(total_orders[i].access_order()==order_number){
            total_orders.erase(total_orders.begin()+i);
        }
    }
}
order* find_order(vector<order> &total_orders,int order_number){
    for(int i=0;i<total_orders.size();i++){
        if(total_orders[i].access_order()==order_number){
            return &total_orders[i];
        }
    }
    cout<<"Invalid entry"<<endl;
    return &total_orders[0];
}

int main(){
    vector<order> total_orders;
    cout<<"Welcome to the restaurent management system"<<endl;
    char operation;
    int ordernumber=0;
    while(true){
        cout<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"Please choose your operation:"<<endl;
        cout<<"For creating order please press c"<<endl;
        cout<<"For deleting order please press d"<<endl;
        cout<<"For changing something in an existing order please press h"<<endl;
        cout<<"For displaying all orders press p "<<endl;
        cout<<"And for quitting please press q ";
        cin>>operation;
        if(operation=='c'){
            ordernumber++;
            string food;
            int table;
            int number_of_f;
            cout<<"Please enter the food name: ";
            cin>>food;
            cout<<"Please enter the number of order of the same food: ";
            cin>>number_of_f;
            cout<<"Please enter the table number: ";
            cin>>table;
            add_order(food,number_of_f,table,ordernumber,total_orders);
        }
        else if(operation=='d'){
            cout<<"Please enter the order number of the order you want to delete: ";
            int order_n;
            cin>>order_n;
            delete_order(total_orders,order_n);
            cout<<"Order deleting successful"<<endl;
        }
        else if(operation=='h'){
            cout<<"Please enter order number: ";
            int order_N;
            cin>>order_N;
            order* sa = find_order(total_orders,order_N);
            change_something_in_order(sa);
        }
        else if(operation=='p'){
            display(total_orders);
        }
        else if(operation=='q'){
            cout<<"Terminating program";
            break;
        }
        else{
            cout<<"Invalid entry. Please try again"<<endl;
        }
        cout<<"*****************************************"<<endl;
    }





    return 0;
}