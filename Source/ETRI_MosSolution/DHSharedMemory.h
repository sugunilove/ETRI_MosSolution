// DHSharedMemory.h

#pragma once

#include <windows.h>

#define	 DH_DATA_SIZE sizeof(double)

/*--------------------------------------------------------------*/
/* PPG와 HR(분당맥박수)를 전달하기 위한 공유메모리				*/
/*--------------------------------------------------------------*/

// PPG 및 HR 값의 저장 시간
HANDLE hmapHandle_Vital_Time = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, DH_DATA_SIZE, L"DH_VITAL_Time");
char* pmapFile_Vital_Time = (char*)MapViewOfFile(hmapHandle_Vital_Time, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, DH_DATA_SIZE);

// PPG
HANDLE hmapHandle_Vital_PPG = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, DH_DATA_SIZE, L"DH_VITAL_PPG");
char* pmapFile_Vital_PPG = (char*)MapViewOfFile(hmapHandle_Vital_PPG, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, DH_DATA_SIZE);

// HR
HANDLE hmapHandle_Vital_HR = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, DH_DATA_SIZE, L"DH_VITAL_HR");
char* pmapFile_Vital_HR = (char*)MapViewOfFile(hmapHandle_Vital_HR, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, DH_DATA_SIZE);
