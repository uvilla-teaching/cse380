#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE MyTests
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(my_test)
{
    BOOST_CHECK(1 == 1);
}
