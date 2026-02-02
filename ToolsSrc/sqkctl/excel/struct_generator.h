#pragma once

#if PLATFORM == PLATFORM_WIN
#include <direct.h>
#endif
#include "i_generator.h"
namespace sqkctl {
class StructGenerator : public IGenerator {

  public:
    StructGenerator(const std::string &excelPath, const std::string &outPath) { SetPath(excelPath, outPath); }

    virtual bool Generate(const std::map<std::string, ClassData *> &classData) override {
        ClassData *pBaseObject = classData.at("IObject");

        for (std::map<std::string, ClassData *>::const_iterator it = classData.begin(); it != classData.end(); ++it) {
            if (it->second->beParted) {
                continue;
            }

            const std::string &className = it->first;
            ClassData *pClassDta = it->second;

            INFO("Save for struct ---> " << className);
            std::string path = pClassDta->filePath;
            Files::StringReplace(path, strExcelIniPath, "");
            std::string fileName = strXMLStructPath + path + ".xml";
            std::ofstream outputFile;
            OpenFile(fileName, outputFile);
            outputFile << "<?xml version='1.0' encoding='utf-8' ?>\n<XML>\n";
            outputFile << "\t<Propertys>\n";

            for (std::map<std::string, ClassProperty *>::iterator itProperty = pClassDta->xStructData.xPropertyList.begin();
                 itProperty != pClassDta->xStructData.xPropertyList.end(); ++itProperty) {
                const std::string &propertyName = itProperty->first;
                ClassProperty *xPropertyData = itProperty->second;

                std::string strElementData = "\t\t<Property Id=\"" + propertyName + "\" ";
                for (std::map<std::string, std::string>::iterator itDesc = xPropertyData->descList.begin(); itDesc != xPropertyData->descList.end();
                     ++itDesc) {
                    const std::string &strKey = itDesc->first;
                    const std::string &value = itDesc->second;
                    strElementData += strKey + "=\"" + value + "\" ";
                }
                strElementData += "/>\n";
                outputFile << strElementData;
            }

            outputFile << "\t</Propertys>\n";
            outputFile << "\t<Records>\n";

            for (std::map<std::string, ClassRecord *>::iterator itRecord = pClassDta->xStructData.xRecordList.begin();
                 itRecord != pClassDta->xStructData.xRecordList.end(); ++itRecord) {
                const std::string &recordName = itRecord->first;
                ClassRecord *xRecordData = itRecord->second;

                // for desc
                std::string strElementData = "\t\t<Record Id=\"" + recordName + "\" ";
                for (std::map<std::string, std::string>::iterator itDesc = xRecordData->descList.begin(); itDesc != xRecordData->descList.end(); ++itDesc) {
                    const std::string &strKey = itDesc->first;
                    const std::string &value = itDesc->second;
                    strElementData += strKey + "=\"" + value + "\"\t ";
                }
                strElementData += ">\n";

                // for col list
                for (int i = 0; i < xRecordData->colList.size(); ++i) {
                    for (std::map<std::string, ClassRecord::RecordColDesc *>::iterator itDesc = xRecordData->colList.begin();
                         itDesc != xRecordData->colList.end(); ++itDesc) {
                        const std::string &strKey = itDesc->first;
                        const ClassRecord::RecordColDesc *pRecordColDesc = itDesc->second;

                        if (pRecordColDesc->index == i) {
                            strElementData += "\t\t\t<Col Type =\"" + pRecordColDesc->type + "\"\tTag=\"" + strKey + "\"/>";
                            if (!pRecordColDesc->desc.empty()) {
                                strElementData += "<!--- " + pRecordColDesc->desc + "-->\n";
                            } else {
                                strElementData += "\n";
                            }
                        }
                    }
                }
                outputFile << "\t\t</Record>\n";
            }

            outputFile << "\t</Records>\n";
            outputFile << "\t<Includes>\n";

            std::string strFileIncludeBody;
            for (auto item : pClassDta->includes) {
                auto includeClass = classData.at(item);

                std::string path = includeClass->filePath;
                Files::StringReplace(path, strExcelIniPath, "");
                std::string fileName = path + ".xml";

                strFileIncludeBody += "\t\t<Include Id=\"" + fileName + "\" />";
                strFileIncludeBody += "\n";
            }
            outputFile << strFileIncludeBody;
            outputFile << "\t</Includes>\n";
            outputFile << "</XML>";
            outputFile.close();
        }

        return false;
    }
};
} // namespace sqkctl
