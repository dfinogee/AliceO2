SET(MODULE_NAME TOFBase)

O2_SETUP(NAME ${MODULE_NAME})

set(SRCS
  src/Geo.cxx
)

set(HEADERS
  include/${MODULE_NAME}/Geo.h
)

SET(LINKDEF src/TOFBaseLinkDef.h)
SET(LIBRARY_NAME ${MODULE_NAME})
SET(BUCKET_NAME emcal_base_bucket)

O2_GENERATE_LIBRARY()
