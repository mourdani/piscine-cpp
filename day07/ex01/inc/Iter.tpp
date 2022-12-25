#ifndef ITER_TPP
# define ITER_TPP

template < typename T >
void	iter(T *array, unsigned int len, void (*f)(T const &)) {
	if (!array)
  		return;
	unsigned int i = 0;
	while (i < len)
		f(array[i++]);

	return;
}

template< typename T >
void print(const T &x) {
	std::cout << x << std::endl;
	return;
}

#endif

