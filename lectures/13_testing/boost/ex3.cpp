#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FP Check
#include <boost/test/unit_test.hpp>
namespace btest = boost::unit_test;

BOOST_AUTO_TEST_CASE(test1, * btest::tolerance(0.00001))
{
  double x = 10.0000000;
  double y = 10.0000001;
  double z = 10.001;
  BOOST_TEST(x == y); // irrelevant difference
  BOOST_TEST(x == z); // relevant difference
}
