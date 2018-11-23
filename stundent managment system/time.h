#include <iostream>
#include <chrono>
#include<time.h>
#include<ctime>
#include<iomanip>
using namespace std;
void time()
{
		time_t const now_c = time(NULL);
		auto s = put_time(localtime(&now_c), "%F %T");
		cout << s << endl;
}
