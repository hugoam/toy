# toy engine manual

- [quickstart](#quickstart)
  - [simple game module](#simple-game-module)
  - [minimal game code](#minimal-game-code)
  - [rendering a cube](#rendering-a-cube)
  - [defining an entity type](#defining-an-entity-type)
  - [drawing entities](#drawing-entities)

- [reflection](#reflection)
  - [annotating code](#annotating-code)
  - [precompiling](#precompiling)

- [scripting](#scripting)

- [context](#context)
- [math](#math)
  - [vector math](#vector-math)
  
- [geometry](#geometry)
  - [shapes](#shapes)
    - [simple shapes](#simple-shapes)
    - [complex shapes](#complex-shapes)
    - [shapes intersection](#shapes-intersection)

- [graphics](#graphics)
  - [resources](#resources)
    - [loading resources](#loading-resources)
    - [asynchronous loading](#asynchronous-loading)
  - [scene and graph](#scene-and-graph)
    - [scene](#scene)
    - [declarative graph](#declarative-graph)
  - [viewport and camera](#scene-viewport-and-camera)
    - [camera](#camera)
    - [viewport](#viewport)
  - [meshes and models](#meshes-and-models)
    - [meshes](#meshes)
    - [creating meshes](#creating-meshes)
    - [cached meshes](#cached-meshes)
  - [textures](#textures)
  - [shaders, programs, and materials](#shaders-programs-and-materials)
    - [programs and shaders](#programs-and-shaders)
    - [materials](#materials)
    - [material parameters](#material-parameters)
  - [models](#models)
    - [importing models](#importing-models)
  - [lights](#lights)
  - [skeletons and rigs](#skeletons-and-rigs)
  - [animations](#animations)
  - [advanced rendering](#advanced-rendering)
    - [custom programs and materials](#custom-programs-and-materials)
  - [pbr](#pbr)
    - [environment and radiance](#environment-and-radiance)
    - [lights](#lights)
    - [shadows](#shadows)
  - [importers](#importers)
    - [gltf importer](#gltf-importer)
    - [obj importer](#obj-importer)
    
- [user interface](#user-interface)
  - [input](#input) 
  - [declarative graph](#declarative-graph)
  - [widgets](#widgets)
    - [basic widgets](#basic-widgets)
    - [basic controls](#basic-controls)
    - [sliders](#sliders)
    - [misc widgets](#misc-widgets)
    - [selector widgets](#selector-widgets)
    - [text editor](#text-editor)
    - [input widgets](#input-widgets)
    - [popups and modals](#popups-and-modals)
    - [toolbars](#toolbars)
    - [menus](#menus)
    - [containers](#containers)
    - [file browser](#file-browser)
    - [windows](#windows)
    - [dock containers](#dock-containers)
    - [nodes](#nodes)
    - [viewers](#viewers)
    - [layout system](#layout-system)
    - [skin system](#skin-system)
    - [styling](#styling)

- [sound](#sound)
  - [audio files](#audio-files)
  - [playing sounds](#playing-sounds)

- [physics](#physics)
  - [colliders](#colliders)
  - [solids](#solids-aka-rigid-bodies)
  - [queries and raycasts](#queries-and-raycasts)
  - [mediums](#mediums)

# toy engine manual

# quickstart

## simple game module

A Module is a group of c++ files located in the same directory, and meant to be compiled together.
A Project is a library or an executable, compose of a set of Modules. Modules and Projects are declared inside a `.lua` project file.  

The simplest toy project is composed one `.cpp` file, one `.h`, and a `genie.lua` project definition. let's create our first project :
```
+-- game
    +-- Game.h
    +-- Game.cpp
+-- scripts
    +-- genie.lua
    +-- Game.lua
+-- toy
    +-- ...
```

A module `.lua` project definition file in its simplest form looks like this :
```lua
-- module declaration
game = mud_module(nil, "game", ROOT_PATH, "game",  nil, nil, nil, toy.all)

-- project declaration
toy_shell("game", { game })
    -- add any "game" project specific configuration here
```

- First we declare the module itself, passing its main namespace `nil`, its name `"game"`, base path `ROOT_PATH`, subpath `"game"`, three declaration functions `nil, nil, nil`, and finally the list of dependencies `toy.all`.

  In this case, we select all toy modules as dependencies. We could pass a specific set of dependencies like so: `{ mud.infra, mud.math, toy.core }` for example.

- Second, we declare the project itself that will be built, which consists of one module. This allows to have a finer granularity of modules on one hand, and projects composed of modules on the other hand.

This script will be processed when using the [GENie](https://github.com/bkaradzic/GENie) project generator, which is the main supported build system for toy. They are used for all build-related tasks, specifically:
- precompiling modules to their reflection files
- generating project files/makefiles to build it

Now our basic project is setup, we can start writing the code.

Once the script is written, we can bootstrap the project, and regenerate project files, reflection, with the three following commands, `<platform>` being one of `win`, `linux`, `darwin`:
- `toy\mud\bin\<plaftorm>\genie bootstrap`
- `toy\mud\bin\<plaftorm>\genie <generator>` with a generator one of `gmake`, `vs2015`, `vs2017` depending on the target build system
- `toy\mud\bin\<plaftorm>\genie reflect`

## creating the app
```cpp
class MyGame : public GameModule
{
public:
    virtual void init(GameShell& app, Game& game) {}
    
    virtual void start(GameShell& app, Game& game) {}
    
    virtual void pump(GameShell& app, Game& game) {}
    
    virtual void scene(GameShell& app, GameScene& scene) {}
};

int main()
{
    GameShell app(TOY_RESOURCE_PATH, argc, argv);

    GameModule module;
    app.run_game(module);
}
```

This is the minimal code required to start a game with toy: it yields a running app, with a black screen :)
The `GameModule` interface provides four main hooks for writing your game logic:
- `init()` is called right after the app has initialized
- `start()` is called when a game is started
- `pump()` is called on each frame
- `scene()` is called every time a scene is created

Note: `GameModule` and `GameShell` are merely helper classes: you aren't in any way constrained to use them. If you want complete control over your application flow, you can borrow the setup logic from the [`Shell.cpp`](src/shell/Shell.cpp) file, and setup a working application in a couple dozen lines of code.

## rendering a cube
Rendering objects is simply a matter of creating a `Scene`, a `Viewer`, and submitting some geometry to the `Scene`.
- initialize the UI graph by calling `begin()` on the ui root
- add a `Viewer` to the UI graph by calling `scene_viewer()`
- initialize the render graph by calling `begin()` on the scene
- (optionally) add a `Node` to the render graph by calling `node()`
- add a `Cube` to the render graph by calling `shape()`

Note: The `scene_viewer()` function declares a special kind of `Viewer` that holds its own `Scene` inside. If you created a `Scene` separately, just call the `viewer()` function instead.

```cpp
class MyGame : public GameModule
{
public:
    // ...
    
    virtual void pump(GameShell& app, Game& game)
    {
        Widget& ui = app.m_ui.begin();
        Viewer& viewer = ui::scene_viewer(ui);
        
        Gnode& scene = viewer.m_scene.begin();
        
        Gnode& node = gfx::node(scene, {}, vec3(0.f, 0.f, 0.f));
        gfx::shape(node, Cube(1.f), Symbol(Colour::Pink));
    }
};
```

## rendering a model
Rendering a 3d `Model` is almost as simple as rendering a shape. Instead of calling `shape()`, you need to fetch the Model before calling `item()`.
- get the `Model` asset store by calling `models()` on the application `GfxSystem`
- fetch the `Model` by calling `file()` on the asset store
- draw the `Model` by calling `item()`

Note: You might want to get the `Model` once and store it somewhere.

```cpp
class MyGame : public GameModule
{
public:
    virtual void pump(GameShell& app, Game& game)
    {
        // ... (initialize the viewer)
        
        Model& model = app.m_gfx_system.models().file("my_model.obj");
        
        Gnode& node = gfx::node(scene, {}, vec3(0.f, 0.f, 0.f));
        gfx::item(node, model);
    }
};
```

## reacting to input
Querying events is done on the `Widget` object returned by the widget declaration, using the following functions (in this case on the `Viewer`):
- `key_event()` by passing the key code and the type of input event to check for
- `mouse_event()` by passing the mouse button and the type of input event to check for

Note: To fully grasp event dispatching you need to get familiar with how toy deals with the concepts of modal receivers, and focused receivers.

```cpp
class MyGame : public GameModule
{
public:
    virtual void pump(GameShell& app, Game& game)
    {
        static vec3 position = Zero3;
        
        Widget& ui = app.m_ui.begin();
        Viewer& viewer = ui::scene_viewer(ui);
        
        if(viewer.key_event(KC_A, EventType::Pressed))
            position += X3;
        if(viewer.key_event(KC_D, EventType::Pressed))
            position -= X3;
    }
};
```

## defining an entity type
An `Entity` in toy is a spatial object with children. It's convenient to define **game objects types** composed around an `Entity` as well as other components:
- an `Entity` component has a position, a rotation, and a list of children
- a `Movable` component has a linear and angular velocity


```cpp
class Monster : public Complex
{
public:
	Monster(Id id, Entity& parent, const vec3& position)
        : m_entity(id, parent, position)
        , m_movable(m_entity)
    {}

	Entity m_entity;
	Movable m_movable;
};
```

To move an entity, you can directly modify the `position`, `rotation` members, or use the mutating functions.

Note: toy doesn't feature flexible entity which you add and remove components to on-the-fly, because we prefer the convenience and safety of defining entity types. this feature might be added in the future for users wishing to assemble dynamic entities directly in the editor.

## drawing all entities
An optional way to draw `Entities` is to create a `GameScene`, and to add a `Painter` to it. Each frame, for each `Painter` you attached to it, the `GameScene` goes over all `Entities` of the given type, and send them to the given draw function.
- create a `GameScene` by calling `add_scene()` on the `Game` object
- in the `scene()` handler function, add one `Painter` for each type of entity you want to draw, passing the function (`paint_monster()` in the example)
- call `next_frame()` on the `GameScene`, each frame


```cpp
void paint_monster(Gnode& parent, Monster& monster)
{
    gfx::shape(parent, Cube(1.f), Symbol(Colour::Pink));
}

class MyGame : public GameModule
{
public:
    virtual void pump(GameShell& app, Game& game)
    {
        static GameScene& scene = game.add_scene();
        Viewer& viewer = ui::viewer(app.m_ui.begin(), scene);
        scene.next_frame();
    }
    
    virtual void scene(GameShell& app, GameScene& scene)
    {
        static OmniVision vision = { *scene.m_game.m_world };
        scene.entity_painter<Monster>("Monsters", vision.m_store, paint_monster);
    }
};
```

## defining a physics entity type
To give `Rigid Body` dynamics to an `Entity` you can add a `Solid` component to it, with the following parameters:
- the `Entity` itself
- the geometric `Shape` of the body
- whether it is a `static` body
- the `mass` of the body


```cpp
class Crate : public Complex
{
public:
	Crate(Id id, Entity& parent, const vec3& position)
        : m_entity(id, *this, parent, position)
        , m_movable(m_entity)
        , m_solid(m_entity, *this, Cube(1.f), false, 1.f))
    {}

	Entity m_entity;
	Movable m_movable;
    Solid m_solid;
};
```

# reflection

## annotating code
The prerequisite to using generic [primitives](#primitives) and [operations](#operations) on any given c++ construct, is to produce the necessary reflection data, for this construct.  
This is done by annotating the code in the following manner, which is then fed to a precompiler or reflection [generator](#generator) :
```c++
enum class refl_ ShapeType
{
    Sphere,
    Cube
};

class refl_ MyObject
{
public:
    constr_ MyObject(int number, std::string name);

    meth_ int method();

    attr_ int m_number;
    attr_ ShapeType m_shape;
};

func_ void bar(MyObject& object, int value);
```
Notice how this is a standard c++ definition, with some added [reflection hints](#hints): `refl_` to reflect a class, `_constr_` to reflect a constructor, `_meth_` for a reflected method, and `_attr_` for a reflected attribute.

Using these annotations, the reflection [generator](#generator) produces a couple of reflection files, which declares and registers [constructs](#constructs) using mud corresponding types: [functions](../src/type/Reflect/Method.h), [types](../src/type/Reflect/Meta.h), [classes](../src/type/Reflect/Class.h), [class members](../src/type/Reflect/Member.h), [class methods](../src/type/Reflect/Method.h), [enums](../src/type/Reflect/Enum.h).  

## precompiling

# scripting

# context
mud supports four context providers :
- [glfw](../src/ctx-glfw): cross-platform OpenGL context
- [windows](../src/ctx-win): native Windows context
- [emscripten](../src/ctx-wasm): native asmjs/WebAssembly context
- [ogre](../src/ctx-ogre): integration in the Ogre3d engine

you mostly don't need to touch these directly : contexts will be provided to you by a render system :
- [bgfx](../src/ctx-bgfx): lower level render system, on top of bgfx library (wraps all of the above)
- [gfx](../src/gfx): higher level gfx library

if you wish to only use mud up to the ui level, you must create a [bgfx render system](../src/ctx-bgfx/BgfxSystem.h) :
```c++
BgfxSystem render_system = {};
UiWindow& ui_window = render_system.create_window("My App", 800, 600, false);
```

if you wish to use mud gfx rendering library, just replace it with the [mud gfx render system](../src/gfx/GfxSystem.h) :
```c++
GfxSystem render_system = {};
UiWindow& ui_window = render_system.create_window("My App", 800, 600, false);
```

once this is done, your app is basically up and running  
you just need to update it each frame :
```c++
while(render_system->next_frame())
{
    // your application logic goes here
}
```

# math

# geometry

# graphics

## resources

### loading resources
the following graphics resources are loaded from files of standard formats:
- models: `.gltf` and `.obj` files
- programs: `.sc` files
- textures: `.png`, `.jpg`, `.raw`, etc (full list of formats supported by the bimg library)

the following graphics resources are created and managed by the graphics system:
- meshes
- materials

To load a resource, you need to use the AssetStore using the `load()` function, passing the path of the resource to be loaded.
Each Asset Store holds the specific operations to do in order to load a given type of resource. 

```cpp
Texture* texture = gfx_system.textures().file("my_texture.png");
Model* model = gfx_system.models().file("my_model.gltf");
```

Resources lifetimes are managed by the user explicitly: to free a resource, simply call

```cpp
gfx_system.textures().release(texture);
```

### asynchronous loading
resources can be loaded in a background thread. the returned pointer is null until the resource has actually loaded.

## scene and graph

### scene
Scenes represent a graph of objects to be rendered.

```cpp
Scene scene = { gfx_system };

while(true)
{
    // rendering logic
}
```

### declarative graph
Every rendered object in toy is added to a graph through a declarative idiom.
This means you don't need to manage the lifetimes of the rendered objects yourself: you just need to traverse, each frame, the declarations of what needs to be rendered, and the lifetime management is handled for you.

```cpp
// inside the drawing loop
Gnode& root = scene.begin();
Model& model = gfx_system.models().file("my_model.obj");
gfx::item(root, model);
```


## viewport and camera
Cameras represent the properties of the viewpoint used for rendering the Scene.
Viewports represent a rectangle on a render target to render a given Camera to.

As a user of toy, you will mostly be creating Viewers, which are interface elements themselves holding a Camera and a Viewport.
In this case you can interact with the underlying Camera and Viewport directly to change their parameters.
If you want to interact with the rendering layer directly though, the only things needed to start rendering is a Camera, a Viewport, and a Scene.

```cpp
Scene scene = { gfx_system };
Camera camera = { &scene };
Viewport viewport = { camera, scene };

gfx_context.m_viewports.push_back(&m_viewport);

while(true)
{
    // rendering logic
}
```

### camera
Cameras are defined by two points in space: the eye, and the target.

Like most classes of toy, the Camera fields can be modified on-the-fly, for direct effect.
- `m_ortographic`: whether or not this camera is an ortographic projection (if not set, it's a perspective projection)
- `m_fov`: the vertical field of view of the camera (horizontal is derived from this and the aspect ratio)
- `m_aspect`: the aspect ratio of the camera (this is updated automatically from the viewport proportions)
- `m_height`: the span of the vertical side of the ortographic view, in real world units

On each frame, you can change these to update how the camera is rendered.

```cpp
camera.m_ortographic = false;
camera.m_fov = 90.f;
```

The `m_lod_offsets` field holds 4 distances that can be tweaked to determine how the 4 LOD are distributed along the linear depth scale.

### viewport
Everything related to the specific effects applied to a rendering is applied to the viewport.

## meshes and models

### meshes
Meshes are the primitive geometry units used when rendering a scene. They map to the different primitives exposed by the rendering APIs: lines, line strips and loops, triangles, triangle strips and loops.

Meshes are never dealt with directly when rendering, because meshes are always rendered as part of a Model, which is simply a group of mesh with given transforms and materials for each mesh instance.

### creating meshes
Meshes are just a primitive type, and a set of buffers filled with data describing their vertices and indices. Filling these buffers is usually done by the different Model importers, but you can also create Meshes manually.

### cached meshes
Meshes are usually sent directly to the GPU, after the necessary attributes have been computed, like bounding volume. However you can specify a mesh to be kept accessible on the CPU side to access its vertices later-on.

To read a cached mesh, you need to fetch the `MeshData` stored in the `m_cache` attribute of the Mesh, and iterate over the vertices.
```cpp
MeshData data = mesh.m_cache;

for(size_t i = 0; i < data.m_vertices.size(); ++i)
{
    vec3 vertex = data.position());
    // use the vertex position
}
```

## textures
A Texture in toy is an image file that has been uploaded to the GPU, ready to be used for rendering.
toy uses the bimg library to load textures, which supports the following formats:
- `.bmp`: input (Windows Bitmap)
- `.dds`: input, output (Direct Draw Surface)
- `.exr`: input, output (OpenEXR)
- `.gif`: input (Graphics Interchange Format)
- `.jpg`: input (JPEG Interchange Format)
- `.hdr`: input, output (Radiance RGBE)
- `.ktx`: input, output (Khronos Texture)
- `.png`: input, output (Portable Network Graphics)
- `.psd`: input (Photoshop Document)
- `.pvr`: input (PowerVR)
- `.tga`: input (Targa)

A Texture is loaded explicitly with the following code:
```cpp
// loads and return a texture, or nullptr if the file isn't found in any resource paths
Texture* texture = gfx_system.textures().file("my_texture.png");
```

Some properties are stored in the Texture object for convenience:
- width and height
- pixel format

The Texture data can be read using the bgfx API directly, using `bgfx::readTexture()`

## shaders, programs, and materials

### programs and shaders
A Program in toy is defined as a combination of Shaders for a given draw call.
Usually, a Program is composed of a Vertex Shader and a Fragment Shader, which are defined in the bgfx shader language, which compiles to the target shader language required by the platform toy is running on.

### materials
A Material in toy is simply a set of parameters for a given (GPU) Program to execute correctly. In programming terms, the Program is a (very complex) function executed on the GPU, and the Material holds some of the specific parameters for that function invocation. Other parameters will come from other sources (Camera, Scene, Lights, Environment...).

To represent that distinction, Programs are composed of Blocks. A Program relies on a set of functional Blocks, some of which are Material Blocks, and some other Blocks. A Material associated to this Program holds one of each Material Blocks expected by the Program. The other Blocks are provided by the Scene, the Camera, etc...

A Block is simply a structure, holding data, uploaded to the GPU, to be used by the Program, on each render call.

For example, an Unshaded Material will be composed of the BaseMaterialBlock, and the UnshadedBlock. The Program expects only these two blocks, as well as the general RenderBlock holding camera, projection data.

The BasicBlock holds the following Material attributes, which are used by every Program:
- `m_cull_mode`: 
- `m_depth_draw_mode`:
- `m_depth_test`:
- `m_uvX_scale`: a scale applied to the X (0 or 1) set of UV 
- `m_uvX_offset`: an offset added to the X (0 or 1) set of UV
- `m_is_alpha`: whether this material uses alpha blending

```cpp
// fetch the program
Program& program = gfx_system.programs().file("unshaded");

// initialize a material with the required blocks
BasicBlock base_block = {};
UnshadedBlock unshaded_block = {};
Material material = { program, base_block, { unshaded_block } };
```

### material parameters
Material parameters, or Material Block parameters (since each one is accessed from its block), are set just like regular C++ attributes on any object.

Their only particularity is that most parameters are of the type MaterialParam<T>, which holds three things:
- the base value
- the texture bound to this parameters
- the texture channel on which this specific parameter value is encoded

```cpp
material.block<UnshadedBlock>().m_color.m_value = Colour::White;
material.block<UnshadedBlock>().m_color.m_texture = gfx_system.textures().file("my_texture.png");
```

## models
A Model is the basic primitive for rendering any geometry. When rendering any geometry, you render a Model, which gather a number of Meshes, each with a Transform and an assigned Material.
This is represented as a collection of ModelItems, stored in the `m_items` attribute. Each time you render a Model, you are actually sending each of the Meshes that compose it to the renderer.

### importing models

Models are imported by importers defined for each specific format. So far, toy provides an OBJ importer and a glTF importer.

The import process can be configured using a ModelConfig structured passed to the importer.
- `m_transform`: apply the transformation in this matrix to each imported mesh. this matrix can be easily composed using the math utility functions : `translation()`, `rotation()`, `scale()`.
- `m_format`: force importing as a specific format
- `m_normals`: whether or not normals must be imported
- `m_tangents`: whether or not tangents must be imported
- `m_cache_meshes`: force caching of imported meshes on CPU-side for later access

When rendering a model, the materials applied are the material specified in each ModelItem.
You can override the material, either for the whole model (i.e. all meshes) by passing a material, or you can override specific materials by creating a model variant.

## lights
Lights exist as graphics primitives in toy. However, until you use a shaded renderer pipeline, they won't actually affect rendering at all. This is on purpose: the toy renderer is flexible and designed to implement. toy provides a default PBR rendering pipeline that uses Lights as you would expect from any PBR renderer.

toy supports three types of lights:
- Spot lights
- Directional lights
- Point Lights

all lights have the following attributes:
- `m_colour`: the colour of the light energy
- `m_intensity`: the intensity of the light, in physical units
- `m_attenuation`: specifies the term of the attenuation formula
- `m_range`: the maximum range of the light, in any direction

the following parameters control the Light shadows:
- `m_shadows`: whether or not this light casts shadows
- `m_shadow_range`: maximum range of shadows
- `m_shadow_colour`: the color substracted from the light to compute shadows
- `m_shadow_bias` and `m_shadow_normal_bias`: the shadow bias offsets each geometry fragment towards the light source, while the normal bias offsets it in the direction of the normal.

the following are specific to Spot Lights:
- `m_spot_angle`: the angle of the spotlight cone
- `m_spot_attenuation`: the term of the spotlight attenuation formula (angle to direction axis)

## skeletons and rigs

## animations

## advanced rendering

### custom programs and materials


## pbr 

### environment and radiance

### lights

### shadows


## importers

### gltf importer
The glTF importer is a minimal implementation to load models written according the the `glTF 2.0 specification`.
To use it, you simply need to create the `ImporterGlTF` when initializing the application. The importer will automatically register itself to the Model Asset Store, so that you can directly open glTF models from files.


### obj importer
The OBJ importer implements importing of Wavefront OBJ files.
To use it, you simply need to create the `ImporterOBJ` when initializing the application. The importer will automatically register itself to the Model Asset Store, so that you can directly open OBJ models from files.


# user interface

## input 
Input handling is provided by the Context and injected directly into the User Interface. To query for any input, you will usually do so through a user interface element.
Since toy uses a immediate like paradigm, input handling is done in an immediate way, which means, you check for each event in the body of each of your user interface elements declaration functions.

To query for mouse button presses, you should use the `Widget::key_event()` query on the ui element.

```cpp
widget.key_event(KC_C, EventType::Stroked); // query for a key stroke
widget.key_event(KC_C, EventType::Pressed); // query for a key press
widget.key_event(KC_C, EventType::Released); // query for a key released
```

```cpp
widget.mouse_event(Device::LeftButton, EventType::Moved);
```

in general, events are dispatched in the following way :
- mouse events are dispatched to the top-most `OPAQUE` widget under the mouse cursor.
- key events are dispatched to the widget that has focus / is modal for the given input device.

to check for an event after you declared a widget, use the [following functions](https://github.com/hugoam/mud/blob/master/src/ui/Structs/Widget.h#L69) on the `Widget` object :
```c++
KeyEvent key_event(KeyCode code, EventType event_type, InputModifier modifier = InputModifier::Any);
KeyEvent key_event(KeyCode code, InputModifier modifier = InputModifier::Any);
MouseEvent mouse_event(DeviceType device, EventType event_type, InputModifier modifier = InputModifier::None, bool consume = true);
```

the returned object evaluates to true the widget received an event of this type, so the calling code usually looks like so :
```c++
if(MouseEvent mouse_event = self.mouse_event(DeviceType::MouseLeft, EventType::Pressed))
{
    // handle the event
}
```


## declarative graph

## widgets
to create a widget, call its function, the first parameter of which is always the **parent** it should be nested in.  
widgets taking a string or vector of string parameters representing their contents, display each string either as a label, or as an icon if it is of the form `(icon.png)`

### [basic widgets](../src/ui/Button/Button.h)
```c++
namespace ui
{
    Widget& icon(Widget& parent, const string& icon);
    Widget& label(Widget& parent, const string& label);
    Widget& text(Widget& parent, const string& label);
}
```

### [basic controls](../src/ui/Button/Button.h)
```c++
namespace ui
{
    Widget& button(Widget& parent, const string& content = "");
    Widget& multi_button(Widget& parent, const vector<string>& elements, Style* element_style = nullptr);
    
    Widget& toggle(Widget& parent, bool& on, const string& content = "");
    Widget& multi_toggle(Widget& parent, bool& on, const vector<string>& elements, Style* element_style = nullptr);
    
    Widget& checkbox(Widget& parent, bool& on);
}
```

### [sliders](../src/ui/Button/Slider.h)
```c++
namespace ui
{
    bool slider(Widget& parent, float& value, SliderMetrics metrics, Dim dim = DIM_X);
}
```

### [misc widgets](../src/ui/Button/Button.h)
```c++
namespace ui
{
    Widget& fill_bar(Widget& parent, float percentage, Dim dim = DIM_X);
}
```

### [selector widgets](../src/ui/Button/Button.h)
all selector widgets have a similar interface : they take a vector of string elements representing each choice, and they update an index parameter depending which is the currently selected choice

```c++
namespace ui
{
    bool radio_switch(Widget& parent, const vector<string>& labels, size_t& value);
    bool dropdown_input(Widget& parent, const vector<string>& choices, size_t& value, bool compact = false);
    bool typedown_input(Widget& parent, const vector<string>& choices, size_t& value);
}
```

### [text editor](../src/ui/TypeIn.h)
mud has a pretty full featured [text editor](../src/ui/TypeIn.h#L147) with mouse and keyboard selection, line numbers, undo and redo, syntax hilighting, on-hover tooltips, and auto-complete.

```c++
namespace ui
{
    TextEdit& type_in(Widget& parent, string& text, size_t lines = 1, const string& allowed_chars = "");
    TextEdit& text_edit(Widget& parent, string& text, size_t lines = 1, std::vector<string>* vocabulary = nullptr);
}
```

### [input widgets](../src/ui/Edit/Input.h)
there is a range of built-in input widgets :
`input<T>()` maps to number input for numbers, and to checkbox and textboxes for bool and string types

```c++
namespace ui
{
    template <class T>
    bool number_input(Widget& parent, T& value);
    
    template <class T>
    bool slider_input(Widget& parent, T& value);
    
    template <class T>
    bool input(Widget& parent, T& value);
}
```

### [popups and modals](../src/ui/Widget/Sheet.h)
```c++
namespace ui
{
    Widget& popup(Widget& parent, const vec2& position, bool modal);
    Widget& modal(Widget& parent);
}
```

### [toolbars](../src/ui/Button/Button.h)
```c++
namespace ui
{
    Widget& toolbutton(Widget& parent, const string& icon);
    Widget& tooldock(Widget& parent);
    Widget& toolbar(Widget& parent, bool wrap = false);
}
```
    
### [menus](../src/ui/Button/Button.h)
```c++
namespace ui
{
    Widget& menu_choice(Widget& parent, const vector<string>& elements);
    Widget& menu(Widget& parent, const string& label, bool submenu = false);
    Widget& menubar(Widget& parent);
}
```

### [containers](../src/ui/Container/Container.h)
```c++
namespace ui
{
    Table& table(Widget& parent, std::vector<string> columns, std::vector<float> weights);
}
```

```c++
namespace ui
{
    Expandbox& expandbox(Widget& parent, const vector<string>& elements, bool open = true);
    TreeNode& tree_node(Widget& parent, const vector<string>& elements, bool leaf = false, bool open = true);
}
```

```c++
namespace ui
{
    Widget* tab(Tabber& tabber, const string& name);
    Tabber& tabber(Widget& parent, bool downtabs = false);
}
```

### file browser
```c++
namespace ui
{
    Widget& file_browser(Widget& parent, string& path);
    Widget& file_tree(Widget& parent, const string& path);
}
```

### [windows](../src/ui/Window/Window.h)
```c++
namespace ui
{
    Window& window(Widget& parent, const string& title, WindowState state = WINDOW_DEFAULT);
}
```

### dock containers

### [nodes](../src/ui/Window/Node.h)
```c++
namespace ui
{
    Canvas& canvas(Widget& parent, const string& title, size_t num_nodes = 0);
    
    Node& node(Canvas& parent, const string& title, int order = 0);
    Node& node(Canvas& parent, const string& title, vec2& position, int order = 0);
    
    NodePlug& node_input(Node& node, const string& name, const string& icon, const Colour& colour, bool connected = false);
    NodePlug& node_output(Node& node, const string& name, const string& icon, const Colour& colour, bool connected = false);
}
```

## viewers

## layout system
the first fundamental block of **mud ui** is the **layout system** : it dictates the positioning and sizing of **all** widgets on the screen.  
each widget in mud has a [frame](../src/ui/Frame/Frame.h) object : mostly a rectangle with a few additional properties.  
every frame that is in the [flow]() is automatically laid out by its parent [solver](), depending on both children and parent layout properties.

the most important properties governing layout are the following :
- [solver](../src/ui/Frame/Dim.h#L58) : which solver should be used to layout the children : 
  - `row solver`: the simple and ubiquitous solver : lays out its children in a sequence, and computes its size as the sum of its children sizes.
  - complex solvers are made of sub-solvers :
  - `grid solver`: lays out children in multiple rows according to a 2d index (x, y)
  - `table solver`: lays out children in rows vertically, and in columns horizontally
- [flow](../src/ui/Frame/Dim.h#L73) : whether or not the widget is part of the automatic layout flow.
  - `flow`: is in the parent flow = positioned and sized by the parent solver
  - `free`: not in the parent flow = positions itself, but sized by the parent (outside of the flow)
- [direction](../src/ui/Frame/Dim.h#L31) : the direction of the flow, in which the children are laid out. it can be either of :
  - relative : `orthogonal` or `parallel` to its parent own direction
  - absolute : `paragraph` or `reading`, meaning vertical or horizontal.
- [sizing](../src/ui/Frame/Dim.h#L81) : how the size of a widget is computed : one of `expand`, `shrink`, `content` or `wrap`
  - `expand` : takes all available space in the parent
  - `shrink` : shrinks to the total measured size of all children widgets in the [flow]()
  - `fixed` : determined by its content (a string or an image)
  - `wrap` : hybrid behavior, expanding as soon as there is available space, but wrapping the contents if space is minimal

aditionally, some more cosmetic layout attributes governs some sizing and positioning offsets :
- [span](../src/ui/Frame/Dim.h) : how much of the parent space an `expand` or `wrap` widget wants to occupy, as a ratio
- [padding](../src/ui/Frame/Dim.h) : an offset added **inside** the widget frame, padding it around its content
- [margin](../src/ui/Frame/Dim.h): an offset added **around** the widget frame when it laid out by its parent
- [spacing](../src/ui/Frame/Dim.h): an offset added **between each widget** positioned in the flow
- [pivot](../src/ui/Frame/Dim.h#L40): in which direction the solver sequences its children : `forward` or `reverse`
- [aligh](../src/ui/Frame/Dim.h#L46): where in the parent sequence should the widget be aligned

we believe the above set of properties and solvers is sufficiently wide, so that roughly any thinkable 2d layout of frames can be produced, while being quite simpler than the CSS layout rules.

all these properties are computed for each frame, by their widget [style](../src/ui/Frame/Style.h#L163), which holds a [layout](../src/ui/Frame/Style.h#L82) object.

## skin system
if the layout of the frames is determined by the layout, the graphical appearance of the ui elements itself is determined by the [skin](../src/ui/Style/Style.h#L114).  
[styles](../src/ui/Style/Style.h#L163) hold both : a layout, a skin, and an additional list of skins affected to specific widget states.

the skin properties are *very* similar to CSS graphical properties :
- [background colour](../src/ui/Style/Style.h#L133), [border colour](../src/ui/Style/Style.h#L134), [text colour](../src/ui/Style/Style.h#L135): self-explanatory
- [text font](../src/ui/Style/Style.h#L136): self-explanatory
- [text break](../src/ui/Style/Style.h#L137): should the text be broken in lines when newlines are encountered
- [text wrap](../src/ui/Style/Style.h#L138): should the text wrap around the frame edges
- [border width](../src/ui/Style/Style.h#L139): four values, as in CSS (and in the same order: left, top, right, bottom)
- [corner radius](../src/ui/Style/Style.h#L140): four values, as in CSS (same order)
- [padding](../src/ui/Style/Style.h#L140): an offset added around the frame content (image/string)
- [margin](../src/ui/Style/Style.h#L140): an offset added around the frame content
- [align](../src/ui/Style/Style.h#L140): how the content aligns in the frame
- [image](../src/ui/Style/Style.h#L140): 
- [overlay](../src/ui/Style/Style.h#L140): an image applied as overlay
- [tile](../src/ui/Style/Style.h#L140): an image applied in a tiled repating pattern
- [image skin](../src/ui/Style/ImageSkin.h#L18): an image skin, defined by 9 sprites
- [shadow](../src/ui/Style/Style.h#L140): 
- [shadow colour](../src/ui/Style/Style.h#L140):
- [hover cursor](../src/ui/Style/Style.h#L140):

## styling
a [style](../src/ui/Style/Style.h#L163) object contains a [layout](../src/ui/Frame/Style.h#L82) and [skin](../src/ui/Style/Style.h#L114) which are both applied to each widget set to this style.  
a **style** also holds some [additional skins](../src/ui/Style/Style.h#L163) that apply only to specific widget states.

all ui widgets have a [default style](../src/ui/Style/Style.h#L193), identified by having the same name as the widget:
in the following code the widget will use the style called `"button"`:
```c++
ui::button(parent, "Click me!");
```

most ui widgets have an overload allowing you to explicitly set a style as the second parameter :
```c++
static Style my_style = { "MyStyle" };
ui::button(parent, my_style, "Click me!");
```

in the lack of c++ designated initializers, we have a special syntax which allows us to use "named" arguments :
```c++
static Style my_style = { "MyStyle", Args{ { &Layout::m_space, BLOCK } } };
```

styles can be modified and created from code. but more interestingly, they can be modified all at once by loading a `json style sheet`.
by switching between style sheets on the fly, you can instantly change the **whole** appearance of the ui.
mud ui provides four default style sheets : `minimal`, `vector`, `blendish` and `blendish dark`.

to load a style sheet, use the following parser [functions](../src/ui/Style/StyleParser.h#L13) :
```c++
ui::set_style_sheet(ui_window.m_styler, ui_window.m_resource_path + "interface/styles/minimal.json");
```

a [json style sheet](../data/interface/styles/minimal.yml) consists mainly of a sequence of selectors, each one setting some attributes of the selected styles (indiscriminately of whether it's a layout or a skin attribute) :  
```json
{   
    "selector" : "Tooltip, Popdown, DropdownList, MenuList, SubMenuList",
    "background_colour" : [1.0, 0.43, 0.7, 1],
    "border_colour" : { "r": 1.0, "g": 0.43, "b": 0.7 },
    "text_colour" : "ClearGreyText"
},
```
notice how attributes can be either set as a list of arguments (of their type constructor), or as a named object.  
colours in particular can also be identified by a name, referencing colours indexed in the [colours](../data/interface/styles/minimal.yml) section at the top of the style sheet.

to set attributes for a specific widget states, the syntax is the following :
```json
{   
    "selector" : "Button", 
    "hovered" : {
        "background_colour" : "Grey312"
    }
}
```


# sound

## audio files

## playing sounds

# physics

## colliders

## solids (aka rigid bodies)

## queries and raycasts

## mediums
