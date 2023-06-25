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
        billNumber = 0;
        paymentMethod = Card;
    };
    BookingPayInfo::BookingPayInfo(
        int _total, 
        int _subtotal, 
        int _tax, 
        time_t _paidDate, 
        int _billNumber,
        shared::PaymentMethod _paymentMethod
    ) {
        total = _total;
        subTotal = _subtotal;
        tax = _tax;
        paidDate = _paidDate;
        paymentMethod = _paymentMethod;
    };

    int BookingPayInfo::getTotal() { return total; };
    int BookingPayInfo::getSubTotal() { return subTotal; };
    int BookingPayInfo::getTax() { return tax; };
    time_t BookingPayInfo::getPaidDate() { return paidDate; };
    int BookingPayInfo::getBillNumber() { return billNumber; };
    PaymentMethod BookingPayInfo::getPaymentMethod() { return paymentMethod; };

    void BookingPayInfo::setTotal(int _total) { total = _total; };
    void BookingPayInfo::setSubTotal(int _subtotal) { subTotal = _subtotal; };
    void BookingPayInfo::setTax(int _tax) { tax = _tax; };
    void BookingPayInfo::setPaidDate(time_t _paidDate) { paidDate = _paidDate; };
    void BookingPayInfo::setBillNumber(int _billNumber) { billNumber = _billNumber; };
    void BookingPayInfo::setPaymentMethod(shared::PaymentMethod _paymentMethod) { paymentMethod = _paymentMethod; };
};