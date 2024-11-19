#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h>



float f(const float& a)
{
    return expf(a);
}
// Check vector add result
void verify_result(std::vector<float> &a, std::vector<float> &b,
                   std::vector<float> &c) {
  for (int i = 0; i < a.size(); i++)
    assert(abs(c[i] - 50.0f*(f(a[i]) + f(b[i]))) < 0.001);
}


int main(int argc, char *argv[]) {
    // Array size of 2^16 (65536 elements)
    const int N{1 << std::stoi(argv[1])};
    srand (static_cast <unsigned> (time(0)));
    std::vector<float> a(N, 0.0f),  b(N, 0.0f), c(N, 0.0f);
    // Initialize random numbers in each array
    for (int i = 0; i < N; i++) {
        a[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        b[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    for (size_t i = 0; i < N; i++)
    {
        for(int j=0;j<50;++j)
            c[i] += (f(a[i]) + f(b[i]));
    }
    
    // Check result for errors
    verify_result(a, b, c);
    return 0;
}