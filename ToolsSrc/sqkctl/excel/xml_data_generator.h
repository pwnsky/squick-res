
#pragma once

#include "i_generator.h"

namespace sqkctl {
class XMLDataGenerator : public IGenerator {
  public:
    XMLDataGenerator(const std::string &excelPath, const std::string &outPath) { SetPath(excelPath, outPath); }

    virtual bool Generate(const std::map<std::string, ClassData *> &classData) override {
        ClassData *pBaseObject = classData.at("IObject");
        for (std::map<std::string, ClassData *>::const_iterator it = classData.begin(); it != classData.end(); ++it) {
            const std::string &className = it->first;
            ClassData *pClassDta = it->second;

            if (pClassDta->beIncluded || pClassDta->beParted || className == "Include") {
                continue;
            }

            INFO("Save for xml data ---> " << className);

            std::string path = pClassDta->filePath;
            Files::StringReplace(path, strExcelDataPath, "");
            std::string fileName = strXMLDataPath + path + ".xml";
            std::ofstream outputFile;
            OpenFile(fileName, outputFile);
            
            std::string strFileHead = "<?xml version='1.0' encoding='utf-8' ?>\n<XML>\n";
            outputFile << strFileHead;
            for (std::map<std::string, ClassElement::ElementData *>::iterator itElement = pClassDta->xIniData.xElementList.begin();
                 itElement != pClassDta->xIniData.xElementList.end(); ++itElement) {

                const std::string &strElementName = itElement->first;
                ClassElement::ElementData *pIniData = itElement->second;

                std::string strElementData = "\t<Object Id=\"" + strElementName + "\" ";
                for (std::map<std::string, std::string>::iterator itProperty = pIniData->xPropertyList.begin(); itProperty != pIniData->xPropertyList.end();
                     ++itProperty) {
                    const std::string &strKey = itProperty->first;
                    const std::string &value = itProperty->second;
                    strElementData += strKey + "=\"" + value + "\" ";
                }
                strElementData += "/>\n";
                outputFile << strElementData;
            }

            std::string strFileEnd = "</XML>";
            outputFile << strFileEnd;
            outputFile.close();
        }

        return false;
    }
};
} // namespace sqkctl
