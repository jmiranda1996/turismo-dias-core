#include <iostream>
// #include "Client.h"
// #include "Schedule.h"
#include "Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    class BookingPayInfo {
        private:
            uint total;
            uint subTotal;
            uint tax;
            time_t bookingDate;
            // boleta? Invoice Type
            // factura? Invoice Type
            PaymentMethod paymentMethod;
        public:
            BookingPayInfo();
            BookingPayInfo(uint _total, uint _subtotal, uint _tax, time_t _bookingDate, shared::PaymentMethod _paymentMethod = Card);

            uint getTotal();
            uint getSubTotal();
            uint getTax();
            time_t getBookingDate();
            PaymentMethod getPaymentMethod();

            void setTotal(uint _total);
            void setSubTotal(uint _subtotal);
            void setTax(uint _tax);
            void setBookingDate(time_t _bookingDate);
            void setPaymentMethod(shared::PaymentMethod _paymentMethod);
    };
};