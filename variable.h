#pragma once

#include <set>
#include <string>
#include <vector>
#include "any.h"

namespace ts {

class Variable {
 public:
  template <typename T>
  const T &Get() const {
    return blob_.get<T>();
  }

  template <typename T>
  T *GetMutable() {
    if (!blob_.valid()) {
      blob_.set<T>();
    }
    return blob_.get_mutable<T>();
  }

  template <typename T>
  bool IsType() const {
    return blob_.is_type<T>();
  }

 private:
  Any blob_;
};

}  // namespace ts
