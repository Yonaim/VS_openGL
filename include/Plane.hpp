#ifndef PLANE_HPP
#define PLANE_HPP

#include <Surface.hpp>
#include <glm/glm.hpp>

class Plane : public Surface
{
  private:
	glm::vec3 normal;

  public:
	Plane();
	Plane(glm::vec3 pos, glm::vec3 normal);
	virtual ~Plane();
	void         setNormal(glm::vec3 normal);
	virtual bool intersect(hitRecord *hit, Ray &ray, float tMin,
						   float tMax) const override;
};

#endif
