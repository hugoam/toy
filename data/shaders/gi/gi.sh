#ifndef MUD_SHADER_GI
#define MUD_SHADER_GI

 #include <common.sh>

uniform mat4 u_world;
uniform mat3 u_world_normal;

uniform vec4 u_voxelgi_params_0;
#define u_voxelgi_extents u_voxelgi_params_0.xyz

uniform vec4 u_voxelgi_params_1;
#define u_voxelgi_resolution u_voxelgi_params_1.xyz

#define VOXELGI_RESOLUTION_Z 128

#endif
