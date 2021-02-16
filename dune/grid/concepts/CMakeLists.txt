install(FILES
    entity.hh
    entityiterator.hh
    geometry.hh
    grid.hh
    gridview.hh
    indexset.hh
    intersection.hh
    intersectioniterator.hh
  COMPONENT Development
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/dune/grid/concepts"
)
