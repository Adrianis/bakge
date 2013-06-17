
Engine classes should focused on controlling interactions between various
components like the renderers, scene manager and scene objects, event
handlers, and more.

Engines will house the main loop of the application, from which game world
updates are polled, and render calls dispatched.

A good example of Engine behavior is rendering the scene.


bind RENDERER
for each object in SCENE:
  bind object
  RENDERER->Draw(object)
  unbind object
unbind RENDERER


Depending on what type of Renderer the engine uses, Bind internally sets
up the OpenGL state to properly draw the Drawable object. When the
Drawable is bound, it does any OpenGL calls it needs to be drawn properly,
like setting the modelview matrix position, or changing the draw color.

