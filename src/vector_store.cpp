#include "vector_engine/vector_store.hpp"
#include <algorithm>
#include <cmath>

namespace vector_engine {
namespace {

float cosine_similarity(const std::vector<float>& a, const std::vector<float>& b) {
    float dot = 0.0f, norm_a = 0.0f, norm_b = 0.0f;
    for (std::size_t i = 0; i < a.size(); ++i) {
        dot += a[i] * b[i];
        norm_a += a[i] * a[i];
        norm_b += b[i] * b[i];
    }
    if (norm_a == 0.0f || norm_b == 0.0f) {
        return 0.0f;
    }
    return dot / (std::sqrt(norm_a) * std::sqrt(norm_b));
}

} // namespace

void VectorStore::add(const std::string& id, const std::vector<float>& embedding) {
    ids_.push_back(id);
    embeddings_.push_back(embedding);
}

std::vector<SearchResult> VectorStore::search(const std::vector<float>& query, std::size_t top_k) const {
    std::vector<SearchResult> results;
    results.reserve(ids_.size());
    for (std::size_t i = 0; i < ids_.size(); ++i) {
        results.push_back({ids_[i], cosine_similarity(query, embeddings_[i])});
    }
    std::sort(results.begin(), results.end(), [](const SearchResult& a, const SearchResult& b) {
        return a.score > b.score;
    });
    if (results.size() > top_k) {
        results.resize(top_k);
    }
    return results;
}

} // namespace vector_engine
