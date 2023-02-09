//
// Created by Administrator on 2023/2/7.
//

#ifndef H2_SHOCK_SHOCK_CAL_H
#define H2_SHOCK_SHOCK_CAL_H
#include <vector>
#include <string>
class Caculate{
public:
    Caculate(std::string _name,double _P4);
    ~Caculate();

    void cMs() ;// 计算入射激波马赫数
    void cV2() ;// 计算入射激波速度
    void cP2(); // 计算入射激波
    void cT2() ; // 计算入射激波温度
    void cP5() ; // 计算反射激波压力
    double cRouBi1() ; // 计算密度比（入射激波与初始）
    double cRouBi2() ; // 计算密度比（反射激波与入射激波）
    void cT5() ; // 计算反射激波温度
    void cA4() ;// 计算氢气音速

    double* getDataList();

    const double getMs();
    const double getV2();
    const double getP2();
    const double getT2();
    const double getP5();
    const double getT5();
    const double getP4();
    const double getD();
    const std::string getName();

private:
    const double r1 = 1.4; // 空气比热
    const double r4 = 1.4; // 氢气比热
    const double a1 = 340; // 空气声速
    const double T1 = 297; // 初始温度
    double D;
    double a4; // 氢气声速
    double P1 = 0.1; // 大气压
    double P4; // 爆破压力
    double Ms; // 入射激波马赫数
    double V2; // 入射激波速度
    double P2; // 入射激波压力
    double T2; // 入射激波温度
    double P5; // 反射激波压力
    double T5; // 反射激波温度
    std::string name; // 作者
    double dataList[7];
};


#endif //H2_SHOCK_SHOCK_CAL_H
