#include "BitcoinMarketInfo.hpp"

using std::cout;
using std::endl;
using std::string;

BitcoinMarketInfo::BitcoinMarketInfo() {
    high = 0.0;
    low = 0.0;
    vol = 0.0;
    last = 0.0;
    buy = 0.0;
    sell = 0.0;
    date = 0;
    serviceURL = TICKER_LITECOIN;
}

void BitcoinMarketInfo::setHigh(double high){
    this->high = high;
}

void BitcoinMarketInfo::setLow(double low){
    this->low = low;
}

void BitcoinMarketInfo::setVol(double vol){
    this->vol = vol;
}

void BitcoinMarketInfo::setLast(double last){
    this->last = last;
}

void BitcoinMarketInfo::setBuy(double buy){
    this->buy = buy;
}

void BitcoinMarketInfo::setSell(double sell){
    this->sell = sell;
}

void BitcoinMarketInfo::setDate(int date){
    this->date = date;
}

string BitcoinMarketInfo::toString(){
    std::stringstream ss;

	ss << "BitcoinMarketInfo\n";
    ss << "High: " << this->high << "\n";
    ss << "Low: " << this->low << "\n";
    ss << "Vol: "  << this->vol << "\n";
    ss << "Last: " << this->last << "\n";
    ss << "Buy: "  << this->buy << "\n";
    ss << "Sell: " << this->sell << "\n";
    ss << "Date: " << this->date;

    return ss.str();
}

int BitcoinMarketInfo::getBitcoinMarketInfo() {


    Curly curly;
    Json::Value retJSON;

    if (curly.Fetch(this->serviceURL) == CURLE_OK){

        if (curly.HttpStatus() != 200) {
            return FAIL;
        }
        retJSON = curly.getContentJSON();
        //std::cout << "status: " << curly.HttpStatus() << std::endl;
        //std::cout << "type: " << curly.Type() << std::endl;
        //std::vector<std::string> headers = curly.Headers();

        //for(std::vector<std::string>::iterator it = headers.begin();
        //        it != headers.end(); it++)
        //    std::cout << "Header: " << (*it) << std::endl;
        if (!retJSON.empty()) {
            this->setBuy(retJSON.get("ticker", "" ).get("buy", "" ).asDouble());
            this->setDate(retJSON.get("ticker", "" ).get("date", "" ).asInt());
            this->setHigh(retJSON.get("ticker", "" ).get("high", "" ).asDouble());
            this->setLast(retJSON.get("ticker", "" ).get("last", "" ).asDouble());
            this->setLow(retJSON.get("ticker", "" ).get("low", "" ).asDouble());
            this->setVol(retJSON.get("ticker", "" ).get("vol", "" ).asDouble());
            this->setSell(retJSON.get("ticker", "" ).get("sell", "" ).asDouble());
            return SUCCESS;
        }
    }

    return FAIL;
}


int main(void) {
    
    BitcoinMarketInfo bitcoinMarketInfo;
    if (bitcoinMarketInfo.getBitcoinMarketInfo() == SUCCESS) {
        cout << bitcoinMarketInfo.toString() << endl;
    }
    return 0;
}