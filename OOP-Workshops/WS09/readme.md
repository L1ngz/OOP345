# Workshop 9: Multi-Threading

You calculate average of the values stored in files, and use multi-threading to read data from the files and to compute averages of the read data. 


### Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to
- process partitioned data on two or more threads
- write a set of numbers to a file in binary mode
- read a set of numbers from a file in binary mode 
- bind a function to its arguments



## Submission Policy

The workshop is divided into two coding parts and one non-coding part:

- *Part 1*: worth 0% of the workshop's total mark, is optional and designed to assist you in completing the second part.
- *Part 2*: worth 100% of the workshop's total mark, is due on **Sunday at 23:59:59** of the week of your scheduled lab.  Submissions of *Part 2* that do not contain the *reflection* are not considered valid submissions and are ignored.
- *reflection*: non-coding part, to be submitted together with *Part 2*. The reflection does not have marks associated to it, but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

The workshop should contain ***only work done by you this term*** or provided by your professor.  Work done in another term (by you or somebody else), or work done by somebody else and not **clearly identified/cited** is considered plagiarism, in violation of the Academic Integrity Policy.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

- If the file contains only your work, or work provided to you by your professor, add the following message as a comment at the top of the file:

    > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

- If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which parts of the assignment are given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrong doing.



## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
/usr/local/gcc/10.2.0/bin/g++ -Wall -pthread -std=c++17 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: compiler will report all warnings
- `-std=c++17`: the code will be compiled using the C++17 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.




## Part 1 (0%)

The three source files provided for this workshop are
- `process_data.h`   -- fully implemented, **do not modify**
- `process_data.cpp` -- partially implemented, 
- `w9_p1.cpp`         -- already implemented, **do not modify**

A data file provided for this workshop is 
- `data_int.dat` -- First 4 bytes (`int` size) in the file contains the total number of data items. The remaining bytes in the file contain the data-item values, where each data-item is of 4 byte (`int` size). 

The `computeAvgFactor` and `computeVarVactor` functions, implemented in `process_data.cpp`, compute the average-factor and variance-factor from the data supplied in the first parameter. These functions are described as comments in the `process_data.cpp` file, read carefully and understand. These functions are fully implemented, do not change them.

The `ProcessData` constructor function, in the file `process_data.cpp` receives a filename as `std::string`, opens the file in binary mode and reads the total number of data items (first 4 bytes) followed by the data-item values. Detailed description is included as comment in `process_data.cpp`, read carefully and understand.

Your **first task** for part 1 of this workshop is to complete the definition of the constructor in class `ProcessData` to load the data from the binary file whose name is received as a parameter. See above info about the structure of the file. Do not modify existing code in this function, only add what is missing.

Your **second task** is to write definition of the `operator()` function in `process_data.cpp`. Prototype of this function is in the header file `process_data.h`. The first parameter of this function receives target-filename to which the data is to be written in binary format. The second parameter is a double reference variable for holding computed average value. The third parameter is double reference variable for holding computed variance value. 
- You compute the average value by calling `computeAvgFactor` with the following parameters: `data`, `total_items` as the size of the array, and again `total_items` as divisor. The fourth argument is going to be a variable in which the computed average value is to be stored. 
- You compute variance value by calling `computeVarFactor` with first, second and third arguments same as before, i.e., in the case of `computeAvgFactor`. The fourth argument is the average value computed by `computeAvgFactor` and fifth argument is the variable in which the computed variance is to be stored. 
- You open the target data file and write the data (`total_items`, and `data`) in the format of the input data file `data_int.dat`.
  

### `w9_p1` Module (supplied)

The tester module has been supplied. **Do not modify the existing code!**

When doing the workshop, you are encouraged to write your own tests, focusing on a single implemented feature at the time, until you get all functionality in place.



### Sample Output

When the program is started with the command (the input file is provided):
```
ws data_int.dat data_int_target.dat
```
the output should look like the one from the `sample_output.txt` file.


### Test Your Code

To test the execution of your program, use the same data as shown in the output example above.

Upload your source code to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 345_w9_p1
```
and follow the instructions.

***This part represents a milestone in completing the workshop and is not marked!***






## Part 2 (100%)

Your second task is to extend your work in part 1 to include multi-threaded logic for calculating average and variance of the data read from the file. 

The following enhancements have already been made in the `process_data` module for handling the multi-threaded computation:
- class definition for `ProcessData` has been enhanced by including member variables for handling the multi-threaded computation. 
- The constructor definition for `ProcessData` has been enhanced for handling the muli-threaded computation.  
- The destructor has been enhanced 
- Overloaded `bool` operator function has also been enhanced

Your job is to enhance the `operator()` function you created in part 1 for multi-threaded computation. Specifically, you include:
- Computation of average through multi-threading: to compute average, you call the function `computeAvgFactor` in different threads with different parts of the `data` items divided by partition-indices. 
  - bind `total_items` to the function `computeAvgFactor` as the divisor parameter. 
  - create threads by passing the following arguments to the function: address of the first element of each partition as `arr`, number of elements in the partition as `size`, and an element of the resource variable created to hold average-factors as `avg`. 
  - join the threads.
  - add all the average-factors into the variable to hold total average; this shold be one of the parameters of the `operator()` function. 
- Computation of variance through multi-threading: to compute variance, you call the function `computeVarFactor` in different threads with different parts of the `data` items divided by partition-indices. You follow a procedure similar to the one you followed while computing the average, with following exceptions:  
  - use the average value computed in the previous step as the 4th parameter. 
  - bind `total_items` and the computed average as `divisor` and `avg`, respectively, to the function ,before creating the threads. 
  - the last parameter should be an element of the resource variable created to store variance-factors.
  - you add the variance-factors computed by threads to compute the total variance.
- You open the target data file and write the data (`total_items`, and `data`) in the format of the input data file `data_int.dat`.
  

Your code must be free from memory leak.

When binding an argument to a function, consider the following reference:

  - [std::bind(...)](https://en.cppreference.com/w/cpp/utility/functional/bind)


### `w9_p2` Module (supplied)

The tester module has been supplied. **Do not modify the existing code!**


When doing the workshop, you are encouraged to write your own tests, focusing on a single implemented feature at the time, until you get all functionality in place.



### Sample Output


When the program is started with the command (the input file is provided):
```
ws data_int.dat data_int_target.dat
```
the output should look like the one from the `sample_output.txt` file.

### Computational complexity (experiments)
Insert the following statement inside the `for` loop in both the functions `computeAvgFactor` and `computeVarFactor`.
```
std::this_thread::sleep_for(std::chrono::nanoseconds(1));
```
Run your code with three different values of the argument in this statement, e.g., 
```
std::this_thread::sleep_for(std::chrono::nanoseconds(1)); // or
std::this_thread::sleep_for(std::chrono::nanoseconds(10)); // or
std::this_thread::sleep_for(std::chrono::nanoseconds(50));
```
In your reflect, include discussion on your observation of the computation times with three different values of the above parameters. 


### Reflection

Study your final solution, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop. **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:
- was there any benefit from using binary files in this workshop?
- why would be important to bind a function to its arguments, and how was it useful in this workshop
- the advantages of using multiple threads, and how did you accomplished multi-threading in this workshop

To avoid deductions, refer to code in your solution as examples to support your explanations.





### Submission

To test and demonstrate execution of your program use the same data as shown in the output example above.

Upload the source code and the reflection file to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.  Add switch to your compilation command `-pthread` to enable threading capabilities.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 345_w9_p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
