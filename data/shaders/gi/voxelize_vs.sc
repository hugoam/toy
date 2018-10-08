$input a_position, a_normal, a_tangent, a_color0, a_texcoord0
$output g_voxposition, g_normal, g_color, g_texcoord0

#include <gi/gi.sh>

//uniform vec3 u_eye_snap; // camera position snap

void main()
{
    g_color = a_color0;
    g_texcoord0 = a_texcoord0;

    //g_voxposition = (vec3(u_world * vec4(pos, 1.0)) - u_eye_snap) / u_voxelgi_extents;
    g_voxposition = mul(u_world, vec4(a_position, 1.0)).xyz / u_voxelgi_extents;
    g_normal = normalize(mul(u_world_normal, a_normal));
    
    gl_Position = vec4(0.0, 0.0, 0.0, 1.0);
}