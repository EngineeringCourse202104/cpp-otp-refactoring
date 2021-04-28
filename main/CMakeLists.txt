set(Main_SRCS main.cpp AuthenticationService.cpp ProfileDao.cpp RsaTokenDao.cpp Context.cpp BudgetRepo.h)

include_directories(.)

add_library(core ${Main_SRCS})
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} core)
