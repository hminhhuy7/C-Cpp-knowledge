
#ifndef _FAB_H
#define _FAB_H

#include <iostream>
#include <list>
#include <string>
#include <iomanip>


using namespace std;

typedef enum
{
    FOOD,
    BEVERAGE
}TypeFaB;

class FaB
{
    private:
        int id;
        string name;
        TypeFaB type;
        float prices;
    public:
        FaB(int idd, string namee, TypeFaB typee, float pricess )
        : id(idd), name(namee), type(typee), prices(pricess)  {};       

        void setId (int idd);
        void setName (string namee);
        void setType (TypeFaB typee);
        void setPrices (float pricess);

        int getId ();
        string getName ();
        TypeFaB getType();
        float getPrices();       
};

class FaBList
{
    private:
        list <FaB> listFaB;
    public:
        void addNewfab(FaB fb);
        void editFaB(int id);
        void deleteFaB(int id);
        void search(int id);
        void searchFaB(TypeFaB fo);
        bool compareNameFaB(string i2, list <FaB> :: iterator i3);
        list <FaB> fabList();
};

#endif