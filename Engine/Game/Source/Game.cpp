#include "../Game.h"
#include "../ObjectBasicAttribute.h"
#include "../ObjectControlAttribute.h"
#include "../ObjectEmissionAttribute.h"
#include "../../Media/AssimpInterface.h"
#include "../../Graphics/RendererDeferred.h"
#include "../../Graphics/RendererMultipass.h"
#include "../../Utility/UnsignedIntDictionary.h"

namespace EG{
    namespace Game{
        Game::Game(EG::Utility::Window *_window, EG::Game::Scene *_scene){
            use_gui = false;
            window = _window;
            scene = _scene;
            input = new EG::Input::Input();
            sfml_interface->SetInput(input);
            time = new EG::Utility::Time();
            graphics->Initialize(window->GetResolutionWidth(), window->GetResolutionHeight());

            // Resolution needs to be from config
            rendering_method = RENDERER_SIMPLE;

            if (graphics->CheckVersion(3, 1)){
            //if (graphics->CheckVersion(4, 1)){
                if (rendering_method == RENDERER_SIMPLE){
                    rendering_method = RENDERER_DEFERRED;
                }
            }else{
                rendering_method = RENDERER_SIMPLE;
                //graphics->OverrideVersion(2, 1);
            }
            if (rendering_method == RENDERER_SIMPLE){
                renderer = new EG::Graphics::Renderer();
                renderer->Initialize();
            }else if (rendering_method == RENDERER_MULTIPASS){
                renderer = new EG::Graphics::RendererMultipass();
                (static_cast<EG::Graphics::RendererMultipass *>(renderer))->Initialize();
            }else if (rendering_method == RENDERER_DEFERRED){
                renderer = new EG::Graphics::RendererDeferred();
                (static_cast<EG::Graphics::RendererDeferred *>(renderer))->Initialize();
            }
            //gui = new EG::GUI::GUI();

            physics = new EG::Dynamics::Physics();

            time->Update();
            if (use_gui){
                gui->Update();
            }
        }

        Game::~Game(void){
            //
        }

