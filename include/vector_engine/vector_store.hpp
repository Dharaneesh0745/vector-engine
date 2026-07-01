#pragma once

#include <cstddef>
#include <string>
#include <vector>

namespace vector_engine {

struct SearchResult {
    std::string id;
    float score;
};

class VectorStore {
public:
    void add(const std::string& id, const std::vector<float>& embedding);
    std::vector<SearchResult> search(const std::vector<float>& query, std::size_t top_k) const;

private:
    std::vector<std::string> ids_;
    std::vector<std::vector<float>> embeddings_;
};

} // namespace vector_engine
