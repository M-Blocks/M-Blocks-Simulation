#ifndef CUBE_H
#define CUBE_H

#include "shader.h"

#include <array>

#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Cube {
public:
  Cube(glm::mat4 transform, Shader *shader);

private:
  glm::mat4 m_transform;
};

#endif
