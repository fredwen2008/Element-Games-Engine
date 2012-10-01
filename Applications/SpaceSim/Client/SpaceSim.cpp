#include "SpaceSim.h"

SpaceSim::SpaceSim(EG::Utility::Window *_window, EG::Game::Scene *_scene) : Game(_window, _scene) {
    network->Connect("127.0.0.1", "admin", "admin");
}

SpaceSim::~SpaceSim(void) {
    //
}

void SpaceSim::ProcessNetworkPacket(float frame_time, EG::Network::Packet* packet) {
    sf::Packet *sfpacket = packet->GetPacket();
    unsigned int action_type_id;
    *(sfpacket) >> action_type_id;
    if (action_type_id == NETWORK_ACTION_MESSAGE_RELAY) {
        unsigned int client_id, from_client_id;
        std::string message;
        *(sfpacket) >> client_id >> from_client_id >> message;
        std::stringstream stream;
        stream << "Received Broadcast Message From " << client_id << ":" << from_client_id << " of " << message << std::endl;
        console->Print(stream.str());
    }
}

void SpaceSim::NetworkUpdates(float frame_time) {
    bool got_packet = false;
    EG::Network::Packet *packet = network->ReceivePacket(got_packet);
    while (got_packet) {
        ProcessNetworkPacket(frame_time, packet);
        packet = network->ReceivePacket(got_packet);
    }
}

void SpaceSim::InputUpdates(float frame_time) {
    float movement_speed = frame_time * 2.0f;
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
    if (input->IsKeyPressed(EG::Input::k)) {
        EG::Network::Packet *packet = new EG::Network::Packet();
        std::string message = "What's up server!";
        *(packet->GetPacket()) << NETWORK_ACTION_MESSAGE_BROADCAST << network->GetClientId() << message;
        network->SendPacket(packet);
        console->Print("Sending Broadcast Message");
    }
    if (input->IsKeyPressed(EG::Input::p)) {
        network->PollLAN();
    }
}

void SpaceSim::PhysicsUpdates(float frame_time) {
    physics->Update(frame_time);
}

void SpaceSim::Update(void) {
    float frame_time = time->GetFrameTime();
    NetworkUpdates(frame_time);
    InputUpdates(frame_time);
    PhysicsUpdates(frame_time);
}