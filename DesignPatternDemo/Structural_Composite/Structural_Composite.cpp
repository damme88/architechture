// Structural_Composite.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;
class EProduct
{
public:
  virtual void Show() = 0;
};

class Phone: public EProduct
{

  int type_number_;
public:
  Phone(int num)
  {
    type_number_ = num;
  }
  void Show()
  {
    cout << "Number of types are "<< type_number_ << ' ' << std::endl;
  }
};

class Composite: public EProduct
{
  std::vector <EProduct*> p_child_; 
public:

  void add(EProduct *ele)
  {
    p_child_.push_back(ele);
  }
  void Show()
  {
    for (int i = 0; i < p_child_.size(); i++)
        p_child_[i]->Show();
  }
};

int main()
{
  Composite containers;
  containers.add(new Phone(4));
  containers.Show();


  _getch();
}


