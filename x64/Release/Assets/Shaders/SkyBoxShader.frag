#version 410 core


layout(location = 0) in vec2 outTexcoord;
layout(location = 1) in vec3 outNormal;
layout(location = 2) in vec3 outDirToCamera;

layout(location = 0) out vec4 color;

uniform sampler2D tex;

void main()
{
	vec4 texColor = texture(tex, outTexcoord);
	color = vec4(texColor.rgb,1.0);
}
