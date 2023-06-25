#include <iostream>
#include "ScheduleRepository.h"
#include "../structures/HashTable.h"
#include "../structures/LinkedList.h"
#include "../common/Utils.h"
#include "../../domain/entities/Schedule.h"
 
using namespace std;
using namespace tdc::domain;
using namespace tdc::infraestructure::structures;

namespace tdc::infraestructure::repository {
    ScheduleRepository* ScheduleRepository::singleton= nullptr;
    
    ScheduleRepository* ScheduleRepository::GetInstance() {
        if(singleton == nullptr){
            singleton = new ScheduleRepository();
        }
        return singleton;
    }

    LinkedList<entities::Schedule> ScheduleRepository::getAll() {
        int maxSize = schedules->getMaxSize();
        LinkedList<entities::Schedule> list;
        for (int i = 0; i < maxSize; i++)
        {
            entities::Schedule* Schedule = schedules->get(i);
            if (Schedule != nullptr)
                list.insert(*Schedule);
        }
        return list;
    }

    entities::Schedule ScheduleRepository::get(int key) {
        return *schedules->get(key);
    }

    void ScheduleRepository::insertOrUpdate(entities::Schedule* newEntity) {
        int newKey = Utils::hashFunction(newEntity->getId(), schedules->getMaxSize());
        schedules->insert(newKey, newEntity);
    }

    void ScheduleRepository::remove(int key) {
        schedules->remove(key);
    }

    int ScheduleRepository::count() {
        return schedules->getSize();
    }
};