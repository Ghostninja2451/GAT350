#pragma once
#include "Ray.h"
#include"Material.h"

class Geometry
{
public:
    Geometry() = default;
    virtual ~Geometry() = default;
    std::shared_ptr<Material> material;

    Geometry(std::shared_ptr<Material> material) : material{ material } {}
    virtual bool Hit(const ray_t& r, float tMin, float tMax, raycastHit_t& hit) = 0;
};