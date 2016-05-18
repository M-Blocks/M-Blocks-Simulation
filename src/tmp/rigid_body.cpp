class RigidBody {
  RigidBody(btTransform transform, float mass, btCollisionShape *shape) {
    btAssert((!shape || shape->getShapeType() != INVALID_SHAPE_PROXYTYPE));

    bool isDynamic = (mass != 0.f);
    btVector3 localInertia(0, 0, 0);
    if (isDynamic)
      shape->calculateLocalInertia(mass, localInertia);

    btDefaultMotionState *m_motionState = new btDefaultMotionState(transform);

    btRigidBody::btRigidBodyConstructionInfo cInfo(mass, m_motionState, shape, localInertia);
    m_body = new btRigidBody(cInfo);

    m_body->setUserIndex(-1);
  }
};
