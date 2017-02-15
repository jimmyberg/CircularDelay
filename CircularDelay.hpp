
#include <stdexcept>
#include <cstdlib>
/**
 * @brief A class that functions as a smaple buffer.
 * @details You can use this to insert samples and use the get fuction to get a sample of the past.
 *
 * @tparam type Type of sample or even object that needs to be stored.
 * @tparam size Size of how big the history buffer is.
 */
template<typename type, size_t size>
class CircularDelay{
public:
	CircularDelay();
	void push(type input);
	type get(size_t delay);
private:
	type data[size];
	size_t index;
};

/**
 * @brief Constructor that initializeses that buffer and its set index.
 */
template<typename type, size_t size>
CircularDelay<type, size>::CircularDelay():index(size-1){
	for (size_t i = 0; i < size; ++i){
		data[i] = 0;
	}
}

/**
 * @brief With this funtion you can insert a new sample into the buffer.
 *
 * @param input Sample to push into.
 */
template<typename type, size_t size>
void CircularDelay<type, size>::push(type input){
	index = (index + 1) % size;
	data[index] = input;
}

/**
 * @brief With this funtion you can retrieve a smaple from the past.
 * @details Maxinum delay is the size of the CircularDelay - 1.
 *
 * @param delay How many samples you ago you want to get.
 * @return The sample of delay ago.
 */
template<typename type, size_t size>
type CircularDelay<type, size>::get(size_t delay){
	if(delay >= size)
		throw(std::domain_error("Tried to get a value that is longer ago than the size of a CircularDelay."));
	return data[(index + size - delay) % size];
}
