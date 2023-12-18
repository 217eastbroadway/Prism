#include <pLoader.h>

namespace pLoader{
    void loadPack(const char* fileDir, std::vector<pObject*> &vPrism, SDL_Renderer* rend){
        std::ifstream fileLoad;
        fileLoad.open(fileDir);

        std::vector<std::string> vPrismStr;

        std::string tempStr;
        while(std::getline(fileLoad, tempStr))
            vPrismStr.push_back(tempStr);

        for(int i = 0; i < vPrismStr.size(); i++){
            std::vector<std::string> vPrismArgs;

            pIO::fileHandler::parseString(vPrismStr[i].c_str(), vPrismArgs);
            if(vPrismArgs.size() < 8){ //if argc < 8 (pObject)
                pObject* tempObj = loadSingleObject(vPrismArgs, rend);
                if(tempObj)
                    vPrism.push_back(tempObj);
            }

            else {
                pTextObject* tempObj = loadSingleTextObject(vPrismArgs, rend);
                if(tempObj)
                    vPrism.push_back(tempObj);
            }
        }
    }
}