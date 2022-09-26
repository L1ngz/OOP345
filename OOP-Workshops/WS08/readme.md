# Workshop 8: Smart Pointers

In this workshop, you combine two lists and use a smart pointer to ensure that memory is deallocated in the possible presence of an exception.



## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- create a program component of quadratic complexity
- use a smart pointer to move an object




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
/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g -o ws file1.cpp file2.cpp ...
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

The first portion of this workshop consists of modules:
- `w8` (supplied)
- `EmpProfile` (incomplete)
- `GeneratingList` (incomplete)
- `WritingRecord` (supplied header, incomplete implementation)

Your tasks for this part of the workshop are:
- Add a `rangeValidator()` function to the `EmpProfile` module
- Add an operator `+=` overload to the `GeneratingList` module using raw pointer syntax
- Add an implementation of [Luhn Algorithm](https://en.wikipedia.org/wiki/Luhn_algorithm) to the `GeneratingList` module to validate the [SIN](https://en.wikipedia.org/wiki/Social_insurance_number)
- Complete the `writeRaw()` function in the `WritingRecord` module using raw pointer syntax



### `EmpProfile` Module

The `EmpProfile` module holds employee, salary and correct wages information.
- The `Employee` structure holds employee SIN and employee name.  
- The `Salary` structure holds employee SIN and current salary.  
- The `EmployeeWage` structure holds employee name and employee salary. 

**Your Task:** Add a `rangeValidator()` function to the `EmploeeWage` type.  Your function reports an exception if the object’s salary is more than 99,999 or less than 0. Your function receives nothing and returns nothing.



### `GeneratingList` Module

The `GeneratingList` module defines a class that retrieves a list of records stored in a text file, holds the elements in an STL vector, provides access to them by index and displays them to an output stream.

**Your Task:**

- Add an operator `+=` overload to the `GeneratingList` template. Your function receives the address of an object to be stored in the `GeneratingList` container and moves the object into that container. Your overload returns nothing.
- Add an implementation of Luhn's Algorithm to check the validity of the SIN. Your function receives a reference of a `const std::string` type representing the SIN to check and return `true` if the SIN is valid, `false` otherwise.

### `WritingRecord` Module

**Your Task:** Implement the `writeRaw()` function.  This function creates a list of  active employees; an employee is considered active if both lists received as parameters contain an employee with the same SIN.  For each active employee found in both lists, **dynamically** create a new object of type `EmployeeWage`  and add it to the collection `activeEmp` only if it passes both validations below:

- validate the salary before adding it using the function you defined above
- validate the SIN using Luhn's algorithm you implemented above; if the SIN doesn't pass validation, generate an exception of type `std::string`






### `w8` Module (supplied)


The tester module has been supplied. **Do not modify the existing code!**

When doing the workshop, you are encouraged to write your own tests, focusing on a single implemented feature at the time, until you get all functionality in place.



### Sample Output


When the program is started with the command (the input files are provided):
```
ws NamesSIN.dat CorrectSalary.dat WrongSalary.dat
```
the output should look like the one from the `sample_output.txt` file.




### Test Your Code

To test the execution of your program, use the same data as shown in the output example above.

Upload your source code to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 345_w8_p1
```
and follow the instructions.

***This part represents a milestone in completing the workshop and is not marked!***










## Part 2 (100%)

The second part of this workshop upgrades your solution to use smart pointers.

Your tasks for this part of the workshop are:
- Add an operator `+=` overload to the `GeneratingList` module using smart pointer syntax
- Complete the `WriteSmart()` function in the `WritingRecord` module using smart pointer syntax

These two functions should do the same thing as the raw pointer version, but using **unique smart pointers** instead.



### `w8` Module (supplied)


The tester module has been supplied. **Do not modify the existing code!**

When doing the workshop, you are encouraged to write your own tests, focusing on a single implemented feature at the time, until you get all functionality in place.



### Sample Output


When the program is started with the command (the input files are provided):
```
ws NamesSIN.dat CorrectSalary.dat WrongSalary.dat
```
the output should look like the one from the `sample_output.txt` file.




### Reflection

Study your final solution, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop. **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:
- the advantage that smart pointer syntax provides. Use example from your code to support your explanation.
- the difference between raw and smart pointer syntax in your solution.

To avoid deductions, refer to code in your solution as examples to support your explanations.





### Submission

To test and demonstrate execution of your program use the same data as shown in the output example above.

Upload the source code and the reflection file to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 345_w8_p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Resubmissions will attract a penalty.
