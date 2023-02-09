#include <iostream>
#include "shock_cal.h"
#include "BasicExcel.hpp"
#include "json/json.h"
#include <string> //字符串类 c++标准库
#include <vector>
#include <codecvt>
using namespace YExcel;

void writeData(BasicExcelWorksheet*,BasicExcelCell*);
void createExcelFile();
void testExcel();
void testJson();
void cal(); // 整体计算（创建excel+写入数据）

std::string wstring2utf8string(const std::wstring& str)
{
    static std::wstring_convert<std::codecvt_utf8<wchar_t> > strCnv;
    return strCnv.to_bytes(str);
}

std::wstring utf8string2wstring(const std::string& str) {
    static std::wstring_convert<std::codecvt_utf8<wchar_t> > strCnv;
    return strCnv.from_bytes(str);
}

//    写入数据
void writeData(BasicExcelWorksheet* sheet1,BasicExcelCell* cell){
    for (int j = 2; j < 13; ++j) {
        Caculate c = Caculate("gong",j);
        double (*data) = c.getDataList();
        for (int k = 0; k < 7; ++k) {
            cell = sheet1->Cell((j-1),k);
            cell->SetDouble(*data);
            data++;
        }
    }
}

// 创建excel
void createExcelFile(){
    std::vector<std::string> titleList = {"P4","Ms","V2","P2","T2","P5","T5"};
    BasicExcel e;
    e.Load("shock.xls");
    e.New(1);
    BasicExcelWorksheet *sheet1 = e.GetWorksheet("Sheet1");
    BasicExcelCell *cell;
    // 写入标题
    for (int i =0; i<7 ;++i) {
        cell = sheet1->Cell(0,i);
        cell->SetWString(utf8string2wstring(titleList[i]).c_str());
    }
    // 写入数据
    writeData(sheet1,cell);
    if(!e.SaveAs("shock.xls")) std::cout << "写入失败" <<std::endl;
}

// 计算
void cal(){
//    char *titleList[7] = {"name","P4","Ms","P2","T2","P5","T5"};
    std::vector<std::string> titleList = {"name","P4","Ms","P2","T2","P5","T5"};
    BasicExcel e;
    e.Load("shock.xls");
    e.New(1);
    BasicExcelWorksheet *sheet1 = e.GetWorksheet("Sheet1");
    BasicExcelCell *cell;
//    写入标题
    for (int i =0; i<7 ;++i) {
        cell = sheet1->Cell(0,i);
        cell->SetWString(utf8string2wstring(titleList[i]).c_str());
//        cell->SetString(titleList[i]);
    }
//    写入数据
    for (int j = 2; j < 13; ++j) {
        Caculate c = Caculate("gong",j);
        double (*data) = c.getDataList();
        for (int k = 0; k < 7; ++k) {
            cell = sheet1->Cell((j-1),k);
            if(k==0){
                cell->SetString("gong");
            } else{
                cell->SetDouble(*data);
                data++;
            }
        }
    }

    e.SaveAs("shock.xls");
}

// 测试excel
void testExcel(){
    BasicExcel e;
    e.Load("test1.xls");
    e.New(1);
    BasicExcelWorksheet* sheet = e.GetWorksheet("Sheet1");
    BasicExcelCell* cell = sheet->Cell(0,0);
    cell->Set(3.6666);
    e.SaveAs("test1.xls");
//    ofstream f("example4.csv");
//    sheet->Print(f, ',', '\"'); // Save the first sheet as a CSV file.
//    f.close();
}

// 测试json
void testJson(){
    string str;
    Json::Value root;
    ifstream ifs;
    ifs.open("example.json");
    Json::CharReaderBuilder ReaderBuilder;
    Json::parseFromStream(ReaderBuilder,ifs,&root,&str);
    std::cout << root["encoding"];
}

int main() {
    createExcelFile();
    return 0;
}
