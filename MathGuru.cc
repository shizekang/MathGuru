#include<iostream>
#include<exception>
#include<string>
#include<cmath>
#include<iomanip>

int main()
{
	try
	{
		constexpr auto alpha(sqrt(5)/5),pho((sqrt(5)+1)/2);
		std::ios::sync_with_stdio(false);
		std::cout<<std::fixed<<std::setprecision(0);
		for(;;)
		{
			std::cout<<
R"abc(1. 2^n, with input n. For example, when n is 3, the output is 8
2. n!, with input n. For example, 5! = 5*4*3*2*1
3. fab(n) with input n. fab(n) is the nth number in the Fibonacci sequence, with 1, 1, 2, 3, 5, 8, 13, 21, 34
)abc";
			std::size_t option;
			std::cin>>option;
			if(0<option&&option<4)
			{
				std::size_t n;
				std::cin>>n;
				if(20<n)
					std::cout<<"Please select a value below 20\n";
				else
				{
					switch(option)
					{
						case 1:
							std::cout<<(1<<n)<<'\n';
						break;
						case 2:
							std::cout<<tgamma(n+1)<<'\n';
						break;
						case 3:
							std::cout<<alpha*pow(pho,n)<<'\n';
						break;
					};
				}
			}
			std::cout<<"Try again? (yes/no)\n";
			std::string s;
			std::cin>>s;
			if(s!="yes")
				break;
		}
	}
	catch(const std::exception &ex)
	{
		std::cerr<<ex.what()<<'\n';
	}
}