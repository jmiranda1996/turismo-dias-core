#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "DataManager.h"
#include "../repository/AdminRepository.h"
#include "../repository/AgencyRepository.h"
#include "../repository/ContactFormRepository.h"
#include "../../domain/entities/Admin.h"
#include "../../domain/entities/Agency.h"
#include "../../domain/entities/ContactForm.h"
#include "../../domain/shared/Enums.h"
#include "../common/Utils.h"
 
using namespace std;
using namespace tdc::infraestructure::repository;
using namespace tdc::domain::entities;
using namespace tdc::domain::shared;
using namespace tdc::infraestructure::common;

namespace tdc::infraestructure::common {
    void DataManager::loadData(string _filename) {
        vector<vector<string>> content;
        vector<string> row;
        string line, word;
        fstream file (_filename, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                row.clear();
                stringstream str(line);
                while(getline(str, word, ',')) {
                    cout << word << endl;
                    row.push_back(word);
                }
                content.push_back(row);
            }
        }
        else
            throw runtime_error("No se pudo abrir el archivo " + _filename);
    };

    void DataManager::loadAdmin(string _filename) {
        AdminRepository* repository = AdminRepository::GetInstance();
        string line, word;
        fstream file (_filename, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                int i = 0;
                Admin entity;
                stringstream str(line);
                while(getline(str, word, ',')) {
                    switch (i)
                    {
                        case 0: entity.setDocumentId(word); break;
                        case 1: entity.setDocumentType(DNI); break;
                        case 2: entity.setUsername(word); break;
                        case 3: entity.setEmailAddress(word); break;
                        case 4: entity.setPasswordHash(word); break;
                        case 5: entity.setCreatedDate(time(0)); break;
                        default: break;
                    }
                    i++;
                }
                entity.setUserInfo(nullptr);
                entity.setStatus(Active);
                repository->insertOrUpdate(&entity);
            }
        }
        else
            throw runtime_error("No se pudo abrir el archivo " + _filename);
    }

    void DataManager::loadAgencies(string _filename) {
        AgencyRepository* repository = AgencyRepository::GetInstance();
        string line, word;
        fstream file (_filename, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                int i = 0;
                Agency* agency = new Agency();
                stringstream str(line);
                while(getline(str, word, ',')) {
                    if (agency != nullptr) {}
                    switch (i)
                    {
                        case 0: agency->setId(word); break;
                        case 1: agency->setAddress(word); break;
                        case 2: agency->setZipCode(word); break;
                        case 3: agency->setCountry(word); break;
                        case 4: agency->setPhoneNumber(word); break;
                        case 5: agency->setCity(word); break;
                        case 6: agency->setTerminalName(word); break;
                        default: break;
                    }
                    i++;
                }
                repository->insertOrUpdate(agency);
            }
        }
        else
            throw runtime_error("No se pudo abrir el archivo " + _filename);
    }

    void DataManager::loadContactForm(string _filename) {
        AgencyRepository* agencyRepository = AgencyRepository::GetInstance();
        ContactFormRepository* repository = ContactFormRepository::GetInstance();
        string line, word;
        fstream file (_filename, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                int i = 0;
                ContactForm entity;
                stringstream str(line);
                uint key;
                while(getline(str, word, ',')) {
                    switch (i)
                    {
                        case 0: entity.setDocumentId(word); break;
                        case 1: 
                            if (word == "1") entity.setDocumentType(DNI); 
                            else if (word == "2") entity.setDocumentType(CarnetExtranjeria); 
                            else if (word == "3") entity.setDocumentType(RUC); 
                            break;
                        case 2: entity.setFirstName(word); break;
                        case 3: entity.setLastName(word); break;
                        case 4: entity.setEmailAddress(word); break;
                        case 5: entity.setPhoneNumber(word); break;
                        case 6: entity.setSubject(word); break;
                        case 7: entity.setReason(word); break;
                        case 8: {
                            key = Utils::hashFunction(word, 50000);
                            Agency agency = agencyRepository->get(key);
                            Agency* _agency = new Agency();
                            _agency->setAddress(agency.getAddress());
                            _agency->setCity(agency.getCity());
                            _agency->setCountry(agency.getCountry());
                            _agency->setId(agency.getId());
                            _agency->setPhoneNumber(agency.getPhoneNumber());
                            _agency->setTerminalName(agency.getTerminalName());
                            _agency->setZipCode(agency.getZipCode());
                            entity.setAgency(_agency); 
                            break;
                        }
                        default: break;
                    }
                    i++;
                }
                repository->insertOrUpdate(&entity);
            }
        }
        else
            throw runtime_error("No se pudo abrir el archivo " + _filename);
    }
}