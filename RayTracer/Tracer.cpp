#include "Tracer.h"
#include"Scene.h"
#include<iostream>

void Tracer::Trace(const ColorBuffer& colorBuffer, Scene* scene, Camera* camera)
{
	float aspectRatio = colorBuffer.width / (float)colorBuffer.height;
	float invSample = 1.0f / samples;

	for (int y = 0; y < colorBuffer.height; y++)
	{
		for (int x = 0; x < colorBuffer.width; x++)
		{
			glm::vec3 color{ 0, 0, 0 };

			for (int sample = 0; sample < samples; sample++)
			{
				glm::vec2 viewport = camera->ScreenToViewport({ x + random01(), y + random01() });
				viewport.y = 1 - (viewport.y);
				ray_t ray = camera->ViewportToRay(viewport);

				raycastHit_t hit;
				color += scene->Trace(ray, 0.001f, FLT_MAX, hit, depth);
			}

			//color /= (float)samples;

			color.r = sqrt(color.r * invSample);
			color.g = sqrt(color.g * invSample);
			color.b = sqrt(color.b * invSample);

			colorBuffer.SetColor(x, y, Vec3ToColor(color));
		}
		std::cout << y << std::endl;
	}
}
