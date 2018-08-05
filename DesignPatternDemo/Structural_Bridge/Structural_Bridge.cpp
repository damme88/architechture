// Structural_Bridge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

class EProduct 
{
public:
  EProduct(int num) 
  {
    number_ = num;
  }

  virtual void show() 
  {
    std::cout << "Number of products  are: " << number_  << std::endl;
  }
protected:
  int number_;
};

class Phone: public EProduct 
{
public:
  Phone(int num, int num_type): EProduct(num) 
  {
    type_num_ = num_type;
  }

  void show() 
  {
    EProduct::show();
    std::cout << "Number of Phone Types are : " << type_num_  << std::endl;
  }
protected:
  int type_num_;
};

class Tablet: public EProduct 
{
public:
  Tablet(int number, int num_type): EProduct(number) 
  {
    type_num_ = number_;
  }

  void show() 
  {
    EProduct::show();
    std::cout << "Number of Tablet Types are : " << type_num_ << std::endl;
  }
protected:
  int type_num_;
};


class Shop 
{
public:
  Shop()
  {

  }
  Shop(int number) 
  {
    p_product_ = new EProduct(number);
  }

  virtual void ShowInfo() 
  {
    p_product_->show();
  }
protected:
  EProduct *p_product_;
};

class Ashop: public Shop 
{
public:
  Ashop(int number, int number_type) 
  {
    p_product_ = new Phone(number, number_type);
  }
};

class BShop: public Shop 
{
public:
  BShop(int number, int number_type) 
  {
    p_product_ = new Tablet(number, number_type);
  }
};

void main() 
{
  Shop* shop_a = new Ashop(30, 4); //Phone
  shop_a->ShowInfo();

  Shop* shop_b = new BShop(25, 3); //Tablet
  shop_b->ShowInfo();

  Shop* shop = new Shop(50); // Common
  shop->ShowInfo();

  _getch();
}


