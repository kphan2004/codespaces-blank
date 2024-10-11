#include <iostream>
#include "Stock.h"

Stock::Stock()  : ownerName(""), accountNumber(0), numberOfShares(0), pricePerShare(0) {
}
Stock::Stock(std::string name, int accountNumber, int numberOfShares, double pricePerShare) {
    this->ownerName = name;
    this-> accountNumber = accountNumber;
    this->numberOfShares = numberOfShares;
    this->pricePerShare = pricePerShare;
}
void Stock::setOwner(std::string name) {
    this->ownerName = name;
}
std::string Stock::getOwnerName() {
    return ownerName;
}
void Stock::setAccountNumber(int accountNumber) {
    this->accountNumber = accountNumber;
}
int Stock::getAccountNumber() {
    return accountNumber;
}
void Stock::setNumberOfShares(int numberOfShares) {
    this->numberOfShares = numberOfShares;
}
int Stock::getNumberOfShares() {
    return numberOfShares;
}
void Stock::setPricePerShare(double pricePerShare) {
    this->pricePerShare = pricePerShare;
}
int Stock::getPricePerShare() {
    return pricePerShare;
}
void Stock::buyShares(int number) {
    numberOfShares += number;
}
void Stock::sellShares(int number) {
    if (number > numberOfShares) {
        std::cout << "Not enough shares to sell!!" << std::endl;
    } else {
        numberOfShares -= number;
    }
}
double Stock::getValueOfPortfolio() {
    return numberOfShares * pricePerShare;
}