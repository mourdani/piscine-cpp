#ifndef  ARRAY_TPP
# define ARRAY_TPP

template <typename T>
class Array {
	private:
		T 			*_array;
		unsigned int _size;
	
	public:
		Array(): _array(NULL), _size(0) {}
		Array(unsigned int n): _array(new T[n]), _size(n) {}
		Array(Array const &cpy): _array(NULL) { *this = cpy; }
		~Array() { delete[] _array; }

		Array	&operator=(Array &rhs) {
			if (this == &rhs)
				return (*this);

			delete[] _array;
			_array = new T[rhs.size()];
			_size = rhs.size();
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
			return (*this);
		}

		class	ArrayUnreachable : public std::exception {
			public:
				const char	*what() const throw() {
					return ("The value to access is unreachable!");
				};
		};

		T	&operator[](unsigned int i) const {
			if (i < 0 || i >= _size)
				throw ArrayUnreachable();
			return(_array[i]);
		}

		unsigned int	size() const { return (this->_size); }
};

#endif

