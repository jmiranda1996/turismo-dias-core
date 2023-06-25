#ifndef BookingPayInfo_H
#define BookingPayInfo_H

#include <iostream>
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    class BookingPayInfo {
        private:
            int total;
            int subTotal;
            int tax;
            time_t paidDate;
            int billNumber;
            PaymentMethod paymentMethod;
        public:
            BookingPayInfo();
            BookingPayInfo(int _total, int _subtotal, int _tax, time_t _paidDate, int _billNumber, shared::PaymentMethod _paymentMethod = Card);

            int getTotal();
            int getSubTotal();
            int getTax();
            time_t getPaidDate();
            int getBillNumber();
            PaymentMethod getPaymentMethod();

            void setTotal(int _total);
            void setSubTotal(int _subtotal);
            void setTax(int _tax);
            void setPaidDate(time_t _paidDate);
            void setBillNumber(int _billNumber);
            void setPaymentMethod(shared::PaymentMethod _paymentMethod);
    };
};

#endif