#ifndef __SCENE_H__
#define __SCENE_H__

#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <light.h>
#include <material.h>
#include <sphere.h>
#include <mesh.h>
#include <bounding_volume.h>

namespace path_tracer {

class Scene {
private:
    glm::vec3 _backgroundColor;
    unsigned int _maxDepth;
    unsigned int _antialias;
    unsigned int _width;
    unsigned int _height;
    float _fov;
    glm::vec3 _up;
    glm::vec3 _lookAt;
    glm::vec3 _eye;
    std::vector<Light> _lights;
    std::vector<Sphere> _spheres;
    std::vector<Mesh> _meshes;
    std::vector<Triangle> _tris;
    BoundingVolume::Ptr _bvh;
    int _backwardsDepth;

    float raycast(glm::vec3 rayPos, glm::vec3 rayDir, glm::vec3& hitPos, glm::vec3& normal,
                  Material& mat);
    float raycast(glm::vec3 rayPos, glm::vec3 rayDir);
    glm::vec3 raytrace(glm::vec3 rayPos, glm::vec3 rayDir, int iter = 0, int numIndirect = 32);
    glm::vec3 randHemi(glm::vec3 normal);
    glm::vec3 randSphere();

public:
    Scene(const std::string& filename);
    void render(const std::string& filename);
    void generateBvh();
    void exportBvh(std::ostream& os);
    void importBvh(const std::string& filename);
    friend std::ostream& operator<<(std::ostream& os, Scene& s);
};

}  // namespace path_tracer

#endif  //  __SCENE_H__
