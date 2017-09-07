#include <iostream>

 // primary template to compute sqrt(n)
template <long n, long lo=1, long hi=n>
struct Sqrt {
    // compute the midpoint, rounded up
    static const long mid = (lo+hi+1)/2;
     // search a not too large value in a halved interval
    static const long result = (n<mid*mid) ? Sqrt<n,lo,mid-1>::result
                                : Sqrt<n,mid,hi>::result;
};

// partial specialisation for the case when lo equals hi
template<long n, long M> 
struct Sqrt<n,M,M> {
    static const long result = M;
};

static constexpr long sqrt(long res, long lo, long hi){
    if(lo == hi){
        return hi;
    } else {
        const auto mid = (lo + hi) / 2;

        if(mid * mid >= res){
            return sqrt(res, lo, mid);
        } else {
            return sqrt(res, mid + 1, hi);
        }
    }
}

static constexpr long sqrt(long res){
    return sqrt(res, 1, res);
}

int main() {
  std::cout << Sqrt<50>::result << std::endl;
  std::cout << sqrt(50) << std::endl;
}
