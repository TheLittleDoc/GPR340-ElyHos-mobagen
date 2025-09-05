#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2f CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
  Vector2f cohesionForce;

  // todo: add your code here to make a force towards the center of mass
  // hint: iterate over the neighborhood

  // find center of mass
  const Boid* thisBoid = boid;
  Vector2f cm;
  int count = 0;

  for (auto it : neighborhood) {
    if (it == boid)
      continue;
    cm += thisBoid->getPosition();
    count++;
    }
  if (count > 0) {
    Vector2f Fcm = cm / count;
    Vector2f pos = boid->getPosition();
    Fcm -= boid->getPosition();
    return Fcm;
  }
  return {0,0};


}