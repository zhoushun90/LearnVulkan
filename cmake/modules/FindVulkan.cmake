# - Try to find Vulkan
# Once done, this will define
#
# Vulkan_FOUND - system has Vulkan
# Vulkan_INCLUDE_DIR - the Vulkan include directories
# Vulkan_LIBRARIES - link these to use Vulkan

SET(VulKan_DIR "$ENV{VK_SDK_PATH}")
IF(VulKan_DIR)
	MESSAGE(STATUS "Found Vulkan: ${VulKan_DIR}")
ENDIF(VulKan_DIR)

FIND_PATH( Vulkan_INCLUDE_DIR vulkan/vulkan.h
	/usr/include
	/usr/local/include
	/opt/local/include
	${CMAKE_SOURCE_DIR}/includes
	${VulKan_DIR}/Include
)
FIND_LIBRARY( Vulkan_LIBRARY vulkan-1
	/usr/lib64
	/usr/lib
	/usr/local/lib
	/opt/local/lib
	${CMAKE_SOURCE_DIR}/lib
	${VulKan_DIR}/Lib
)
IF(Vulkan_INCLUDE_DIR AND Vulkan_LIBRARY)
	SET( Vulkan_FOUND TRUE )
	SET( Vulkan_LIBRARIES ${Vulkan_LIBRARY} )
ENDIF(Vulkan_INCLUDE_DIR AND Vulkan_LIBRARY)
IF(Vulkan_FOUND)
	IF(NOT Vulkan_FIND_QUIETLY)
	MESSAGE(STATUS "Found Vulkan Library: ${Vulkan_LIBRARY}")
	ENDIF(NOT Vulkan_FIND_QUIETLY)
ELSE(Vulkan_FOUND)
	IF(Vulkan_FIND_REQUIRED)
	MESSAGE(FATAL_ERROR "Could not find libVulkan")
	ENDIF(Vulkan_FIND_REQUIRED)
ENDIF(Vulkan_FOUND)
