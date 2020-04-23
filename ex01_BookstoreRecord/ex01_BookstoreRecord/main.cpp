//
//  main.cpp
//  ex01_BookstoreRecord
//
//  Created by Chun-Jen Hsueh on 4/22/20.
//  Copyright © 2020 Chun-Jen Hsueh. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Sales_item.h"

int main()
{
  std::ifstream inputFile;
  inputFile.open("input_file.in");
    
  Sales_item total;
  if (inputFile >> total)
  {
    Sales_item trans;
    while (inputFile >> trans)
    {
      if (total.isbn() == trans.isbn())
        total += trans;
      else
        {
          std::cout << total << std::endl;
          total = trans;
        }
    }
      std::cout << total << std::endl;
  }
  else
  {
    std::cerr << "No data!" << std::endl;
    return -1;
  }
  return 0;
}
