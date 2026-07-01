#include <iostream>
#include "vector_engine/vector_store.hpp"

int main() {
    vector_engine::VectorStore store;
    store.add("cat", {1.0f, 0.0f, 0.0f});
    store.add("dog", {0.9f, 0.1f, 0.0f});
    store.add("car", {0.0f, 0.0f, 1.0f});

    auto results = store.search({1.0f, 0.0f, 0.0f}, 2);
    for (const auto& result : results) {
        std::cout << result.id << " " << result.score << "\n";
    }

    return 0;
}
