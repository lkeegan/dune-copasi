#ifndef DUNE_COPASI_CONCEPTS_GRID_HH
#define DUNE_COPASI_CONCEPTS_GRID_HH

#include <dune/grid/concepts/grid.hh>

#include <dune/geometry/type.hh>

/**
 * @ingroup Concepts
 */
namespace Dune::Copasi::Concept {

using namespace Dune::Concept;

/**
* @brief Check if a type is dune subdomain grid
*
* @tparam G        The type to check
* @return true     if the type is a dune subdomain grid
* @return false    if the type is not a dune subdomain grid
*/
template<class G>
static constexpr bool
isGrid()
{
#if DUNE_HAVE_CXX_CONCEPTS
  return Concept::Grid<G>;
#else
  return models<Concept::Fallback::Grid, G>();
#endif
}

} // namespace Dune::Copasi::Concept

#endif // DUNE_COPASI_CONCEPTS_GRID_HH
