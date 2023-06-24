#ifndef BookingRepository_H
#define BookingRepository_H

#include <iostream>
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../../domain/interfaces/GenericInterface.h"
#include "../../domain/entities/Booking.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    class BookingRepository {
        private:
            HashTable<entities::Booking>* bookings;
        protected:
            BookingRepository() {
                bookings = new structures::HashTable<entities::Booking>(50000);
            }
            static BookingRepository* singleton;
        public:
            BookingRepository(BookingRepository &other) = delete;
            void operator=(const BookingRepository &) = delete;
            static BookingRepository *GetInstance();

            LinkedList<entities::Booking> getAll();
            entities::Booking get(uint key);
            void insertOrUpdate(entities::Booking* newEntity);
            void remove(uint key);
            uint count();
    };
};

#endif