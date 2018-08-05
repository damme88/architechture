// Behavioral_Command.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>

class Person;

class Command
{
  Person *object_;
  void (Person::*method)();

public:
  Command(Person* obj = 0, void(Person::*meth)() = 0)
  {
    object_ = obj;
    method = meth;
  }

  void Excute()
  {
    if (object_ != NULL)
    {
      (object_->*method)();
    }
  }
};

class Person
{
  std::string name_;
  Command cmd_;
public:
  Person(std::string n, Command c) : cmd_(c)
  {
    name_ = n;
  }

  void Talk()
  {
    std::cout << name_ << " is talking" << std::endl;
    cmd_.Excute();
  }

  void Sleep()
  {
    std::cout << name_ << " is Sleeping" << std::endl;
    cmd_.Excute();
  }

  void Write()
  {
    std::cout << name_ << " is writing" << std::endl;
    cmd_.Excute();
  }

  void Listen()
  {
    std::cout << name_ << " is listening" << std::endl;
    cmd_.Excute();
  }
};

void main()
{
  Person pToan("Toan", Command());

  Person pDung("Dung", Command(&pToan, &Person::Listen));
  Person plong("Long", Command(&pDung, &Person::Write));
  Person pMai("Mai", Command(&plong, &Person::Sleep));

  pMai.Talk();
	_getch();
}

