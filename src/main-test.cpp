#include <iostream>
#include <string>
#include <stdlib.h>
#include "domain/entities/Client.h"
#include "domain/shared/User.h"
#include "signUp.hpp"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_STYLE_BOLD    "\x1b[1m"
#define ANSI_COLOR_RESET   "\x1b[0m"

using namespace std;
using namespace tdc;

// int main(int argc, char *argv[]) {
    
//     cout << "Turismo Dias Core" << endl;

//     tdc::domain::shared::User * newClient = new tdc::domain::entities::Client();
//     newClient->setUsername("Jerson Miranda");

//     cout << newClient->getUsername() << endl;

//     cin.get();
// }

/*
 ClientRepository* _repository = new ClientRepository();
  entities::Client* _client = new entities::Client();
  _client->setDocumentId("232323");
  _repository->insertOrUpdate(_client);

  entities::Client _client2 = *_repository->get(303);
  _client->setEmailAddress("bob@mail.com");
  _client2.setEmailAddress("alice@mail.com");
  std::cout << _client->getEmailAddress() << endl;
  std::cout << _client2.getEmailAddress() << endl;
*/