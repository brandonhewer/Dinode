#ifndef __COSPAN_HPP_
#define __COSPAN_HPP_

#include "polymorphic_types/type_constructor.hpp"

#include <cstddef>
#include <memory>
#include <string>
#include <variant>
#include <vector>

namespace Project {
namespace Naturality {

struct EmptyType {};

struct CospanMorphism {
  using PairType = std::pair<std::size_t, std::size_t>;
  using Type = std::variant<std::size_t, PairType, EmptyType, CospanMorphism>;
  using MappedType = Types::TypeWithVariance<Type>;
  std::vector<MappedType> map;
};

struct CospanStructure {
  std::vector<CospanMorphism> domains;
  std::vector<std::pair<std::size_t, std::size_t>> shared_counts;
  std::size_t start_identifier;
  std::size_t total_number_of_identifiers;
};

CospanStructure create_default_cospan(Types::TypeConstructor const &,
                                      Types::TypeConstructor const &);

} // namespace Naturality
} // namespace Project

#endif