add_llvm_library(LSLPPass MODULE
    LSLPVectorizer.cpp
    PLUGIN_TOOL
    opt
)

if(APPLE)
    set_target_properties(LSLPPass PROPERTIES
        LINK_FLAGS "-undefined dynamic_lookup"
    )
endif(APPLE)
