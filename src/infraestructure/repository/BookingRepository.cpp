#include <iostream>
#include "BookingRepository.h"
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../common/Utils.h"
#include "../../domain/entities/Booking.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    BookingRepository* BookingRepository::singleton= nullptr;
    
    BookingRepository* BookingRepository::GetInstance() {
        if(singleton == nullptr){
            singleton = new BookingRepository();
        }
        return singleton;
    }

    LinkedList<entities::Booking> BookingRepository::getAll() {
        int maxSize = bookings->getMaxSize();
        LinkedList<entities::Booking> list;
        for (int i = 0; i < maxSize; i++)
        {
            entities::Booking* Booking = bookings->get(i);
            if (Booking != nullptr)
                list.insert(*Booking);
        }
        return list;
    }

    entities::Booking BookingRepository::get(int key) {
        return *bookings->get(key);
    }

    void BookingRepository::insertOrUpdate(entities::Booking* newEntity) {
        int newKey = Utils::hashFunction(newEntity->getId(), bookings->getMaxSize());
        bookings->insert(newKey, newEntity);
    }

    void BookingRepository::remove(int key) {
        bookings->remove(key);
    }

    int BookingRepository::count() {
        return bookings->getSize();
    }
};