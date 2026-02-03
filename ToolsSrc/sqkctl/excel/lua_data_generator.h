
#pragma once

#include "i_generator.h"

namespace sqkctl {
class LuaDataGenerator : public IGenerator {
  public:
    LuaDataGenerator(const std::string &excelPath, const std::string &outPath) { SetPath(excelPath, outPath); }

    bool GenerateRoot(const std::map<std::string, ClassData *> &classData, bool isForUnreal = false) {
        std::string fileName;
        if (isForUnreal) {
            fileName = outPath + "/Lua/Init.lua";
        }
        else {
            fileName = outPath + "/Lua/Root.lua";
        }
        std::ofstream outputFile;
        OpenFile(fileName, outputFile);
        outputFile << "-- don't edit it, generated from xlsx files by tools\n";
        ClassData *pBaseObject = classData.at("IObject");
        
        std::string strElementData = "Excel = {}\n";
        strElementData += "Excel[\"" + pBaseObject->xStructData.className + "\"] = ";

        std::string path = pBaseObject->filePath;
        Files::StringReplace(path, strExcelDataPath, "");
        string preFixPath = "";
        if (isForUnreal)
        {
            preFixPath = "Excel/Data";
        }
        else
        {
            preFixPath = "Data";
        }
        strElementData += " require(\"" + preFixPath + path + "\")\n";

        for (std::map<std::string, ClassData *>::const_iterator it = classData.begin(); it != classData.end(); ++it)
        {
            const std::string &className = it->first;
            ClassData *pClassDta = it->second;
            if (className == "IObject") {
                continue;
            }

            if (it->second->beIncluded || it->second->beParted) {
                continue;
            }

            strElementData += "Excel[\"" + pClassDta->xStructData.className + "\"]";

            std::string path = pClassDta->filePath;
            Files::StringReplace(path, strExcelDataPath, "");

            strElementData += " = require(\"" + preFixPath + path + "\")\n";
        }
        outputFile << strElementData;
        outputFile.close();
        return false;
    };

    bool isStartWithNumber(const std::string s)
    {
        if (s[0] >= '0' && s[0] <= '9')
        {
            return true;
        }
        return false;
    }

    virtual bool Generate(const std::map<std::string, ClassData *> &classData) override {

        // generate for server
        GenerateRoot(classData);
        
        // generate for unreal
        GenerateRoot(classData, true);
        
        ClassData *pBaseObject = classData.at("IObject");
        for (std::map<std::string, ClassData *>::const_iterator it = classData.begin(); it != classData.end(); ++it) {
            const std::string &className = it->first;
            ClassData *pClassDta = it->second;

            if (pClassDta->beIncluded || pClassDta->beParted || className == "Include") {
                continue;
            }

            INFO("Gen for lua data ---> " << className);

            std::string path = pClassDta->filePath;
            Files::StringReplace(path, strExcelDataPath, "");
            std::string fileName = strLuaDataPath + path + ".lua";
            std::ofstream outputFile;
            OpenFile(fileName, outputFile);
            outputFile << "-- don't edit it, generated from xlsx files by tools\n";
            outputFile << "local " + className + " = {\n";

            for (std::map<std::string, ClassElement::ElementData *>::iterator itElement = pClassDta->xIniData.xElementList.begin();
                itElement != pClassDta->xIniData.xElementList.end(); ++itElement) {
                const std::string &strElementName = itElement->first;
                ClassElement::ElementData *pIniData = itElement->second;
                if (strElementName.empty() || isStartWithNumber(strElementName)) {
                    ERROR("Check ID start with number: " << strElementName << " file: " << className);
                }
                std::string strElementData = "\t" + strElementName + " = {\n";
                for (std::map<std::string, std::string>::iterator itProperty = pIniData->xPropertyList.begin(); itProperty != pIniData->xPropertyList.end();
                     ++itProperty) {
                    const std::string &strKey = itProperty->first;
                    const std::string &value = itProperty->second;
                    const std::string &type = pClassDta->xStructData.xPropertyList.at(strKey)->descList["Type"];
                    const std::string &desc = pClassDta->xStructData.xPropertyList.at(strKey)->descList["Desc"];
                    std::string outValue = "";
                    if (type == "int" || type == "bool" || type == "float" || type == "double" || type == "int64") {
                        if (value == "") {
                            outValue = "0";
                            WARN("Check default value not set, ID: " << strElementName << " file: " << className << " col: " << strKey);
                        }else {
                            outValue = value;
                        }
                    } else {
                        outValue = "\"" + value + "\"";
                    }
                    strElementData += "\t\t" + strKey + "=" + outValue + ",\n";
                }
                strElementData += "\t},\n";
                outputFile << strElementData;
            }
            
            std::string strFileEnd = "}\n";
            strFileEnd += "return " + className;
            outputFile << strFileEnd;
            outputFile.close();
        }
        
        return false;
    }
};
} // namespace sqkctl
