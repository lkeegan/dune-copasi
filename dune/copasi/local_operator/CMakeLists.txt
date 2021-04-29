add_subdirectory(diffusion_reaction)

set(header_files  variadic.hh)

install(FILES ${header_files}
      DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/dune/copasi/local_operator")

if(TARGET headers)
      target_precompile_headers(headers INTERFACE ${header_files})
endif()
