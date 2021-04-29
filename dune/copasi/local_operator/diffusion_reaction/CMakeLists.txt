set(header_files  base.hh
                  continuous_galerkin.hh
                  finite_volume.hh
                  multidomain.hh)

install(FILES ${header_files}
      DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/dune/copasi/local_operator/diffusion_reaction")

if(TARGET headers)
      target_precompile_headers(headers INTERFACE ${header_files})
endif()
