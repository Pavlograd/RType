cmake_minimum_required(VERSION 3.5)
set(WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#CLIENT

set(CLIENT r-type_client)
project(${CLIENT} LANGUAGES CXX)
set(CLIENT_SRC_PATH "client/src")
set(CLIENT_INCLUDE_PATH "client/include")
set(CLIENT_ENTITIES_INCLUDE_PATH "client/include/Entities")
set(CLIENT_SCENES_INCLUDE_PATH "client/include/Scenes")
set(GE_INCLUDE_PATH "gameEngine/include/GE")
set(GE_ENUMS_INCLUDE_PATH "gameEngine/include/enums")
set(GE_ENTITIES_INCLUDE_PATH "gameEngine/include/Entities")
set(GE_COMPONENTS_INCLUDE_PATH "gameEngine/include/Components")
set(UDP_INCLUDE_PATH "client/include/Network")

set(SRC_CLIENT client/src/main.cpp
		gameEngine/src/GE/Engine.cpp
		gameEngine/src/Entities/Button.cpp
		gameEngine/src/Entities/ParralaxSprite.cpp
		gameEngine/src/Entities/Player.cpp
		gameEngine/src/Entities/Enemy.cpp
		gameEngine/src/Components/Position.cpp
		gameEngine/src/Components/Sprite.cpp
		gameEngine/src/Components/Scale.cpp
		gameEngine/src/Components/Speed.cpp
		gameEngine/src/Components/Text.cpp
		gameEngine/src/Components/Rect.cpp
		client/src/Entities/Submarine.cpp
		client/src/Entities/Plane.cpp
		client/src/Entities/RaptorPlane.cpp
		client/src/Entities/Laser.cpp
		client/src/Scenes/Menu.cpp
		client/src/Scenes/Level.cpp
		client/src/Scenes/GameOver.cpp
		client/src/Scenes/Win.cpp
		client/src/eventsReturnFunctions.cpp
		client/src/Client.cpp
		client/src/Network/UDPclient.cpp
		client/src/Network/ClientDataCreator.cpp
	)

set(HPP_CLIENT
		client/include/Client.hpp
	)

add_executable(${CLIENT} ${SRC_CLIENT} ${HPP_CLIENT})

target_link_libraries(${CLIENT}
			CONAN_PKG::boost
			CONAN_PKG::sfml
			)

target_include_directories(${CLIENT} PUBLIC
			${CONAN_INCLUDE_DIRS_BOOST}
			${CONAN_INCLUDE_DIRS_SFML}
			${CLIENT_INCLUDE_PATH}
			${CLIENT_ENTITIES_INCLUDE_PATH}
			${CLIENT_SCENES_INCLUDE_PATH}
			${GE_INCLUDE_PATH}
			${GE_ENUMS_INCLUDE_PATH}
			${GE_ENTITIES_INCLUDE_PATH}
			${GE_COMPONENTS_INCLUDE_PATH}
			${UDP_INCLUDE_PATH}
			)

#SERVER

set(SERVER r-type_server)
project(${SERVER} LANGUAGES CXX)
set(SERVER_SRC_PATH "server/src")
set(SERVER_INCLUDE_PATH "server/include")

set(SRC_SERVER server/src/main.cpp
		server/src/Network/UDPserver.cpp
	)

set(HPP_SERVER 
	)

add_executable(${SERVER} ${SRC_SERVER} ${HPP_SERVER})
target_link_libraries(${SERVER}
			CONAN_PKG::boost
			)
target_include_directories(${SERVER} PUBLIC
			${CONAN_INCLUDE_DIRS_BOOST}
			${SERVER_INCLUDE_PATH}
			)

#CONAN

include(build/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

#GCC

if(CMAKE_COMPILER_IS_GNUCXX)
	message(STATUS "GCC detected, adding compile flags")
	list(APPEND CLIENT_COMPILE_OPTIONS "-std=c++11 -W -Wall -Wextra")
	list(APPEND SERVER_COMPILE_OPTIONS "-std=c++11 -W -Wall -Wextra")
	foreach(ITEM ${SERVER_COMPILE_OPTIONS})
		message("    ---> SERVER FLAGS  ${ITEM}")
		set_source_files_properties(${SRC_SERVER} PROPERTIES COMPILE_FLAGS ${ITEM})
	endforeach(ITEM in SERVER_COMPILE_OPTIONS)
	foreach(ITEM ${CLIENT_COMPILE_OPTIONS})
		message("    ---> CLIENT FLAGS  ${ITEM}")
		set_source_files_properties(${SRC_CLIENT} PROPERTIES COMPILE_FLAGS ${ITEM})
	endforeach(ITEM in CLIENT_COMPILE_OPTIONS)
endif(CMAKE_COMPILER_IS_GNUCXX)