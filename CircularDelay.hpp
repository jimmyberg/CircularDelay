
#include <exception>

template<typename type, size_t size>
class CircularDelay{
public:
	CircularDelay();
	void push(type input);
	type get(unsigned int delay);
private:
	type data[size];
	unsigned int index;
};

template<typename type, size_t size>
CircularDelay<type, size>::CircularDelay():index(size-1){
	for (unsigned int i = 0; i < size; ++i){
		data[i] = 0;
	}
}

template<typename type, size_t size>
void CircularDelay<type, size>::push(type input){
	index = (index + 1) % size;
	data[index] = input;
}

template<typename type, size_t size>
type CircularDelay<type, size>::get(unsigned int delay){
	if(delay > size)
		throw(std::domain_error("Tried to get a value that is longer ago than the size of a CircularDelay."));
	return data[(index + size - delay) % size];
}
