#ifdef AMBIENT_OCCLUSION
	#ifdef AO_ON_UV2
		lit.ao = sample_material_texture(s_ambient_occlusion, fragment.uv2).r;
	#else
		lit.ao = sample_material_texture(s_ambient_occlusion, fragment.uv).r;
	#endif
#endif
