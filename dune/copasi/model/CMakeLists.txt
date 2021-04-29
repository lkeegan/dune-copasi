set(header_files  base.hh
                  diffusion_reaction.cc
                  diffusion_reaction.hh
                  multidomain_diffusion_reaction.cc
                  multidomain_diffusion_reaction.hh
                  state.hh)

install(FILES ${header_files}
      DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/dune/copasi/model")

if(TARGET headers)
      target_precompile_headers(headers INTERFACE ${header_files})
endif()
