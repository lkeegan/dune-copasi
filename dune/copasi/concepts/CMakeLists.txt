set(header_files   grid.hh pdelab.hh typetree.hh)

install(FILES ${header_files}
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/dune/copasi/concepts")

if(TARGET headers)
      target_precompile_headers(headers INTERFACE ${header_files})
endif()
