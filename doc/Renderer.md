
Renderers are classes which are used to draw objects type Drawable. They are bindable objects, due to the stateful of the OpenGL calls they make when used.

Ideally, the use renderers from within the engine class should be:

```
MyRenderer->Bind();
for(int i=0;i<SceneObjects.length();++i) {
  SceneObjects[i]->Bind();
  MyRenderer->Draw(&SceneObjects[i]);
  SceneObjects[i]->Unbind();
}
MyRenderer->Unbind();
```
  
The engine class will have to manage drawing so that Bind and Unbind calls are minimized, and all objects in the scene or GUI are drawn with the proper renderer.

Internally, Renderers will bind shaders, set up the viewport, perspective transform, color, properties and attributes (GL_DEPTH_TEST, GL_LIGHTING, etc) and more.

