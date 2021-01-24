#ifndef JAB_UTILS_HPP
#define JAB_UTILS_HPP 

#include <iterator>

namespace jab
{

template<std::random_access_iterator T>
using val_type = typename T::value_type;

};
#endif // JAB_UTILS_HPP
