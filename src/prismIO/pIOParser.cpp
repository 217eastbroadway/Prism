#include <pIO.h>

namespace pIO{
    namespace fileHandler{
        void parseString(const char* str, std::vector<std::string> &vStr){
            std::string tempStr;
            for(int i = 0; i < (int)strlen(str); i++){
                if(str[i] == '#'){ //Comment
                    if(str[i-1] != ' ' && str[i-1] != '"') vStr.push_back(tempStr);
                    return;
                } 

                if(str[i] == '"'){ //String
                    bool qmFound = false;

                    i++;
                    while(!qmFound)
                        if(str[i] == '\\' && str[i+1] == '"' && str[i+1] != '\0'){
                            tempStr += str[i+1];
                            i+=2;
                        }
                        else if(str[i] == '"')
                            qmFound = true;
                        else if(str[i+1] == '\0')
                            qmFound = true;
                        else
                            tempStr += str[i++];

                    vStr.push_back(tempStr);
                    tempStr.clear();
                    i++;
                    continue;
                }


                if(str[i] == ' '){ //Space (new arg)
                    vStr.push_back(tempStr);
                    tempStr.clear();
                }
                
                else tempStr += str[i];

                if(str[i+1] == '\0') //End of string
                    vStr.push_back(tempStr);
            }
        }
    }
}