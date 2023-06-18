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
            // boleta? Invoice Type
            // factura? Invoice Type
            PaymentMethod paymentMethod;
        public:
            BookingPayInfo();
            BookingPayInfo(uint _total, uint _subtotal, uint _tax, time_t _paidDate, shared::PaymentMethod _paymentMethod = Card);

            uint getTotal();
            uint getSubTotal();
            uint getTax();
            time_t getPaidDate();
            PaymentMethod getPaymentMethod();

            void setTotal(uint _total);
            void setSubTotal(uint _subtotal);
            void setTax(uint _tax);
            void setPaidDate(time_t _paidDate);
            void setPaymentMethod(shared::PaymentMethod _paymentMethod);
    };
};

#endif