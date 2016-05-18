class BulletWorld {
public:
  BulletWorld(btVector3 gravity) {
    m_broadphase = new btDbvtBroadphase();
    m_collisionConfiguration = new btDefaultCollisionConfiguration();
    m_dispatcher = new btCollisionDispatcher(collisionConfiguration);
    m_solver = new btSequentialImpulseConstraintSolver();
    m_dynamicsWorld = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase, m_solver,
						  m_collisionConfiguration);

    m_dynamicsWorld->setGravity(gravity);
  }

  ~BulletWorld() {
    delete m_dynamicsWorld;
    delete m_solver;
    delete m_dispatcher;
    delete m_collisionConfiguration;
    delete m_broadphase;
  }
  
private:
  btBroadphaseInterface *m_broadphase;
  btDefaultCollisionConfiguration *m_collisionConfiguration;
  btCollisionDispatcher *m_dispatcher;

  btSequentialImpulseConstraintSolver *m_solver;
  
  btDiscreteDynamicsWorld *m_dynamicsWorld;
};
