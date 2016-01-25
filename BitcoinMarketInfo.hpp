#include <iostream>
#include <sstream>
#include "curly.h"
#include "MercadoDoBitcoinEndpoints.h"

using std::string;

// Armazena as informações do mercado de bitcoin ou litecoin.
class BitcoinMarketInfo {

    public:
        BitcoinMarketInfo();
        void setHigh(double high);
        void setLow(double low);
        void setVol(double vol);
        void setLast(double last);
        void setBuy(double buy);
        void setSell(double sell);
        void setDate(int date);
        int getBitcoinMarketInfo();
        string toString();
    private:
        double high;
        double low;
        double vol;
        double last;
        double buy;
        double sell;
        int date;
        string serviceURL;
};