// Workshop 9 - Multi-threading, Thread class 
// w9_p2.cpp 
// 2022/1/5 - Jeevan Pant

#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
#include "process_data.h"
#include "process_data.h" // intentional

using namespace std;
using namespace sdds_ws9;

void printHead(std::string str); // prints header text, embeds str into the text
void printFoot(); // prints footer text
void compareFiles(const std::string& fileName1, const std::string& fileName2);

int main(int argc, char** argv)
{
//	std::ofstream os("run_time.txt"); // file "run_time.txt" stores the time taken to create 
//			// and invoke function object for the computation of average and variance using 
//			// one, two, and four threads. 

	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	std::string fname_source = "data_int.dat", fname_target = "data_int_target.dat";
	/*
	source data file "data_int.dat" contains data in binary format. First 4 bytes (int size) 
	   in the file contain a value representing total number of data items stored in the file. From 
	 	 5th byte to the end of the file, the date items are stored consecutively, where each data item 
	 	 is stored in a memory space of 4 bytes (int size). 
	 in the target data file "data_int_targer.dat", your code will save the data, read from 
	   "data_int.dat", in binary format. 
	*/
	 if (argc > 1)
		fname_source = argv[1];
	if (argc > 2)
		fname_target = argv[2];

	/* 
	The following code block creates function object pd_obj for the computation of average and
	   variance through a single thread. During the function object creation, number of data 
	   items and the values of the data items are read and stored in instance variables. In 
	   addition to the filename fname_source, the constructor also receives the number of threads
	   as the second argument, which is also stored in the instance variable. Some of the 
	   read data items are also printed on standard output. It also initializes additional resource 
	   variables related to the implementation of multi threading. 
	 Invocation of the function object pd_obj divides the data into a number of parts, where 
	   the number of parts is equal to the number of threads. Multi-threading is used to compute 
	   average-factor for each part of he data by calling the function computeAvgFactor. The 
	   obtained average-factors are added to compute total average. Computed total average is 
	   used as argument for computeVarFactor, which is used compute variance-factors for each part of the 
	   data; multi-threading is for this as well. The computed variance-factors are added to 
	   obtain total variance.
	 Arguments avg and var are passed by reference, so they carry the average and variance computed 
	   after the invocation of function object. 
	 Invocation of the function object pd_obj also saves the data into the file fname_target 
	   supplied as argument. 
	 Read the comments included in the implementation file process_data.cpp. 
	 */
	{
		printHead("Average and variance of record-values using 1 thread.");
		chrono::steady_clock::time_point t_before, t_after;

		t_before = chrono::steady_clock::now();
		double avg = 0.0, var = 0.0;
		ProcessData pd_obj(fname_source, 1); // creates function object 
		if (pd_obj) {
			try {
				pd_obj(fname_target, avg, var); // invokes function object for "data_int.dat"
				compareFiles(fname_source, fname_target);
			}
			catch (std::string* msg) {
				cout << msg << std::endl;
			}
		}
		t_after = chrono::steady_clock::now();
		cout << "Data statistics (\"" << fname_source << "\"):" << std::endl;
		cout.setf(ios::fixed);
		cout << " Average:  " << setw(16) << avg << endl;
		cout << " Variance: " << setw(16) << var << endl;
		cout.unsetf(ios::fixed);
		cout << "Time required to compute average and variance: "
			<< (chrono::duration_cast<chrono::milliseconds>(t_after - t_before)).count() 
			<< " milliseconds." << endl;
		printFoot();
		cout << endl << endl;
	}
	// The following code block creates function object pd_obj for the computation of average and 
	//   variance through 2 threads. The function object is invoked to compute average and 
	//   variance.
	{
		printHead("Average and variance of record-values using 2 threads");
		chrono::steady_clock::time_point t_before, t_after;

		t_before = chrono::steady_clock::now();
		double avg = 0.0, var = 0.0;;
		ProcessData pd_obj(fname_source, 2); // creates function object 
		pd_obj(fname_target, avg, var); // invokes function object for "data_int.dat"
		t_after = chrono::steady_clock::now();

		cout << "Data statistics (\"" << fname_source << "\"):" << std::endl;
		cout.setf(ios::fixed);
		cout << " Average:  " << setw(16) << avg << endl;
		cout << " Variance: " << setw(16) << var << endl;
		cout.unsetf(ios::fixed);
		cout << "Time required to compute average and variance: "
			<< (chrono::duration_cast<chrono::milliseconds>(t_after - t_before)).count() 
			<< " milliseconds." << endl;
		printFoot();
		cout << endl << endl;
	}

	// The following code block creates function object pd_obj for the computation of average and 
	//   variance through 4 threads. The function object is invoked to compute average and 
	//   variance.
	{
		printHead("Average and variance of record-values using 4 threads");
		chrono::steady_clock::time_point t_before, t_after;

		t_before = chrono::steady_clock::now();
		double avg = 0.0, var = 0.0;;
		ProcessData pd_obj(fname_source, 4); // creates function object 
		pd_obj(fname_target, avg, var); // invokes function object for "data_int.dat"
		t_after = chrono::steady_clock::now();

		cout << "Data statistics (\"" << fname_source << "\"):" << std::endl;
		cout.setf(ios::fixed);
		cout << " Average:  " << setw(16) << avg << endl;
		cout << " Variance: " << setw(16) << var << endl;
		cout.unsetf(ios::fixed);
		cout << "Time required to compute average and variance: "
			<< (chrono::duration_cast<chrono::milliseconds>(t_after - t_before)).count() 
			<< " milliseconds." << endl;
		printFoot();
	}
}

void printHead(std::string str) {
	cout << setw(90) << setfill('=') << '=' << endl << setfill(' ');
	cout << setw(45 - str.length() / 2) << ' ' << str << endl;
	cout << setw(90) << setfill('-') << '-' << endl << setfill(' ');
}
void printFoot() {
	cout << setw(90) << setfill('=') << '=' << endl;
}

void compareFiles(const std::string& fileName1, const std::string& fileName2)
{
	ifstream file1(fileName1), file2(fileName2);
	int cnt = 0;
	while (file1 && file2)
	{
		if (file1.get() != file2.get())
			throw std::string("The output file doesn't have the correct binary content as the input file.\n"
			                  "  Byte " + std::to_string(cnt) + " is wrong.\n"
			                  "  Check the 'operator()' implementation to fix.\n");
		++cnt;
	}
	cout << "Read [" << cnt << "] bytes from the files; the content is the same.\n";
}
