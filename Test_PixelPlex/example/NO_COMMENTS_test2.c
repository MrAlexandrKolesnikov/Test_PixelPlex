      

 
#include <iostream> 
#include <string>

     
void func1(int var)
{
	std::cout << ++var << "\n";   
}

     
void func2(int var)
{
	 std::cout << var++ << "\n";
}

 
int main()  
{
	  int var = 5;	 
	if(true)
    {
   		func1(var);		 
    }
    else
    {
    	func2(var);  
    }
    std::cout << "END"<< "\n"; 
}