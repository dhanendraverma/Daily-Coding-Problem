/***************************************************************************************************************************************
This problem was asked by Microsoft.
Implement the singleton pattern with a twist. First, instead of storing one instance, store two instances. And in every even call of 
getInstance(), return the first instance and in every odd call of getInstance(), return the second instance.
***************************************************************************************************************************************/
#include <iostream>

class Singleton
{
    private:
        static Singleton *evenInstance, *oddInstance;
        Singleton();

    public:
        static Singleton* getInstance();
};

Singleton* Singleton::evenInstance = 0;
Singleton* Singleton::oddInstance = 0;
Singleton* Singleton::getInstance()
{
	static bool even=false;
	if(even){
		if (evenInstance == 0)
			evenInstance = new Singleton();
		even = !even;
		return evenInstance;
	}
	if(oddInstance == 0)
		oddInstance = new Singleton();
	even = !even;
	return oddInstance;
}

Singleton::Singleton()
{}

int main()
{
    int i = 10;
    while(i--)
    	std::cout<<Singleton::getInstance()<<std::endl;
}
