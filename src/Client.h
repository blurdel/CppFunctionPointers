#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>


class Client {
public:
	Client() {}
	virtual ~Client() {}

	static void statfunc(int val) {
		std::cout << "static member callback " << val << std::endl;
	}

	void func(int val) const {
		std::cout << "instance member callback " << val << std::endl;
	}

};

#endif
