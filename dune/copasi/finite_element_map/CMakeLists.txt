set(header_files  dynamic_power.hh
                  p0.hh
                  pk.hh
                  subdomain.hh
                  variadic.hh
                  virtual.hh)

install(FILES ${header_files}
      DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/dune/copasi/finite_element_map")

if(TARGET headers)
      target_precompile_headers(headers INTERFACE ${header_files})
endif()
