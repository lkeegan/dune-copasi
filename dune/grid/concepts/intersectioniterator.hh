#ifndef DUNE_GRID_CONCEPTS_INTERSECTION_ITERATOR_HH
#define DUNE_GRID_CONCEPTS_INTERSECTION_ITERATOR_HH

#include <dune/grid/concepts/intersection.hh>

#include <dune/common/concept.hh>

#if DUNE_HAVE_CXX_CONCEPTS
#include <dune/common/std/concepts.hh>
#endif

namespace Dune {
  namespace Concept {

/*!@defgroup ConceptIntersectionIterator Intersection iterator
 * @{
 *  @ingroup Concepts
 *  @par Description
 *    This concept models how an intersection iterator object should look like at compilation time.
 *    Dune::IntersectionIterator is a template for this model.
 *  @snippet this intersection-iterator-concept
 *  @par Uses
 *    - @ref ConceptIntersection
 * @}
 */

#if DUNE_HAVE_CXX_CONCEPTS

    //! [intersection-iterator-concept]
    template<class I>
    concept IntersectionIterator = requires(I i)
    {
      requires Intersection<typename I::Intersection>;
      i++; //! FIXME set type requirement
      ++i; //! FIXME set type requirement
      *i; //! FIXME set type requirement
      i.operator ->(); //! FIXME set type requirement
      { i==i } -> Std::convertible_to<bool>;
      { i!=i } -> Std::convertible_to<bool>;
      requires Std::default_initializable<I>;
    };
    //! [intersection-iterator-concept]

#endif
    namespace Fallback {
      struct IntersectionIterator
      {
        template<class I>
        auto require(I&& i) -> decltype(
          requireConcept<Intersection, typename I::Intersection>(),
          i++, //! FIXME set type requirement
          ++i, //! FIXME set type requirement
          *i, //! FIXME set type requirement
          i.operator ->(), //! FIXME set type requirement
          requireConvertible<bool>(i==i),
          requireConvertible<bool>(i!=i),
          I{}, // default constructible
          I{i} // copy constructible
        );
      };
    } // nampespace Fallback
  } // nampespace Concept

  //! @expectConcept{ConceptIntersectionIterator,I}
  template <class I>
  constexpr bool expectIntersectionIterator()
  {
#if DUNE_HAVE_CXX_CONCEPTS
    static_assert(Dune::Concept::IntersectionIterator<I>);
#else
    static_assert(models<Concept::Fallback::IntersectionIterator, I>());
#endif
    return true;
  }

} // end namespace Dune

#endif
