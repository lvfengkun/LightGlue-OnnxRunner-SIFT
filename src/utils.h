
#pragma once
#pragma warning(disable:4819) 
#pragma warning(disable:4267) 

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <Windows.h>


inline bool fileExists(const std::string& filename) {
	std::ifstream file(filename.c_str());
	return file.good();
}

inline wchar_t* multi_Byte_To_Wide_Char(std::string& pKey)
{
	// string ת char*
	const char* pCStrKey = pKey.c_str();
	// ��һ�ε��÷���ת������ַ������ȣ�����ȷ��Ϊwchar_t*���ٶ����ڴ�ռ�
	size_t pSize = MultiByteToWideChar(CP_OEMCP, 0, pCStrKey, strlen(pCStrKey) + 1, NULL, 0);
	wchar_t* pWCStrKey = new wchar_t[pSize];
	// �ڶ��ε��ý����ֽ��ַ���ת����˫�ֽ��ַ���
	MultiByteToWideChar(CP_OEMCP, 0, pCStrKey, strlen(pCStrKey) + 1, pWCStrKey, pSize);
	// ��Ҫ������ʹ����wchar_t*��delete[]�ͷ��ڴ�
	return pWCStrKey;
}

#endif // UTILS_H