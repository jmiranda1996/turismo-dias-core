#include <iostream>
#include <string>
#include <stdlib.h>

#include "./application/TitleScreen.h"
#include "./infraestructure/common/DataManager.h"

using namespace std;
using namespace tdc::infraestructure;

int main() {
  bool win3264 = false;
  #if _WIN32 || _WIN64
    win3264 = true;
  #endif

  cout << win3264 << endl;

  if (win3264) {
    common::DataManager::loadAdmin("D:\\Estudios\\UPC\\turismo-dias-core\\resources\\admin-dummy.csv");
    common::DataManager::loadAgencies("D:\\Estudios\\UPC\\turismo-dias-core\\resources\\agency-dummy.csv");
    common::DataManager::loadClient("D:\\Estudios\\UPC\\turismo-dias-core\\resources\\client-dummy.csv");
    common::DataManager::loadContactForm("D:\\Estudios\\UPC\\turismo-dias-core\\resources\\contact-form-dummy.csv");
    common::DataManager::loadDriver("D:\\Estudios\\UPC\\turismo-dias-core\\resources\\driver-dummy.csv");
    common::DataManager::loadBus("D:\\Estudios\\UPC\\turismo-dias-core\\resources\\bus-dummy.csv");
    common::DataManager::loadSchedule("D:\\Estudios\\UPC\\turismo-dias-core\\resources\\schedule-dummy.csv");
    common::DataManager::loadBooking("D:\\Estudios\\UPC\\turismo-dias-core\\resources\\booking-dummy.csv");
  } else {
    common::DataManager::loadAdmin("./resources/admin-dummy.csv");
    common::DataManager::loadAgencies("./resources/agency-dummy.csv");
    common::DataManager::loadClient("./resources/client-dummy.csv");
    common::DataManager::loadContactForm("./resources/contact-form-dummy.csv");
    common::DataManager::loadDriver("./resources/driver-dummy.csv");
    common::DataManager::loadBus("./resources/bus-dummy.csv");
    common::DataManager::loadSchedule("./resources/schedule-dummy.csv");
    common::DataManager::loadBooking("./resources/booking-dummy.csv");
  }

  TitleScreen::load();
  
  
  cin.ignore(); 
  return 0;
}