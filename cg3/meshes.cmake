#
# This file is part of cg3lib: https://github.com/cg3hci/cg3lib
# This Source Code Form is subject to the terms of the GNU GPL 3.0
#
# @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
# @author Stefano Nuvoli (stefano.nuvoli@gmail.com)
#

list(APPEND CG3_MODULE_DEFINITIONS CG3_DCEL_DEFINED)

set(CG3_MESHES_HEADERS
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel.h 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel_data.h 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel_face.h 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel_face_iterators.h 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel_half_edge.h 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel_iterators.h 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel_struct.h
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel_struct.inl
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel_vertex.h 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel_vertex_iterators.h 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_algorithms.h  
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_bounding_boxes.h
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_bounding_boxes.inl
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_edge_flip.h
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_flooding.inl
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_to_vectors.h 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_flooding.h 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_coloring.h 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_connected_components.h
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_connected_components.inl
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_robustness.h 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel_builder.h 
	${CMAKE_CURRENT_LIST_DIR}/meshes/mesh.h)

set(CG3_MESHES_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_coloring.cpp  
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_edge_flip.cpp 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_robustness.cpp 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/algorithms/dcel_to_vectors.cpp 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel_builder.cpp 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel_face.cpp 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel_half_edge.cpp 
	${CMAKE_CURRENT_LIST_DIR}/meshes/dcel/dcel_vertex.cpp)

if(TARGET Eigen)
	list(APPEND CG3_MODULE_DEFINITIONS CG3_EIGENMESH_DEFINED)

	list(APPEND CG3_MESHES_HEADERS
		${CMAKE_CURRENT_LIST_DIR}/meshes/eigenmesh/simpleeigenmesh.h 
		${CMAKE_CURRENT_LIST_DIR}/meshes/eigenmesh/eigenmesh.h 
		${CMAKE_CURRENT_LIST_DIR}/meshes/eigenmesh/algorithms/eigenmesh_algorithms.h)
	
	list(APPEND CG3_MESHES_SOURCES
		${CMAKE_CURRENT_LIST_DIR}/meshes/eigenmesh/simpleeigenmesh.cpp 
		${CMAKE_CURRENT_LIST_DIR}/meshes/eigenmesh/eigenmesh.cpp 
		${CMAKE_CURRENT_LIST_DIR}/meshes/eigenmesh/algorithms/eigenmesh_algorithms.cpp)
endif()

if (CG3_STATIC)
	add_library(cg3-meshes SHARED ${CG3_MESHES_HEADERS} ${CG3_MESHES_SOURCES})
else()
	add_library(cg3-meshes INTERFACE)
endif()

target_include_directories(cg3-meshes ${CG3_TARGET_MOD} ${CG3_INCLUDE_DIR})

target_link_libraries(cg3-meshes
	${CG3_TARGET_MOD}
		cg3-core)
	
if (TARGET Qt5::Gui)
	target_link_libraries(cg3-meshes ${CG3_TARGET_MOD} Qt5::Gui)
endif()

list(APPEND CG3_LINK_LIBRARIES cg3-meshes)