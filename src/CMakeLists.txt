file(GLOB_RECURSE Animals_SRCS *.cpp *.h)

set(Animals_SRCS
    ${Animals_SRCS}
    ${TEMPLATES_SRC}
)

# Create the application
add_library(Animals SHARED ${Animals_SRCS})

# Link to Cutelyst
target_link_libraries(Animals
    Cutelyst::Core
    Cutelyst::View::Cutelee
    Cutelyst::Utils::Sql
    Cutelee::Templates
    Qt6::Core
    Qt6::Network
    Qt6::Sql
)
