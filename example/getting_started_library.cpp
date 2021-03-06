// Copyright 2014 Renato Tegon Forti, Antony Polukhin.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org

#include <boost/dll.hpp>
#include <string>

//[getting_started_exports_c_function
// exporting pure 'C' method
extern "C" int BOOST_SYMBOL_EXPORT c_func_name(int);
//]

//[getting_started_exports_c_variable
// exporting POD 'C' variable in global namespace
extern "C" int BOOST_SYMBOL_EXPORT c_variable_name;
//]

//[getting_started_exports_cpp_function
// exporting 'C++' function
namespace my_namespace {

std::string cpp_function_name(const std::string& param);

BOOST_DLL_ALIAS(
    my_namespace::cpp_function_name, cpp_function_alias_name
)

} // namespace my_namespace

//]

//[getting_started_exports_cpp_variable
// exporting 'C++' variable
namespace my_namespace {
    std::string cpp_variable_name = "some value";
}

BOOST_DLL_ALIAS(
    my_namespace::cpp_variable_name, cpp_variable_alias_name
)

//]



int c_func_name(int i) { return ++i; }
int c_variable_name = 1;

namespace my_namespace {
    std::string cpp_function_name(const std::string& param) {
        return param + " Hello from lib!";
    }
}