        void Game::Update(void){
            float movement_speed = time->GetFrameTime() * 2.0f;
            if (input->IsMouseDown(EG::Input::mouse_right)){
                renderer->GetCamera()->RotateByMouse(input->GetMouseDelta());
            }
            if (input->IsKeyDown(EG::Input::q)){
                renderer->GetCamera()->Rotate(glm::vec3(0.0f, 0.0f, -movement_speed));
            }
            if (input->IsKeyDown(EG::Input::e)){
                renderer->GetCamera()->Rotate(glm::vec3(0.0f, 0.0f, movement_speed));
            }
            if (input->IsKeyDown(EG::Input::w)){
                renderer->GetCamera()->Move(glm::vec3(0.0f, 0.0f, -movement_speed));
            }
            if (input->IsKeyDown(EG::Input::s)){
                renderer->GetCamera()->Move(glm::vec3(0.0f, 0.0f, movement_speed));
            }
            if (input->IsKeyDown(EG::Input::a)){
                renderer->GetCamera()->Move(glm::vec3(-movement_speed, 0.0f, 0.0f));
            }
            if (input->IsKeyDown(EG::Input::d)){
                renderer->GetCamera()->Move(glm::vec3(movement_speed, 0.0f, 0.0f));
            }
            if (input->IsKeyDown(EG::Input::space)){
                renderer->GetCamera()->Move(glm::vec3(0.0f, movement_speed, 0.0f));
            }
            if (input->IsKeyDown(EG::Input::c)){
                renderer->GetCamera()->Move(glm::vec3(0.0f, -movement_speed, 0.0f));
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

        void Game::Render(void){
            PostUpdates();
            if (rendering_method == RENDERER_SIMPLE){
                renderer->Render(scene, time->GetFrameTime());
            }else if (rendering_method == RENDERER_MULTIPASS){
                (static_cast<EG::Graphics::RendererMultipass *>(renderer))->Render(scene);
            }else if (rendering_method == RENDERER_DEFERRED){
                (static_cast<EG::Graphics::RendererDeferred *>(renderer))->Render(scene, time->GetFrameTime());
            }
            window->Display();
            PreUpdates();
        }

        void Game::PreUpdates(void){
            time->Update();
            window->Update();
        }

        void Game::PostUpdates(void){
            if (use_gui){
                gui->Update();
            }

            input->Update();

            EG::Utility::UnsignedIntDictionaryKeysIterator object_iter = scene->GetObjectManager()->GetObjects()->GetKeysBegin();
            while (object_iter != scene->GetObjectManager()->GetObjects()->GetKeysEnd()){
                unsigned int object_id = (*object_iter);
                EG::Game::Object *object = scene->GetObjectManager()->GetObject(object_id);

                if (object->HasAttributesOfType(EG::Game::ObjectAttribute::OBJECT_ATTRIBUTE_EMISSION_PARTICLE_SYSTEM)){
                    std::vector<EG::Game::ObjectAttribute *> *attrs = object->GetAttributesByType(EG::Game::ObjectAttribute::OBJECT_ATTRIBUTE_EMISSION_PARTICLE_SYSTEM);
                    std::vector<EG::Game::ObjectAttribute *>::iterator attr_iter = attrs->begin();
                    while (attr_iter != attrs->end()){
                        EG::Game::ObjectAttributeEmissionParticleSystem *pattr = static_cast<EG::Game::ObjectAttributeEmissionParticleSystem *>(*attr_iter);

                        EG::Graphics::ParticleSystem *psys = pattr->GetParticleSystem();
                        std::list<EG::Graphics::Particle *> *particles = psys->GetParticles();
                        std::list<EG::Graphics::Particle *>::iterator piter = particles->begin();
                        while (piter != particles->end()){
                            EG::Graphics::Particle *p = (*piter);
                            bool has_physics = false;
                            glm::mat4 motion_state;
                            if (p->HasAttributesOfType(EG::Game::ObjectAttribute::OBJECT_ATTRIBUTE_CONTROL_RIGID_BODY)){
                                std::vector<EG::Game::ObjectAttribute *> *attrs = p->GetAttributesByType(EG::Game::ObjectAttribute::OBJECT_ATTRIBUTE_CONTROL_RIGID_BODY);
                                std::vector<EG::Game::ObjectAttribute *>::iterator attr_iter = attrs->begin();
                                while (attr_iter != attrs->end()){
                                    EG::Game::ObjectAttributeControlRigidBody *rigid_body_attr = static_cast<EG::Game::ObjectAttributeControlRigidBody *>(*attr_iter);
                                    if (!(rigid_body_attr->GetConnected())){
                                        physics->AddRigidBody(rigid_body_attr->GetBody());
                                        rigid_body_attr->SetConnected(true);
                                    }

                                    if (!(p->Alive())){
                                        physics->RemoveRigidBody(rigid_body_attr->GetBody());
                                    }

                                    // TODO: Get Motion State From Physics
                                    EG::Dynamics::RigidBody *body = rigid_body_attr->GetBody();
                                    motion_state = body->GetMotionState();
                                    has_physics = true;

                                    ++attr_iter;
                                }
                            }

                            if (has_physics && p->HasAttributesOfType(EG::Game::ObjectAttribute::OBJECT_ATTRIBUTE_BASIC_TRANSFORMATION)){
                                std::vector<EG::Game::ObjectAttribute *> *attrs = p->GetAttributesByType(EG::Game::ObjectAttribute::OBJECT_ATTRIBUTE_BASIC_TRANSFORMATION);
                                std::vector<EG::Game::ObjectAttribute *>::iterator attr_iter = attrs->begin();
                                while (attr_iter != attrs->end()){
                                    EG::Game::ObjectAttributeBasicTransformation *trans_attr = static_cast<EG::Game::ObjectAttributeBasicTransformation *>(*attr_iter);
                                    trans_attr->SetTransformation(motion_state);
                                    ++attr_iter;
                                }
                            }
                            ++piter;
                        }

                        pattr->GetParticleSystem()->Update(time->GetFrameTime());
                        ++attr_iter;
                    }
                }

                bool has_physics = false;
                glm::mat4 motion_state;
                if (object->HasAttributesOfType(EG::Game::ObjectAttribute::OBJECT_ATTRIBUTE_CONTROL_RIGID_BODY)){
                    std::vector<EG::Game::ObjectAttribute *> *attrs = object->GetAttributesByType(EG::Game::ObjectAttribute::OBJECT_ATTRIBUTE_CONTROL_RIGID_BODY);
                    std::vector<EG::Game::ObjectAttribute *>::iterator attr_iter = attrs->begin();
                    while (attr_iter != attrs->end()){
                        EG::Game::ObjectAttributeControlRigidBody *rigid_body_attr = static_cast<EG::Game::ObjectAttributeControlRigidBody *>(*attr_iter);
                        if (!(rigid_body_attr->GetConnected())){
                            physics->AddRigidBody(rigid_body_attr->GetBody());
                            rigid_body_attr->SetConnected(true);
                        }

                        // TODO: Get Motion State From Physics
                        EG::Dynamics::RigidBody *body = rigid_body_attr->GetBody();
                        motion_state = body->GetMotionState();
                        has_physics = true;

                        ++attr_iter;
                    }
                }

                if (has_physics && object->HasAttributesOfType(EG::Game::ObjectAttribute::OBJECT_ATTRIBUTE_BASIC_TRANSFORMATION)){
                    std::vector<EG::Game::ObjectAttribute *> *attrs = object->GetAttributesByType(EG::Game::ObjectAttribute::OBJECT_ATTRIBUTE_BASIC_TRANSFORMATION);
                    std::vector<EG::Game::ObjectAttribute *>::iterator attr_iter = attrs->begin();
                    while (attr_iter != attrs->end()){
                        EG::Game::ObjectAttributeBasicTransformation *trans_attr = static_cast<EG::Game::ObjectAttributeBasicTransformation *>(*attr_iter);
                        trans_attr->SetTransformation(motion_state);
                        ++attr_iter;
                    }
                }

                ++object_iter;
            }
        }

        EG::Utility::Window *Game::GetWindow(void){
            return window;
        }

        EG::Game::Scene *Game::GetScene(void){
            return scene;
        }

        EG::Graphics::Renderer *Game::GetRenderer(void){
            return renderer;
        }
    }
}
