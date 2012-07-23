#include "Editor.h"
#include "../../Engine/Game/ObjectBasicAttribute.h"
#include "../../Engine/Game/ObjectControlAttribute.h"
#include "../../Engine/Game/ObjectEmissionAttribute.h"
#include "../../Engine/Game/ObjectRenderingAttribute.h"
#include "../../Engine/Graphics/Renderer.h"
#include "../../Engine/Graphics/RendererDeferred.h"

std::string GetVideoSettingsListener::Call(std::map<std::string, std::string> args) {
    std::string out;
    out += "{";

    std::string bloom_enabled = "false";
    if (renderer->GetBloomEnabled()) {
        bloom_enabled = "true";
    }
    out += "\"bloom\": " + bloom_enabled;

    std::string ssao_enabled = "false";
    if (renderer->GetSSAOEnabled()) {
        ssao_enabled = "true";
    }
    out += " ,\"ssao\": " + ssao_enabled;

    std::string normal_mapping_enabled = "false";
    if (renderer->GetNormalMappingEnabled()) {
        normal_mapping_enabled = "true";
    }
    out += " ,\"normal_mapping\": " + normal_mapping_enabled;

    std::string shadow_mapping_enabled = "false";
    if (renderer->GetShadowsEnabled()) {
        shadow_mapping_enabled = "true";
    }
    out += " ,\"shadows\": " + shadow_mapping_enabled;

    std::string dof_enabled = "false";
    if (renderer->GetDepthOfFieldEnabled()) {
        dof_enabled = "true";
    }
    out += " ,\"dof\": " + dof_enabled;

    out += "}";
    std::cout << "Bin Response: " << out << std::endl;
    return out.c_str();
}

std::string SetVideoSettingsListener::Call(std::map<std::string, std::string> args) {
    std::cout << "Dongle" << std::endl;
    if (args["bloom"] == "true") {
        renderer->SetBloomEnabled(true);
    } else {
        renderer->SetBloomEnabled(false);
    }
    if (args["normal_mapping"] == "true") {
        renderer->SetNormalMappingEnabled(true);
    } else {
        renderer->SetNormalMappingEnabled(false);
    }
    if (args["ssao"] == "true") {
        renderer->SetSSAOEnabled(true);
    } else {
        renderer->SetSSAOEnabled(false);
    }
    if (args["shadows"] == "true") {
        renderer->SetShadowsEnabled(true);
    } else {
        renderer->SetShadowsEnabled(false);
    }
    if (args["dof"] == "true") {
        renderer->SetDepthOfFieldEnabled(true);
    } else {
        renderer->SetDepthOfFieldEnabled(false);
    }
    return "{\"status\": true}";
}

Editor::Editor(EG::Utility::Window *_window, EG::Game::Scene *_scene) : Game(_window, _scene){
    gui->Initialize("Assets/GUIs/Editor", "index.html");

    GetVideoSettingsListener *get_video_listener = new GetVideoSettingsListener();
    get_video_listener->scene = scene;
    get_video_listener->renderer = renderer;
    gui->AddResponseHandler("get_video_settings", get_video_listener);

    SetVideoSettingsListener *set_video_listener = new SetVideoSettingsListener();
    set_video_listener->scene = scene;
    set_video_listener->renderer = renderer;
    gui->AddResponseHandler("set_video_settings", set_video_listener);
}

Editor::~Editor(void){
    //
}

void Editor::Update(void){
    float movement_speed = time->GetFrameTime() * 2.0f;
    if (input->IsKeyDown(EG::Input::v)) {
        movement_speed /= 100.0f;
    }
    if (input->IsMouseDown(EG::Input::mouse_right)){
        scene->GetCurrentCamera()->RotateByMouse(input->GetMouseDelta());
    }
    if (input->IsKeyDown(EG::Input::q)){
        scene->GetCurrentCamera()->Rotate(glm::vec3(0.0f, 0.0f, -movement_speed));
    }
    if (input->IsKeyDown(EG::Input::e)){
        scene->GetCurrentCamera()->Rotate(glm::vec3(0.0f, 0.0f, movement_speed));
    }
    if (input->IsKeyDown(EG::Input::w)){
        scene->GetCurrentCamera()->Move(glm::vec3(0.0f, 0.0f, -movement_speed));
    }
    if (input->IsKeyDown(EG::Input::s)){
        scene->GetCurrentCamera()->Move(glm::vec3(0.0f, 0.0f, movement_speed));
    }
    if (input->IsKeyDown(EG::Input::a)){
        scene->GetCurrentCamera()->Move(glm::vec3(-movement_speed, 0.0f, 0.0f));
    }
    if (input->IsKeyDown(EG::Input::d)){
        scene->GetCurrentCamera()->Move(glm::vec3(movement_speed, 0.0f, 0.0f));
    }
    if (input->IsKeyDown(EG::Input::space)){
        scene->GetCurrentCamera()->Move(glm::vec3(0.0f, movement_speed, 0.0f));
    }
    if (input->IsKeyDown(EG::Input::c)){
        scene->GetCurrentCamera()->Move(glm::vec3(0.0f, -movement_speed, 0.0f));
    }
    if (input->IsKeyPressed(EG::Input::t)){
        if (rendering_method == RENDERER_DEFERRED){
            (static_cast<EG::Graphics::RendererDeferred *>(renderer))->CycleOutputType();
        }
    }
    if (input->IsKeyPressed(EG::Input::b)){
        if (rendering_method == RENDERER_DEFERRED){
            (static_cast<EG::Graphics::RendererDeferred *>(renderer))->ToggleBloom();
        }
    }
    if (input->IsKeyPressed(EG::Input::o)){
        if (rendering_method == RENDERER_DEFERRED){
            (static_cast<EG::Graphics::RendererDeferred *>(renderer))->ToggleSSAO();
        }
    }
    if (input->IsKeyPressed(EG::Input::n)){
        if (rendering_method == RENDERER_DEFERRED){
            (static_cast<EG::Graphics::RendererDeferred *>(renderer))->ToggleNormalMapping();
        }
    }
    if (input->IsKeyPressed(EG::Input::m)){
        if (rendering_method == RENDERER_DEFERRED){
            (static_cast<EG::Graphics::RendererDeferred *>(renderer))->ToggleShadowMapping();
        }
    }
    if (input->IsKeyPressed(EG::Input::f)){
        if (rendering_method == RENDERER_DEFERRED){
            (static_cast<EG::Graphics::RendererDeferred *>(renderer))->ToggleDOF();
        }
    }

    physics->Update(time->GetFrameTime());
}
