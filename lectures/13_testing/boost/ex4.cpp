#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Runlimit

#include <unistd.h>
#include <boost/test/unit_test.hpp>
namespace btest = boost::unit_test;

BOOST_AUTO_TEST_CASE(test1, * btest::timeout(1))
{
  usleep(1500000);
  BOOST_TEST(2 == 2);
}
