#include <pLoader.h>

namespace pLoader{
    pObject* loadSingleObject(std::vector<std::string> vPrismArgs){
        if(vPrismArgs.size() < 8) //if argc is invalid
            return nullptr; //object will never be created

        return new pObject(vPrismArgs[0].c_str(), vPrismArgs[1].c_str(), stoi(vPrismArgs[2]), stoi(vPrismArgs[3]), stoi(vPrismArgs[4]), stoi(vPrismArgs[5]), stoi(vPrismArgs[6]), stoi(vPrismArgs[7]));
    }

    pTextObject* loadSingleTextObject(std::vector<std::string> vPrismArgs){
        if(vPrismArgs.size() < 12) //if argc is invalid
            return nullptr; //object will never be created
        
        return new pTextObject(vPrismArgs[0].c_str(), vPrismArgs[1].c_str(), vPrismArgs[2].c_str(), stoi(vPrismArgs[3]), {(Uint8)stoi(vPrismArgs[4]), (Uint8)stoi(vPrismArgs[5]), (Uint8)stoi(vPrismArgs[6]), (Uint8)stoi(vPrismArgs[7])}, stoi(vPrismArgs[8]), stoi(vPrismArgs[9]), stoi(vPrismArgs[10]), stoi(vPrismArgs[11]));
    }
}