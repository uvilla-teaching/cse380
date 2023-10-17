#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE My tests
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(simple_test) {
  BOOST_CHECK_EQUAL(2+2, 4);
}
