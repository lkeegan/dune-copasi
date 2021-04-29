add_subdirectory(dynamic_power)

set(header_files dynamic_power.hh local_basis_cache.hh p0.hh pk.hh)

install(FILES ${header_files}
      DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/dune/copasi/finite_element")

if(TARGET headers)
      target_precompile_headers(headers INTERFACE ${header_files})
endif()
