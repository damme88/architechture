// Behavioral_ChainOfRespon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <ctime>

using namespace  std;
class BaseMoney
{
  BaseMoney* next_;
public:
  BaseMoney()
  {
    next_ = NULL;
  }

  void SetNext(BaseMoney* n)
  {
    next_ = n;
  }
  void Add(BaseMoney* n)
  {
    if (next_ != NULL)
    {
      next_->Add(n);
    }
    else
    {
      next_ = n;
    }
  }

  virtual void handle(int i)
  {
    if (next_ != NULL)
    {
      next_->handle(i);
    }
  }
};

class Mon100: public BaseMoney
{
public:
  void handle(int value_money)
  {
    int number = value_money/100;
    int remain = value_money - number*100;
     cout << "\n Number of 100k type : " << number << "  ";
     BaseMoney::handle(remain);
  }
};

class Mon50: public BaseMoney
{
public:
  void handle(int value_money)
  {
    int number = value_money/50;
    int remain = value_money - number*50;
    cout << "\n Number of 50k type  : " << number << "  ";
    BaseMoney::handle(remain);
  }
};

class Mon20: public BaseMoney
{
public:
  void handle(int value_money)
  {
    int number = value_money/20;
    int remain = value_money - number*20;
    cout << "\n Number of 20k type  : " << number << "  ";
    BaseMoney::handle(remain);
  }
};

class Mon10: public BaseMoney
{
public:
  void handle(int value_money)
  {
    int number = value_money/10;
    int remain = value_money - number*10;
    cout << "\n Number of 10k type  : " << number << "  ";
    BaseMoney::handle(remain);
  }
};

class Mon5: public BaseMoney
{
public:
  void handle(int value_money)
  {
    int number = value_money/5;
    int remain = value_money - number*5;
    cout << "\n Number of 5k type   : " << number << "  ";
    BaseMoney::handle(remain);
  }
};


void main()
{
  Mon100 m100;

  Mon50 m50;
  Mon20 m20;
  Mon10 m10;
  Mon5 m5;

  m100.Add(&m50);
  m50.Add(&m20);
  m20.Add(&m10);
  m10.Add(&m5);

  m100.handle(3275);

  _getch();
	return;
}

