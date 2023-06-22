#ifndef BookingPayInfo_H
#define BookingPayInfo_H

#include <iostream>
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    class BookingPayInfo {
        private:
            uint total;
            uint subTotal;
            uint tax;
            time_t paidDate;
            uint billNumber;
            PaymentMethod paymentMethod;
        public:
            BookingPayInfo();
            BookingPayInfo(uint _total, uint _subtotal, uint _tax, time_t _paidDate, uint _billNumber, shared::PaymentMethod _paymentMethod = Card);

            uint getTotal();
            uint getSubTotal();
            uint getTax();
            time_t getPaidDate();
            uint getBillNumber();
            PaymentMethod getPaymentMethod();

            void setTotal(uint _total);
            void setSubTotal(uint _subtotal);
            void setTax(uint _tax);
            void setPaidDate(time_t _paidDate);
            void setBillNumber(uint _billNumber);
            void setPaymentMethod(shared::PaymentMethod _paymentMethod);
    };
};

#endif