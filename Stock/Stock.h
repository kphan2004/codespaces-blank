#ifndef STOCK_H
#define STOCK_H

#include <string>

class Stock {
    private:
       std::string ownerName;
       int accountNumber;
       int numberOfShares;
       double pricePerShare;

    public:
        Stock();
        Stock(std::string name, int accountNumber, int numberOfShares, double pricePerShare);

        void setOwner(std::string name);
        std::string getOwnerName();

        void setAccountNumber( int accountNumber);
        int getAccountNumber();

        void setNumberOfShares(int numberOfShares);
        int getNumberOfShares();

        void setPricePerShare(double pricePerShare);
        int getPricePerShare();

        // Other methods
        void buyShares(int number);
        void sellShares(int number);
        double getValueOfPortfolio();
};
#endif