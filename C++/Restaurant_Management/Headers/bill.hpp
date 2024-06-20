
#ifndef _BILL_H
#define _BILL_H

#include <iostream>
#include <list>
#include <string>
#include <iomanip>


using namespace std;

class Bill
{
    private:
        int order;
        string name;        
        float prices;
        int quantities;
        float total;
    public:
        Bill(string namee, float pricess, int quant)
        : name(namee), prices(pricess), quantities(quant) 
        {
            static int i = 1;
            order = i;
            i++;
        };      

        void setQuantities (int quant);

        int getOrder ();
        string getName ();        
        float getPrices();
        int getQuantities ();
        float getTotal();
};

class BillList
{
    private:
        list <Bill> listBill;
    public:   
        bool compareNameBill(string i1, list <Bill> :: iterator i2);
        void searchFaB(string name);
        void orderFaB(Bill bill);
        void editOrderedFaB(string name);
        void deleteOrderedFaB(string name);        
        list <Bill> billList();     
};

#endif