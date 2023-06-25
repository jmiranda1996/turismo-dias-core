#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "DataManager.h"
#include "../repository/AdminRepository.h"
#include "../repository/AgencyRepository.h"
#include "../repository/BookingRepository.h"
#include "../repository/BusRepository.h"
#include "../repository/ClientRepository.h"
#include "../repository/ContactFormRepository.h"
#include "../repository/DriverRepository.h"
#include "../repository/ScheduleRepository.h"
#include "../../domain/entities/Admin.h"
#include "../../domain/entities/Agency.h"
#include "../../domain/entities/Booking.h"
#include "../../domain/entities/Bus.h"
#include "../../domain/entities/Client.h"
#include "../../domain/entities/ContactForm.h"
#include "../../domain/entities/Driver.h"
#include "../../domain/entities/DriverInfo.h"
#include "../../domain/entities/Schedule.h"
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
                Admin* entity = new Admin();
                stringstream str(line);
                while(getline(str, word, ',')) {
                    switch (i)
                    {
                        case 0: entity->setDocumentId(word); break;
                        case 1: entity->setDocumentType(DNI); break;
                        case 2: entity->setUsername(word); break;
                        case 3: entity->setEmailAddress(word); break;
                        case 4: entity->setPasswordHash(word); break;
                        case 5: entity->setCreatedDate(time(0)); break;
                        default: break;
                    }
                    i++;
                }
                entity->setUserInfo(nullptr);
                entity->setStatus(Active);
                repository->insertOrUpdate(entity);
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

    void DataManager::loadBooking(string _filename) {
        BookingRepository* repository = BookingRepository::GetInstance();
        ClientRepository* clientRepostory = ClientRepository::GetInstance();
        ScheduleRepository* scheduleRepostory = ScheduleRepository::GetInstance();
        // BusRepository* busRepository = BusRepository::GetInstance();
        // AgencyRepository* agencyRepository = AgencyRepository::GetInstance();
        string line, word;
        fstream file (_filename, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                int i = 0;
                Booking* entity = new Booking();
                entities::Client* client = new entities::Client();
                Schedule* schedule = new Schedule();
                BookingPayInfo* bookingPayInfo = new BookingPayInfo();
                stringstream str(line);
                uint key;
                while(getline(str, word, ',')) {
                    switch (i)
                    {
                        case 0: entity->setId(word); break;
                        case 1: {
                            uint key = Utils::hashFunction(word, 50000);
                            entities::Client _client = clientRepostory->get(key);
                            client->setClientType(_client.getClientType());
                            client->setCreatedDate(_client.getCreatedDate());
                            client->setDocumentId(_client.getDocumentId());
                            client->setDocumentType(_client.getDocumentType());
                            client->setEmailAddress(_client.getEmailAddress());
                            client->setPasswordHash(_client.getPasswordHash());
                            client->setPoints(_client.getPoints());
                            client->setStatus(_client.getStatus());
                            client->setUserInfo(_client.getUserInfo());
                            client->setUsername(_client.getUsername());

                            entity->setClient(client);
                            break;
                        };
                        case 2: {
                            uint key = Utils::hashFunction(word, 50000);
                            Schedule _schedule = scheduleRepostory->get(key);
                            schedule->setBus(_schedule.getBus());
                            schedule->setDepartureDate(_schedule.getDepartureDate());
                            schedule->setFrom(_schedule.getFrom());
                            schedule->setId(_schedule.getId());
                            schedule->setInbound(_schedule.getInbound());
                            schedule->setOutbound(_schedule.getOutbound());
                            schedule->setPrice(_schedule.getPrice());
                            schedule->setReturnDate(_schedule.getReturnDate());
                            schedule->setStopovers(_schedule.getStopovers());
                            schedule->setTo(_schedule.getTo());

                            entity->setSchedule(schedule);
                            break;
                            break;
                        };
                        case 3: entity->setPassengers(stoi(word)); break;
                        case 4: {
                            vector<uint8_t> seats;
                            seats.push_back(stoi(word));
                            entity->setSeats(seats); 
                            break;
                        }
                        case 5: {
                            entity->setBookingDate(stol(word)/1000); 
                            bookingPayInfo->setPaidDate(stol(word)/1000);
                            break;
                        };
                        case 6: entity->setCancelledDate(stol(word)/1000); break;
                        case 7: bookingPayInfo->setTotal(stoi(word)); break;
                        case 8: bookingPayInfo->setBillNumber(stoi(word)); break;
                        default: break;
                    }
                    i++;
                }
                bookingPayInfo->setPaymentMethod(Card);
                uint tax = bookingPayInfo->getTotal() * 0.18;
                uint subtotal = bookingPayInfo->getTotal() - tax;
                bookingPayInfo->setTax(tax);
                bookingPayInfo->setSubTotal(subtotal);
                entity->setBookingPayInfo(bookingPayInfo);
                repository->insertOrUpdate(entity);
            }
        }
        else
            throw runtime_error("No se pudo abrir el archivo " + _filename);
    }

    void DataManager::loadBus(string _filename) {
        BusRepository* repository = BusRepository::GetInstance();
        DriverRepository* driverRepository = DriverRepository::GetInstance();
        string line, word;
        fstream file (_filename, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                int i = 0;
                Bus* entity = new Bus();
                entities::Driver* driver = new entities::Driver();
                stringstream str(line);
                uint key;
                while(getline(str, word, ',')) {
                    switch (i)
                    {
                        case 0: entity->setId(word); break;
                        case 1: entity->setSeats(stoi(word)); break;
                        case 2: {
                            uint key = Utils::hashFunction(word, 50000);
                            entities::Driver _driver = driverRepository->get(key);
                            driver->setCreatedDate(_driver.getCreatedDate());
                            driver->setDocumentId(_driver.getDocumentId());
                            driver->setDocumentType(_driver.getDocumentType());
                            driver->setDriverInfo(_driver.getDriverInfo());
                            driver->setEmailAddress(_driver.getEmailAddress());
                            driver->setPasswordHash(_driver.getPasswordHash());
                            driver->setStatus(_driver.getStatus());
                            driver->setUserInfo(_driver.getUserInfo());
                            driver->setUsername(_driver.getUsername());

                            entity->setDriver(driver);
                            break;
                        }
                        default: break;
                    }
                    i++;
                }
                // vector<BusAmenities> amenities = { Airco, Toilet };
                // entity->setAmenities(amenities);
                // entity->setServiceType(Express);
                repository->insertOrUpdate(entity);
            }
        }
        else
            throw runtime_error("No se pudo abrir el archivo " + _filename);
    }

    void DataManager::loadClient(string _filename) {
        ClientRepository* repository = ClientRepository::GetInstance();
        string line, word;
        fstream file (_filename, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                int i = 0;
                entities::Client* entity = new entities::Client();
                stringstream str(line);
                uint key;
                while(getline(str, word, ',')) {
                    switch (i)
                    {
                        case 0: entity->setDocumentId(word); break;
                        case 1: entity->setDocumentType(DNI); break;
                        case 2: entity->setUsername(word); break;
                        case 3: entity->setEmailAddress(word); break;
                        case 4: entity->setPasswordHash(word); break;
                        case 5: entity->setCreatedDate(time(0)); break;
                        case 6: entity->setPoints(uint(stoi(word))); break;
                        default: break;
                    }
                    i++;
                }
                entity->setUserInfo(nullptr);
                entity->setStatus(Active);
                entity->setClientType(User);
                repository->insertOrUpdate(entity);
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
                ContactForm* entity = new ContactForm();
                Agency* agency = new Agency();
                stringstream str(line);
                uint key;
                while(getline(str, word, ',')) {
                    switch (i)
                    {
                        case 0: entity->setDocumentId(word); break;
                        case 1: 
                            if (word == "1") entity->setDocumentType(DNI); 
                            else if (word == "2") entity->setDocumentType(CarnetExtranjeria); 
                            else if (word == "3") entity->setDocumentType(RUC); 
                            break;
                        case 2: entity->setFirstName(word); break;
                        case 3: entity->setLastName(word); break;
                        case 4: entity->setEmailAddress(word); break;
                        case 5: entity->setPhoneNumber(word); break;
                        case 6: entity->setSubject(word); break;
                        case 7: entity->setReason(word); break;
                        case 8: {
                            key = Utils::hashFunction(word, 50000);
                            Agency _agency = agencyRepository->get(key);
                            agency->setAddress(_agency.getAddress());
                            agency->setCity(_agency.getCity());
                            agency->setCountry(_agency.getCountry());
                            agency->setId(_agency.getId());
                            agency->setPhoneNumber(_agency.getPhoneNumber());
                            agency->setTerminalName(_agency.getTerminalName());
                            agency->setZipCode(_agency.getZipCode());
                            entity->setAgency(agency); 
                            break;
                        }
                        default: break;
                    }
                    i++;
                }
                repository->insertOrUpdate(entity);
            }
        }
        else
            throw runtime_error("No se pudo abrir el archivo " + _filename);
    }

    void DataManager::loadDriver(string _filename) {
        DriverRepository* repository = DriverRepository::GetInstance();
        string line, word;
        fstream file (_filename, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                int i = 0;
                entities::Driver* entity = new entities::Driver();
                entities::DriverInfo* entityInfo = new entities::DriverInfo();
                stringstream str(line);
                uint key;
                while(getline(str, word, ',')) {
                    switch (i)
                    {
                        case 0: entity->setDocumentId(word); break;
                        case 1: entity->setDocumentType(DNI); break;
                        case 2: entity->setUsername(word); break;
                        case 3: entity->setEmailAddress(word); break;
                        case 4: entity->setPasswordHash(word); break;
                        case 5: entity->setCreatedDate(stoul(word)); break;
                        case 6: entityInfo->setDriverLicense(word); break;
                        case 7: entityInfo->setIssue(stoul(word)); break;
                        case 8: entityInfo->setExpiration(stoul(word)); break;
                        default: break;
                    }
                    i++;
                }
                entity->setDriverInfo(entityInfo);
                repository->insertOrUpdate(entity);
            }
        }
        else
            throw runtime_error("No se pudo abrir el archivo " + _filename);
    }

    void DataManager::loadSchedule(string _filename) {
        ScheduleRepository* repository = ScheduleRepository::GetInstance();
        BusRepository* busRepository = BusRepository::GetInstance();
        AgencyRepository* agencyRepository = AgencyRepository::GetInstance();
        string line, word;
        fstream file (_filename, ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                int i = 0;
                Schedule* entity = new Schedule();
                Bus* bus = new Bus();
                Agency* inbound = new Agency();
                Agency* outbound = new Agency();
                stringstream str(line);
                uint key;
                while(getline(str, word, ',')) {
                    switch (i)
                    {
                        case 0: entity->setId(word); break;
                        case 1: entity->setFrom(word); break;
                        case 2: entity->setTo(word); break;
                        case 3: entity->setDepartureDate(stol(word)/1000); break;
                        case 4: entity->setReturnDate(stol(word)/1000); break;
                        case 5: entity->setPrice(stoi(word)); break;
                        case 6: {
                            uint key = Utils::hashFunction(word, 50000);
                            Bus _bus = busRepository->get(key);
                            bus->setAmenities(_bus.getAmenities());
                            bus->setDriver(_bus.getDriver());
                            bus->setId(_bus.getId());
                            bus->setSeats(_bus.getSeats());
                            bus->setServiceType(_bus.getServiceType());

                            entity->setBus(bus);
                            break;
                        };
                        case 7: {
                            uint key = Utils::hashFunction(word, 50000);
                            Agency _inbound = agencyRepository->get(key);
                            inbound->setAddress(_inbound.getAddress());
                            inbound->setCity(_inbound.getCity());
                            inbound->setCountry(_inbound.getCountry());
                            inbound->setId(_inbound.getId());
                            inbound->setPhoneNumber(_inbound.getPhoneNumber());
                            inbound->setTerminalName(_inbound.getTerminalName());
                            inbound->setZipCode(_inbound.getZipCode());

                            entity->setInbound(inbound);
                            break;
                        };
                        case 8: {
                            uint key = Utils::hashFunction(word, 50000);
                            Agency _outbound = agencyRepository->get(key);
                            outbound->setAddress(_outbound.getAddress());
                            outbound->setCity(_outbound.getCity());
                            outbound->setCountry(_outbound.getCountry());
                            outbound->setId(_outbound.getId());
                            outbound->setPhoneNumber(_outbound.getPhoneNumber());
                            outbound->setTerminalName(_outbound.getTerminalName());
                            outbound->setZipCode(_outbound.getZipCode());

                            entity->setOutbound(outbound);
                            break;
                        }
                        default: break;
                    }
                    i++;
                }
                repository->insertOrUpdate(entity);
            }
        }
        else
            throw runtime_error("No se pudo abrir el archivo " + _filename);
    }
}