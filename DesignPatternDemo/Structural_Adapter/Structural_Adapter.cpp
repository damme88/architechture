// Structural_Adapter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
class Seller
{
public:
  virtual void draw() = 0;
};

// Legacy component
class ElectronicShop
{
public:
  ElectronicShop(int num_phone, int num_tablet)
  {
    num_phone_ = num_phone;
    num_tablet_ = num_tablet;
  }
  void ShowDraw()
  {
    std::cout << "Number of Phone: "<< num_phone_;
    std::cout << "Number of Tablet: "<< num_tablet_;
  }
private:
  int num_phone_;
  int num_tablet_;
};


class AdapterSeller: public Seller, private ElectronicShop
{
public:
  AdapterSeller(int num_p, int num_t): 
    ElectronicShop(num_p, num_t)
  {

  }

  virtual void draw()
  {
    ShowDraw();
  }
};

int main()
{
  Seller *p_custom = new AdapterSeller(120, 200);
  p_custom->draw();
}

