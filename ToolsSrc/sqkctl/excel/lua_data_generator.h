
#pragma once

#include "i_generator.h"

namespace sqkctl {
class LuaDataGenerator : public IGenerator {
  public:
    LuaDataGenerator(const std::string &excelPath, const std::string &outPath) { SetPath(excelPath, outPath); }

    bool GenerateRoot(const std::map<std::string, ClassData *> &classData, bool isForUnreal = false) {
        std::string fileName;
        if (isForUnreal) {
            fileName = outPath + "/XlsxCode/Lua/Init.lua";
        }
        else {
            fileName = outPath + "/XlsxCode/Lua/Root.lua";
        }
        std::string rootOutPath = outPath + "/XlsxCode/Lua";
#if PLATFORM == PLATFORM_WIN
        mkdir(rootOutPath.c_str());
#else
        mkdir(rootOutPath.c_str(), 0777);
#endif
        FILE *iniWriter = fopen(fileName.c_str(), "w");

        std::string strFileHead = "-- don't edit it, generated from xlsx files by tools\n";
        fwrite(strFileHead.c_str(), strFileHead.length(), 1, iniWriter);

        ClassData *pBaseObject = classData.at("IObject");
        
        std::string strElementData = "Excel = {}\n";
        strElementData += "Excel[\"" + pBaseObject->xStructData.className + "\"] = ";

        std::string path = pBaseObject->filePath;
        Files::StringReplace(path, strExcelIniPath, "");
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
            Files::StringReplace(path, strExcelIniPath, "");

            strElementData += " = require(\"" + preFixPath + path + "\")\n";
        }
        fwrite(strElementData.c_str(), strElementData.length(), 1, iniWriter);
        fclose(iniWriter);
        return false;
    };

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

            std::cout << "Gen for lua data ---> " << className << std::endl;

            std::string path = pClassDta->filePath;
            Files::StringReplace(path, strExcelIniPath, "");
            std::string fileName = strLuaDataPath + path + ".lua";

            FILE *iniWriter = fopen(fileName.c_str(), "w+");
            if (iniWriter == nullptr) {
                std::string folder = pClassDta->fileFolder;
                Files::StringReplace(folder, strExcelIniPath, "");
                std::string fileFolder = strLuaDataPath + folder;

#if PLATFORM == PLATFORM_WIN
                mkdir(fileFolder.c_str());
#else
                mkdir(fileFolder.c_str(), 0777);
#endif

                iniWriter = fopen(fileName.c_str(), "w+");
            }
            if (iniWriter) {
                std::string strFileHead = "-- don't edit it, generated from xlsx files by tools\n";
                fwrite(strFileHead.c_str(), strFileHead.length(), 1, iniWriter);


                std::string classNameBegin = "local " + className + " = {\n";
                fwrite(classNameBegin.c_str(), classNameBegin.length(), 1, iniWriter);

                for (std::map<std::string, ClassElement::ElementData *>::iterator itElement = pClassDta->xIniData.xElementList.begin();
                     itElement != pClassDta->xIniData.xElementList.end(); ++itElement) {

                    const std::string &strElementName = itElement->first;
                    ClassElement::ElementData *pIniData = itElement->second;

                    std::string strElementData = "\t" + strElementName + " = {\n";
                    for (std::map<std::string, std::string>::iterator itProperty = pIniData->xPropertyList.begin(); itProperty != pIniData->xPropertyList.end();
                         ++itProperty) {
                        const std::string &strKey = itProperty->first;
                        const std::string &value = itProperty->second;
                        const std::string &type = pClassDta->xStructData.xPropertyList.at(strKey)->descList["Type"];
                        const std::string &desc = pClassDta->xStructData.xPropertyList.at(strKey)->descList["Desc"];
                        std::string outValue = "";
                        if (type == "int" || type == "bool" || type == "float" || type == "double" || type == "int64")
                        {
                            outValue = value;
                        }else
                        {
                            outValue = "\"" + value + "\"";
                        }
                        strElementData += "\t\t" + strKey + "=" + outValue + ",\n";
                    }
                    strElementData += "\t},\n";

                    fwrite(strElementData.c_str(), strElementData.length(), 1, iniWriter);
                }

                std::string strFileEnd = "}\n";
                strFileEnd += "return " + className;
                fwrite(strFileEnd.c_str(), strFileEnd.length(), 1, iniWriter);
            } else {
                std::cout << "save for ini error!!!!!---> " << fileName << std::endl;
            }
            fclose(iniWriter);
        }

        return false;
    }
};
} // namespace sqkctl
