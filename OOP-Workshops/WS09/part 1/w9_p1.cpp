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
//	std::ofstream os("run_time.txt"); // file "run_time.txt" stores the output showing 
//				// the computation time; the rest of the program output is printed on 
//				// the standard ouptut 

	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	std::string fname_source = "data_int.dat", fname_target = "data_int_target.dat";
	// source data file "data_int.dat" contains data in binary format. First 4 bytes (int size) 
	//   in the file contain a value representing total number of data items stored in the file. From 
	// 	 5th byte to the end of the file, the date items are stored consecutively, where each data item 
	// 	 is stored in a memory space of 4 bytes (int size). 
	// in the target data file "data_int_targer.dat", the data read from "data_int.dat" will be saved 
	//   in binary mode, in the same format.
	if (argc > 1)
		fname_source = argv[1];
	if (argc > 2)
		fname_target = argv[2];

	// The following code block creates function object pd_obj. fname_source is supplied to the 
	//   constructor, which reads number-of-data-items and the data items from the file and 
	//   copies to instance variables. The constructor stores data items in a resource array, and 
	//   prints some data items on the standard output. Invocation of the function object pd_obj 
	//   calls the global functions computeAvgFactor and computeVarFactor to compute average and 
	//   variance of the data stored in the resource arrry, and saves the same data into the file 
	//   fname_target supplied as argument. avg and var are passed by reference, so they carry 
	//   the average and variance after the invocation of the function object.
	{
		printHead("Average of record-values using functor \"AvgOfNumbersFromFile\"");
		chrono::steady_clock::time_point t_before, t_after;
		t_before = chrono::steady_clock::now();
		double avg = 0.0, var = 0.0;;
		ProcessData pd_obj(fname_source); // creates function object 
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
