#pragma once
#include"Material.h"

class Metal : public Material
{
public:
	Metal(const glm::vec3& albedo, float fuzz) : albedo{ albedo }, fuzz{ fuzz } {}
	virtual bool Scatter(const ray_t& ray, const raycastHit_t& hit, glm::vec3& attenuation, ray_t& scattered) const override;

protected:
	glm::vec3 albedo{ 0, 0, 0 };
	float fuzz = 0;
};
