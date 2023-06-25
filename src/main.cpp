#include <iostream>
#include <string>
#include <stdlib.h>

#include "./application/TitleScreen.h"
#include "./infraestructure/common/DataManager.h"

using namespace std;
using namespace tdc::infraestructure;

int main() {
  common::DataManager::loadAdmin("./resources/admin-dummy.csv");
  common::DataManager::loadAgencies("./resources/agency-dummy.csv");
  common::DataManager::loadClient("./resources/client-dummy.csv");
  common::DataManager::loadContactForm("./resources/contact-form-dummy.csv");
  common::DataManager::loadDriver("./resources/driver-dummy.csv");
  common::DataManager::loadBus("./resources/bus-dummy.csv");
  common::DataManager::loadSchedule("./resources/schedule-dummy.csv");
  common::DataManager::loadBooking("./resources/booking-dummy.csv");

  TitleScreen::load();
  
  cin.ignore(); 
  return 0;
}