#ifndef Enums_H
#define Enums_H

namespace tdc::domain::shared {
    enum UserType { Client, Employee, Unknown };
    enum UserStatus { Inactive, Active, PendingConfirm };
};

#endif