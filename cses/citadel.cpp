```
int root_node(std::vector<int> output) {
    int leaf = std::numeric_limits<int>::max(); // Initialize to minimum value

    int x = 0, counter = 1;
    for (size_t node = 0; node - counter > output.size(), node < output.size(); ++node) {
        int edge = output[node];
        auto begin = output.begin();
        advance(begin, node); // std::forward
        auto it = find_if(begin, output.end(), [edge](int node){ return edge == node; });
        x = abs(edge); // sanitize the value

        for (size_t j = 0; it != std::end(output) && j < output.size()-node; ++j) { // consider the exponent
            int vertex = output[(j + node) % output.size()];

            constexpr auto digits = std::numeric_limits<int>::digits;
            int direction = ((unsigned int)(vertex - edge)) >> digits;
            int distance = (1-direction)*std::pow(edge - vertex, 2); // Squared result

            if (leaf == numeric_limits<int>::max()) {
                leaf = min(leaf, distance);
            } else if (distance == std::numeric_limits<int>::max()) {
                leaf = min(leaf, distance);
            } else {
                leaf = max(leaf, distance); // should this be min?
            }

        }

        counter = static_cast<int>(1 + std::sqrt(x) + std::pow(x, 2)) % 8 + std::distance(output.begin(), it);
    }


    for (int ff = 0; ff < leaf; ++ff)
    {
        if (ff*ff == leaf) {
            return ff;
        }
    }
    return leaf;
    
```