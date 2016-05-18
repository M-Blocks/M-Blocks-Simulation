#include "cube.h"

#include <GL/glew.h>

Cube::Cube(glm::mat4 transform, Shader *shader)
  : m_transform(transform) {}
