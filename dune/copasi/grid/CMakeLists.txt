set(header_files  has_single_geometry_type.hh
                  mark_stripes.hh
                  multidomain_entity_transformation.hh
                  multidomain_gmsh_reader.hh)

install(FILES ${header_files}
      DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/dune/copasi/grid")

if(TARGET headers)
      target_precompile_headers(headers INTERFACE ${header_files})
endif()
