set(header_files local_basis.hh local_coefficients.hh local_interpolation.hh)

install(FILES ${header_files}
      DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/dune/copasi/finite_element/dynamic_power")

if(TARGET headers)
      target_precompile_headers(headers INTERFACE ${header_files})
endif()
