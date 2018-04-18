/*TODO: Extract all portal related code and put it in separate 
glPortal/sources/renderer/GameRenderer 
which inherits from this class*/

#ifndef GAME_RENDERER_HPP
#define GAME_RENDERER_HPP

#include <memory>
#include <string>

#include <radix/core/math/Vector3f.hpp>
#include <radix/renderer/SubRenderer.hpp>

namespace radix {
  struct RenderContext;
  class Camera;
  class Renderer;
  class Entity;
}

namespace radix {

class World;

class GameRenderer : public SubRenderer {
public:
  GameRenderer(World& w, Renderer& ren, Camera* cam);

  void render();

  /**
   * Renders the scene with provided camera parameters
   */
  void renderScene(RenderContext &rc);

  void renderDebugView(RenderContext &renderContext);
  void renderViewFrames(RenderContext &rc);
  void renderViewFrameStencil(RenderContext &rc);

  /**
   * Renders all the entities in the scene regardless of shading
   */
  void renderEntities(RenderContext &rc);

  /**
   * @brief renderPortals render both portals color and blend
   * @param rc
   */
  void renderPortals(RenderContext &rc);

  /**
   * @brief renderPortal render portal color and blend
   * @param rc
   */
  void renderPortal(Entity* portal, RenderContext& rc,
                    Renderer& renderer);

  /**
   * Renders a single entity regardless of shading
   */
  void renderEntity(RenderContext &rc, const Entity &e);

  /**
   * Renders the player character using ambient shading
   */
  void renderPlayer(RenderContext &rc);

  /**
   * Set the camera in the portal so rendering from that portal is possible
   * @param cam         The camera from which we look at the portal
   * @param dest        The camera to move inside the portal and point in the right direction
   * @param portal      The portal in which to place the camera
   * @param otherPortal The counterpart of the portal
   */
  static void setCameraInPortal(const Camera &cam, Camera &dest,
                const Entity &portal, const Entity &otherPortal);

private:
  Camera* camera;
  //double* dtime;
  double time = 0.0;
};

} /* namespace glPortal */

#endif /* GAME_RENDERER_HPP */
