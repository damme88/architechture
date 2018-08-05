// Creational_Builder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
class ElectronicProduct
{
private :
  string phone_;
  string tablet_;
  string screen_;
  string laptop_;
  string tivi_;

public:
  void set_phone(string phone)
  {
    this->phone_ = phone;
  }

  void set_tablet(string tablet)
  {
    this->tablet_ = tablet;
  }

  void set_laptop(string laptop)
  {
    this->laptop_ = laptop;
  }

  void set_screen(string screen)
  {
    this->screen_ = screen;
  }

  void set_tivi(string tivi)
  {
    this->tivi_ = tivi;
  }

  void ShowInfo()
  {
    std::cout << phone_.c_str() << std::endl;
    std::cout << tablet_.c_str() << std::endl;
    std::cout << screen_.c_str() << std::endl;
    std::cout << laptop_.c_str() << std::endl;
    std::cout << tivi_.c_str() << std::endl;
  }
};

class ShopBuilder
{
public:
  virtual void buildPhone()=0;
  virtual void buildTablet()=0;
  virtual void buildLaptop()=0;
  virtual void buildScreen()=0;
  virtual void buildTivi()=0;
  virtual ElectronicProduct* get_product()=0;
};

class HanoiShop : public ShopBuilder
{
private:
  ElectronicProduct *e_product_;
public:
  HanoiShop()
  {
    e_product_ = new ElectronicProduct();
  }

  void buildPhone()
  {
    e_product_->set_phone("galaxy s5");
  }

  void buildTablet()
  {
    e_product_->set_tablet("samsung tab");
  }

  void buildScreen()
  {
    e_product_->set_laptop("LG LCD");
  }

  void buildLaptop()
  {
    e_product_->set_screen("Asus laptop");
  }

  void buildTivi()
  {
    e_product_->set_tivi("LCD Tivi");
  }

  ElectronicProduct* get_product()
  {
    return this->e_product_;
  }
};


class HaiPhongShop:public ShopBuilder
{
private:
  ElectronicProduct *e_product_;
public:
  HaiPhongShop()
  {
    e_product_ = new ElectronicProduct();
  }

  void buildPhone()
  {
    e_product_->set_phone("Iphone");
  }

  void buildTablet()
  {
    e_product_->set_tablet("Ipad");
  }

  void buildScreen()
  {
    e_product_->set_laptop("samsung lcd");
  }

  void buildLaptop()
  {
    e_product_->set_screen("Dell laptop");
  }

  void buildTivi()
  {
    e_product_->set_tivi("Sony Tivi");
  }

  ElectronicProduct* get_product()
  {
    return this->e_product_;
  }
};


class ContractorShop
{
private:
  ShopBuilder *shop_builder_;

public:
  ContractorShop(ShopBuilder *houseBuilder)
  {
    this->shop_builder_ = houseBuilder;
  }

  ElectronicProduct *getProduct()
  {
    return shop_builder_->get_product();
  }

  void buildProduct()
  {
    shop_builder_->buildPhone();
    shop_builder_->buildTablet();
    shop_builder_->buildScreen();
    shop_builder_->buildLaptop();
    shop_builder_->buildTivi();
  }
};

int main()
{
  ShopBuilder *hanoi_shop = new HanoiShop();
  ShopBuilder *haiphong_shop = new HaiPhongShop();

  ContractorShop *p_shop1 = new ContractorShop(hanoi_shop);
  ContractorShop *p_shop2 = new ContractorShop(haiphong_shop);

  p_shop1->buildProduct();
  ElectronicProduct *e_product_1 = p_shop1->getProduct();

  p_shop2->buildProduct();
  ElectronicProduct *e_product_2 = p_shop2->getProduct();

  e_product_1->ShowInfo();

  std::cout << "\n\n\n\n";

  e_product_2->ShowInfo();

  _getch();
}

