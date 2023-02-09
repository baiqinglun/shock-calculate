//
// Created by Administrator on 2023/2/7.
//
#include<cmath>
#include<iostream>
#include "shock_cal.h"

Caculate::Caculate(std::string _name, double _P4):name(_name),P4(_P4) {
    cA4();
}

Caculate::~Caculate() {

}

// 计算入射激波马赫数
void Caculate::cMs() {
    double _Ms = 0.1;
    double _leftValue = P4 / P1;
    double _rightValue = 1;
    while (_leftValue-_rightValue>0.0001)
    {
        _rightValue = (1 + 2 * r1 * (_Ms * _Ms - 1) / (r1 + 1)) / pow(1 - (r4 - 1) * a1 * (_Ms * _Ms - 1) / (r1 + 1) / a4 / _Ms, 2 * r4 / (r4 - 1));
        _Ms += 0.001;
    }
    std::cout <<"入射激波的马赫数：" << _Ms << std::endl;
    Ms = _Ms;
}

// 计算入射激波速度
void Caculate::cV2(){
    std::cout <<"入射激波的声速：" << a4 << std::endl;
    double _V2 = 2*a1*(Ms-1/Ms)/(r1+1);
    std::cout <<"入射激波的速度：" << _V2 << std::endl;
    V2 = _V2;
}

// 计算入射激波
void Caculate::cP2() {
    double _P2 = ((2 * r1 * Ms * Ms / (r1 + 1) - (r1 - 1) / (r1 + 1)))*P1;
    P2 = _P2;
    std::cout << "入射激波压力：" << P2 << std::endl;
}

// 计算入射激波温度
void Caculate::cT2() {
    double _T2 = ((2 * r1 * Ms * Ms - r1 + 1) * ((r1 - 1) * Ms * Ms + 2) / ((r1 + 1) * (r1 + 1) * Ms * Ms))*T1;
    T2 = _T2;
    std::cout << "入射激波温度：" << T2 << std::endl;
}

// 计算反射激波压力
void Caculate::cP5() {
    double Pbi = P2 / P1;
    double _P5 = ((3 * r1 - 1) * Pbi / (r1 + 1) - (r1 - 1) / (r1 + 1)) / ((r1 - 1) / (r1 + 1) * Pbi + 1);
    P5 = _P5;
    std::cout << "反射激波压力：" << P5 << std::endl;
}

// 计算密度比（入射激波与初始）
double Caculate::cRouBi1() {
    double _rouBi1 = (r1 + 1) * Ms * Ms / (2 + (r1 - 1) * Ms * Ms);
    std::cout << "密度比（入射激波与初始）：" << _rouBi1 << std::endl;
    return _rouBi1;
}

// 计算密度比（反射激波与入射激波）
double Caculate::cRouBi2() {
    double _rouBi2 = ((r1 + 1) * P5 + (r1 - 1) * P2) / ((r1 - 1) * P5 + (r1 + 1) * P2);
    std::cout << "密度比（反射激波与入射激波）：" << _rouBi2 << std::endl;
    return _rouBi2;
}

// 计算反射激波温度
void Caculate::cT5() {
    double _T5 = ((P5 / P2) / cRouBi2() * (P2 / P1) / cRouBi1())*T1;
    T5 = _T5;
    std::cout << "反射激波温度：" << T5 << std::endl;
}

// 计算氢气音速
void Caculate::cA4() {
    double _R = 4123;
    double _a4 = sqrt(r4 * _R * T1);
    a4 = _a4;
    std::cout << "氢气音速：" << a4 << std::endl;
}

double* Caculate::getDataList(){
    cMs();
    cV2();
    cP2();
    cT2();
    cP5();
    cT5();
    dataList[0] = getP4();
    dataList[1] = getMs();
    dataList[2] = getV2();
    dataList[3] = getP2();
    dataList[4] = getT2();
    dataList[5] = getP5();
    dataList[6] = getT5();

    return &dataList[0];
}

const double Caculate::getMs(){
    return Ms;
}
const double Caculate::getV2() {
    return V2;
}
const double Caculate::getP2() {
    return P2;
}
const double Caculate::getT2() {
    return T2;
}
const double Caculate::getP5() {
    return P5;
}
const double Caculate::getT5() {
    return T5;
}
const double Caculate::getP4() {
    return P4;
}
const double Caculate::getD() {
    return D;
}
const std::string Caculate::getName(){
    return name;
}
