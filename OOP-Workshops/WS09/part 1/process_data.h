// Workshop 9 - Multi-Threading, Thread Class
// process_data.h
// 2021/1/5 - Jeevan Pant

#ifndef SDDS_W9_PROCESSDATA_H
#define SDDS_W9_PROCESSDATA_H

#include<iostream>
#include<string>
#include<fstream>
#include<functional>

namespace sdds_ws9 {
	void computeAvgFactor(const int*, int, int, double&);
	void computeVarFactor(const int*, int, int, double, double&);
	class ProcessData {
		int total_items{};
		int* data{};
	public:
		ProcessData(std::string);
		ProcessData(const ProcessData&) = delete;
		ProcessData& operator=(const ProcessData&) = delete;
		~ProcessData();
		operator bool() const;
		int operator()(std::string, double&, double&);
	};
	
	
}



#endif 