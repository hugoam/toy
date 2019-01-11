#include <block/Api.h>
#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(toy_block)
{
    
    // Enums
    enum_<toy::MatterState>("toy::MatterState")
        .value("Solid", toy::MatterState::Solid)
        .value("Liquid", toy::MatterState::Liquid)
        .value("Gas", toy::MatterState::Gas)
        .value("Plasma", toy::MatterState::Plasma)
        ;
    
    // Sequences
    
    // Arrays
    
    // Structs
    value_object<mud::Grid<toy::Block*>>("Grid<toy::Block*>")
        ;
    value_object<mud::ComponentHandle<toy::Block>>("ComponentHandle<toy::Block>")
        ;
    value_object<mud::ComponentHandle<toy::Chunk>>("ComponentHandle<toy::Chunk>")
        ;
    value_object<mud::ComponentHandle<toy::Heap>>("ComponentHandle<toy::Heap>")
        ;
    value_object<mud::ComponentHandle<toy::Sector>>("ComponentHandle<toy::Sector>")
        ;
    value_object<mud::ComponentHandle<toy::Tileblock>>("ComponentHandle<toy::Tileblock>")
        ;
    
    // Classes
    class_<toy::Block>("Block")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HWorldPage, toy::Block*, size_t, const mud::vec3&>()
        .property("world_page", &toy::Block::world_page)
        .property("parentblock", &toy::Block::parentblock)
        .property("index", &toy::Block::index)
        .property("size", &toy::Block::size)
        .property("updated", &toy::Block::updated)
        .function("subdivide", &toy::Block::subdivide)
        .function("reset", &toy::Block::reset)
        .function("chunk", &toy::Block::chunk)
        .function("commit", &toy::Block::commit)
        ;
    class_<toy::Chunk>("Chunk")
        .constructor<>()
        .constructor<toy::HSpatial, toy::Block&, size_t, toy::Element&, float>()
        .property("index", &toy::Chunk::index)
        .property("block", &toy::Chunk::block)
        .property("element", &toy::Chunk::element)
        .property("size", &toy::Chunk::size)
        ;
    class_<toy::Element>("Element")
        .constructor<const char*, toy::MatterState, mud::Colour>()
        .property("id", &toy::Element::id)
        .property("name", &toy::Element::name)
        .property("state", &toy::Element::state)
        .property("colour", &toy::Element::colour)
        ;
    class_<toy::Heap>("Heap")
        .constructor<>()
        .constructor<toy::HSpatial, toy::Element&, float>()
        .property("element", &toy::Heap::element)
        .property("radius", &toy::Heap::radius)
        ;
    class_<toy::Sector>("Sector")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HWorldPage, toy::HNavblock, const mud::uvec3&, const mud::vec3&>()
        .property("coordinate", &toy::Sector::coordinate)
        .property("size", &toy::Sector::size)
        .property("block", &toy::Sector::block)
        ;
    class_<toy::Tileblock>("Tileblock")
        .constructor<>()
        .constructor<toy::HSpatial, toy::HWorldPage, toy::HNavblock, const mud::uvec3&, const mud::vec3&, mud::WaveTileset&>()
        .property("wfc_block", &toy::Tileblock::wfc_block)
        .property("setup", &toy::Tileblock::setup)
        .property("populated", &toy::Tileblock::populated)
        ;
    class_<toy::Earth>("Earth")
        .constructor<>()
        .class_property("me", &toy::Earth::me)
        ;
    
    // Functions
    function("paint_block_height", &toy::paint_block_height);
    function("paint_block_elements", &toy::paint_block_elements);
    function("generate_block", &toy::generate_block);
    function("build_block_geometry", &toy::build_block_geometry);
    function("index_blocks", &toy::index_blocks);
    
}
