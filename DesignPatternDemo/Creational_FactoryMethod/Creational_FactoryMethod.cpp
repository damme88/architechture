// Creational_FactoryMethod.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>


class EProducts
{
public:
  virtual void ShowName() = 0;
};

class Phone: public EProducts
{
public:
  void ShowName()
  {
    std::cout << "This is a phone"<<std::endl;
  }
};

class Tablet : public EProducts
{
public:
  void ShowName()
  {
    std::cout << "This is a tablet"<< std::endl;
  }
};


class ShopProduct
{
public:
  enum TypeProduct
  {
    PHONE = 0,
    TABLET = 1,
  };

  EProducts* GetProduct (int type)
  {
    if (type == PHONE)
    {
      return new Phone;
    }
    else if (type = TABLET)
    {
      return new Tablet;
    }

    return NULL;
  }
};


void main()
{
  ShopProduct* p_shop = new ShopProduct();

  EProducts* phone = p_shop->GetProduct(ShopProduct::PHONE);
  EProducts* tablet = p_shop->GetProduct(ShopProduct::TABLET);

  phone->ShowName();
  tablet->ShowName();


  _getch();
	return;
}

