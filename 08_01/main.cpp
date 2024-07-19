#include<stdio.h>
#include"string.h"
#include <string>
#include <chrono>
#include <iostream>
template<typename T>
T Move(T&& right){
	return right;
}

int main()
{

	std::chrono::system_clock::time_point stratTime,endTime;
	//計測時間
	stratTime = std::chrono::system_clock::now();
	//文字列の初期化
	std::string a(100000, 'a');
	printf("100,000文字を移動とコピーで比較しました。\n");

	std::string copyConstructed(a);
	//計測終了
	endTime = std::chrono::system_clock::now();

	auto millisec = std::chrono::duration_cast<std::chrono::microseconds>(endTime - stratTime).count();
	std::cout <<" コピー:" << millisec << "us\n" << std::endl;

	//計測時間
	stratTime = std::chrono::system_clock::now();

	std::string moveConstructed(std::move(a));
	//計測終了
	endTime = std::chrono::system_clock::now();

	auto mi = std::chrono::duration_cast<std::chrono::microseconds>(endTime - stratTime).count();
	std::cout<<"移動:" << mi<< "us\n" << std::endl;
}