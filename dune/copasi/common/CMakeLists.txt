set(header_files  bit_flags.hh
                  data_context.hh
                  enum.hh
                  factory.hh
                  filesystem.hh
                  muparser_data_handler.hh
                  pdelab_expression_adapter.hh
                  stepper.hh
                  tiff_file.hh
                  tiff_grayscale.hh)

install(FILES ${header_files}
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/dune/copasi/common")

if(TARGET headers)
      target_precompile_headers(headers INTERFACE ${header_files})
endif()
