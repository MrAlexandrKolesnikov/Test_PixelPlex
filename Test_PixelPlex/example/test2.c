/**
 * @file   test2.cpp
 * @Author Kolesnikov Alexandr(mr.alexandr.kolesnikov@gmail.com)
 * @date   October, 2017
 * @brief  test file for Test_PixelPlex project
 **/

/* Required header files of standard libraries. ---------------------*/
#include <iostream> 
#include <string>

/**
 * @brief  some function
 * @param  var
 * @retval none
 */
void func1(int var)
{
	std::cout << ++var << "\n";  //print var
}

/**
 * @brief  some function
 * @param  var
 * @retval none
 */
void func2(int var)
{
	/* print var*/std::cout << var++ << "\n";
}

//main function
int main() /*sume func*/
{
	/*some parameter*/ int var = 5;	//equal to 5
	if(true)
    {
   		func1(var);		//call func1
    }
    else
    {
    	func2(var); /*call func2*/
    }
    std::cout << "END"<< "\n"; 
}