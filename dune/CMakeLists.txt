add_subdirectory(copasi)

if(TARGET headers)
  install(TARGETS headers
    EXPORT dune-copasi-targets
    COMPONENT Development
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  )
endif()
