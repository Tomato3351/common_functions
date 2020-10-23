// common_functions.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <vector>
#include <iostream>


std::vector<std::string> split(const std::string& str, const std::string& delim) {
	std::vector<std::string> res;
	if ("" == str) return res;
	//先将要切割的字符串从string类型转换为char*类型
	char* strs = new char[str.length() + 1];
	strcpy(strs, str.c_str());
	char* d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());
	char* p = strtok(strs, d);
	while (p) {
		std::string s = p; //分割得到的字符串转换为string类型
		res.push_back(s); //存入结果数组
		p = strtok(NULL, d);
	}
	delete[] strs;
	delete[] d;
	return res;
}

template <typename Type>
Type string2Num(const std::string& str) {
	std::istringstream iss(str);
	Type num;
	iss >> num;
	return num;
}

// string转wstring
std::wstring StringToWstring(const std::string str) {
	unsigned len = str.size() * 2;// 预留字节数
	setlocale(LC_CTYPE, "");     //必须调用此函数
	wchar_t* p = new wchar_t[len];// 申请一段内存存放转换后的字符串
	mbstowcs(p, str.c_str(), len);// 转换
	std::wstring str1(p);
	delete[] p;// 释放申请的内存
	return str1;
}












int main()
{
    std::cout << "Hello World!\n";
}

