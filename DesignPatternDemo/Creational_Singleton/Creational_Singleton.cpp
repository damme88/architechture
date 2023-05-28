// Creational_Singleton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

// Example
class ShopRule
{
private:
  static ShopRule* instance_;
  int form_;
  ShopRule() : form_(1){}

public:
  static ShopRule* getInstace() 
  {
    if(instance_ == NULL) 
      instance_ = new ShopRule();
    return instance_;
  }

  void setform(int fr) {form_ = fr;}
  int getform() {return form_;}

  void showRule() 
  {
    std::cout << "Form: " << form_ << endl;
  }
};


ShopRule* ShopRule::instance_ = NULL;

int main() 
{
  ShopRule *rule_shop = ShopRule::getInstace();
  rule_shop->setform(100);
  rule_shop->showRule();

  _getch();
  return 0;
}

