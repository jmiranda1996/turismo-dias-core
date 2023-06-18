#include <iostream>
#include "BookingPayInfo.h"
#include "../shared/Enums.h"

using namespace std;
using namespace tdc::domain::shared;

namespace tdc::domain::entities {
    BookingPayInfo::BookingPayInfo() {
        total = 0;
        subTotal = 0;
        tax = 0;
        paidDate = time(0);
        paymentMethod = Card;
    };
    BookingPayInfo::BookingPayInfo(
        uint _total, 
        uint _subtotal, 
        uint _tax, 
        time_t _paidDate, 
        shared::PaymentMethod _paymentMethod
    ) {
        total = _total;
        subTotal = _subtotal;
        tax = _tax;
        paidDate = _paidDate;
        paymentMethod = _paymentMethod;
    };

    uint BookingPayInfo::getTotal() { return total; };
    uint BookingPayInfo::getSubTotal() { return subTotal; };
    uint BookingPayInfo::getTax() { return tax; };
    time_t BookingPayInfo::getPaidDate() { return paidDate; };
    PaymentMethod BookingPayInfo::getPaymentMethod() { return paymentMethod; };

    void BookingPayInfo::setTotal(uint _total) { total = _total; };
    void BookingPayInfo::setSubTotal(uint _subtotal) { subTotal = _subtotal; };
    void BookingPayInfo::setTax(uint _tax) { tax = _tax; };
    void BookingPayInfo::setPaidDate(time_t _paidDate) { paidDate = _paidDate; };
    void BookingPayInfo::setPaymentMethod(shared::PaymentMethod _paymentMethod) { paymentMethod = _paymentMethod; };
};