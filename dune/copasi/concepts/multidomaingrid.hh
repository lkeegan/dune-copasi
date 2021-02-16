#ifndef DUNE_COPASI_CONCEPTS_MULTIDOMAINGRID_HH
#define DUNE_COPASI_CONCEPTS_MULTIDOMAINGRID_HH

#include <dune/copasi/concepts/grid.hh>

#include <dune/geometry/type.hh>

/**
 * @ingroup Concepts
 */
namespace Dune::Copasi::Concept {

using namespace Dune::Concept;

/**
 * @brief   Concept for dune multidomain grids
 * @details Checks whether the type fits the most of the dune interface
 *          for grid and is extended to a multidomain grid.
 *          Some checks are missing, but they are not important
 *          for the concept.
 */
struct MultiDomainGrid : Refines<Dune::Concept::Fallback::Grid>
{
  template<class G>
  auto require(G&& g) -> decltype(
    requireType<typename G::HostGrid>(),
    requireType<typename G::SubDomainIndex>(),
    requireConvertible<typename G::SubDomainIndex>(g.maxSubDomainIndex()),
    requireConvertible<bool>(G::maxSubDomainIndexIsStatic()),
    requireType<typename G::SubDomainGrid>(),
    requireType<typename G::LeafSubDomainInterfaceIterator>(),
    requireType<typename G::LevelSubDomainInterfaceIterator>(),
    requireType<typename G::LeafAllSubDomainInterfacesIterator>(),
    requireType<typename G::LevelAllSubDomainInterfacesIterator>(),
    g.startSubDomainMarking(),
    g.preUpdateSubDomains(),
    g.updateSubDomains(),
    g.postUpdateSubDomains(),
    g.addToSubDomain(std::declval<typename G::SubDomainIndex>(),
                     std::declval<typename G::template Codim<0>::Entity>()),
    g.removeFromSubDomain(
      std::declval<typename G::SubDomainIndex>(),
      std::declval<typename G::template Codim<0>::Entity>()),
    g.assignToSubDomain(std::declval<typename G::SubDomainIndex>(),
                        std::declval<typename G::template Codim<0>::Entity>()),
    g.removeFromAllSubDomains(
      std::declval<typename G::template Codim<0>::Entity>()),
    requireConvertible<const typename G::SubDomainGrid&>(
      g.subDomain(std::declval<typename G::SubDomainIndex>())),
    requireConvertible<typename G::SubDomainIndex>(
      g.maxAssignedSubDomainIndex()),
    requireConvertible<bool>(g.supportLevelIndexSets()));
};

/**
 * @brief Check if a type is dune multidomain grid
 *
 * @tparam G        The type to check
 * @return true     if the type is a dune multidomain grid
 * @return false    if the type is not a dune multidomain grid
 */
template<class G>
static constexpr bool
isMultiDomainGrid()
{
  return models<Concept::MultiDomainGrid, G>();
}

/**
 * @brief   Concept for dune subdomain grids of multidomain grids
 * @details Checks whether the type fits the most of the dune interface
 *          for grid and is extended to a subdomain grid.
 *          Some checks are missing, but they are not important
 *          for the concept.
 */
struct SubDomainGrid : Refines<Dune::Concept::Fallback::Grid>
{
  template<class G>
  auto require(G&& g) -> decltype(
    requireType<typename G::HostGrid>(),
    requireType<typename G::MultiDomainGrid>(),
    requireConvertible<const typename G::MultiDomainGrid&>(g.multiDomainGrid()),
    requireConcept<Concept::MultiDomainGrid, typename G::MultiDomainGrid>(),
    requireConvertible<typename G::SubDomainIndex>(g.domain())
    // Some other things missing but this is enough
  );
};

/**
 * @brief Check if a type is dune subdomain grid
 *
 * @tparam G        The type to check
 * @return true     if the type is a dune subdomain grid
 * @return false    if the type is not a dune subdomain grid
 */
template<class G>
static constexpr bool
isSubDomainGrid()
{
  return models<Concept::SubDomainGrid, G>();
}

} // namespace Dune::Copasi::Concept

#endif // DUNE_COPASI_CONCEPTS_MULTIDOMAINGRID_HH
