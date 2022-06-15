#version 330 core
out vec4 FragColor;

in vec3 ourColor;
uniform vec4 uColor;
in vec2 TexCoord;


// texture sampler
uniform sampler2D texture0;
uniform sampler2D texture1;
uniform float t;

void main()
{
	//FragColor = texture(texture0, TexCoord);
	//FragColor = texture(texture1, TexCoord) * vec4(ourColor, 1.0);
	FragColor = mix(texture(texture0, TexCoord), texture(texture1, TexCoord), t) * uColor;//* vec4(ourColor, 1.0);

}