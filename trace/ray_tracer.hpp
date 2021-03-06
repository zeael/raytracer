#ifndef RAY_TRACER_HPP
#define RAY_TRACER_HPP

#include <math.h>
#include "def.hpp"
#include "scene/scene.hpp"

class RayTracer {
  private:
    Scene *scene;
    bool refract_(Vector const& normal, Vector &dir, double const& n1, double const& n2) const;
    bool reflect_(Vector const& normal, Vector &dir) const;
    double reflectance_(Vector const& normal, Vector const& dir, double const& n1, double const& n2) const;
    RGBColour transmission_(RGBColour const& colour, double const& coef, double const& dist) const;

  public:
    RayTracer(Scene *scene);
    ~RayTracer(void);

    bool RayTrace(Ray &ray, RGBColour &colour, double &t, double const& coef, int const& depth) const;
};

#endif
