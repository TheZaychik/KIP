#include "stdafx.h"
#include "pr5.h"
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

namespace pr5 {
	 double ClassFunc::func_for(int &a, int &sum, int &cr3, bool &if_sum) {
		 if_sum = false;
		if (a % 3 == 0)
			cr3 += 1;
		string a_str = to_string(a);
		if ( a_str.size() == 3) {
			sum = a % 10 + a / 100 + (a / 10) % 10;
			if_sum = true;
		}
		return 0;
	}
}
