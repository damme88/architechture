// Creational_Prototype.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

class EProducts 
{
public:
  virtual EProducts* clone() = 0;
  virtual void ShowName() = 0;
};


class Phone : public EProducts 
{
public:
  EProducts*   clone() 
  { 
    return new Phone; 
  }

  void ShowName() 
  {
    cout << "This is Phone\n"; 
  }
};

class Tablet : public EProducts 
{
public:
  EProducts*   clone() 
  { 
    return new Tablet; 
  }

  void ShowName() 
  {
    cout << "This is tablet\n"; 
  }
};


class Factory 
{
public:
  static EProducts* make_product(int type);
private:
  static EProducts* s_prototypes[2];
};

EProducts* Factory::s_prototypes[] = {new Phone, new Tablet};


EProducts* Factory::make_product(int choice) 
{
  return s_prototypes[choice]->clone();
}


int main() 
{
  vector<EProducts*> product_list;
  product_list.push_back(Factory::make_product(0));
  product_list.push_back(Factory::make_product(1));

  for (int i= 0; i < product_list.size(); ++i)
  {
    product_list[i]->ShowName();
  }


  //Free
  for (int i=0; i < product_list.size(); ++i)
    delete product_list[i];
  product_list.clear();

  _getch();
}