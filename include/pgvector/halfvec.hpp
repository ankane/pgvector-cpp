/*!
 * pgvector-cpp v0.2.1
 * https://github.com/pgvector/pgvector-cpp
 * MIT License
 */

#pragma once

#include <ostream>
#include <vector>

namespace pgvector {
class HalfVector {
public:
    HalfVector() = default;

    HalfVector(const std::vector<float>& value) {
        value_ = value;
    }

    HalfVector(std::vector<float>&& value) {
        value_ = std::move(value);
    }

    HalfVector(const float* value, size_t n) {
        value_ = std::vector<float>{value, value + n};
    }

    size_t dimensions() const {
        return value_.size();
    }

    operator const std::vector<float>() const {
        return value_;
    }

    friend bool operator==(const HalfVector& lhs, const HalfVector& rhs) {
        return lhs.value_ == rhs.value_;
    }

    friend std::ostream& operator<<(std::ostream& os, const HalfVector& value) {
        os << "[";
        for (size_t i = 0; i < value.value_.size(); i++) {
            if (i > 0) {
                os << ",";
            }
            os << value.value_[i];
        }
        os << "]";
        return os;
    }

private:
    // TODO use std::float16_t for C++23
    std::vector<float> value_;
};
} // namespace pgvector
