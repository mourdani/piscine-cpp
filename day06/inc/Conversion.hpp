#ifndef  CONVERSION_H
# define CONVERSION_H

#include <string>
#include <string>
#include <iomanip>
#include <limits.h>
#include <iostream>

class Conversion {

public:
	Conversion();
	Conversion(Conversion const &cpy);
	virtual ~Conversion();

	Conversion		&operator=(Conversion const &cpy);

	std::string	find_type(std::string literal) const;
	void	print(char c) const;
	void	print(int i) const;
	void	print(float f) const;
	void	print(double d) const;
};

#endif
