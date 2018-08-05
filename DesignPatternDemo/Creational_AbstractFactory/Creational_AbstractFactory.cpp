// Creational_AbstractFactory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>


class PhoneProduct
{
public:
  virtual void ShowName() = 0;
};


class Galaxy : public PhoneProduct
{
public:
  void ShowName()
  {
    std::cout << "This galaxy S5" << std::endl;
  }
};

class IPhone : public PhoneProduct
{
public:
  void ShowName()
  {
    std::cout << "This Iphone 5"<< std::endl;
  }
};


class TabletProduct
{
public:
  virtual void ShowName() = 0;
};

class SamsungTab : public TabletProduct
{
public:
  void ShowName()
  {
    std::cout << "This Samsung Tab E"<< std::endl;
  }
};

class Ipad : public TabletProduct
{
  void ShowName()
  {
    std::cout << "This Ipad 10"<< std::endl;
  }
};


class FactoryProduct
{
public:
  virtual PhoneProduct* MakePhone() = 0;
  virtual TabletProduct* MakeTablet() = 0;
};


class SamsungFactory : public FactoryProduct
{
public:
  PhoneProduct* MakePhone()
  {
    return new Galaxy();
  }

  TabletProduct* MakeTablet()
  {
    return new SamsungTab();
  }
};

class AppleFactory : public FactoryProduct
{
public:
  PhoneProduct* MakePhone()
  {
    return new IPhone();
  }

  TabletProduct* MakeTablet()
  {
    return new Ipad();
  }
};

int main()
{
  FactoryProduct* samsung_product = new SamsungFactory();


  PhoneProduct* s_phone = samsung_product->MakePhone();
  TabletProduct* s_tab =  samsung_product->MakeTablet();

  s_phone->ShowName();
  s_tab->ShowName();

  FactoryProduct* ap_product = new AppleFactory();
  PhoneProduct* a_phone = ap_product->MakePhone();
  TabletProduct* a_tab =  ap_product->MakeTablet();

  a_phone->ShowName();
  a_tab->ShowName();

  _getch();
	return 0;
}

