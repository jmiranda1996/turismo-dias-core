#include <iostream>
#include <string>
#include <stdlib.h>

#include "./application/title-screen.h"
#include "./infraestructure/common/DataManager.h"

using namespace std;
using namespace tdc::infraestructure;

int main() {
  common::DataManager::loadAgencies("./resources/agency-dummy.csv");
  common::DataManager::loadAgencies("./resources/contact-form-dummy.csv");

  TitleScreen::load();
  
  cin.ignore(); 
  return 0;
}