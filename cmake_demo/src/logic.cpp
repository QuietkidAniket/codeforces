#include "logic.hpp"
#include <numeric>

namespace BackendSystem {
    // Definition
    long long process_data(const std::vector<long long>& vec) {
        long long res = 0;
        for(const auto& val : vec) {
            if (val % 2 == 0) {
                long long tmp = val * val;
                res += tmp;
            }
        }
        return res;
    }
}
