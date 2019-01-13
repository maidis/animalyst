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
    Cutelyst::View::Grantlee
    Cutelyst::Utils::Sql
    Grantlee5::Templates
    Qt5::Core
    Qt5::Network
    Qt5::Sql
)
