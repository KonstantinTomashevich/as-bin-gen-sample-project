#include "SampleProject.hpp"
#include <Urho3D/Input/Input.h>
#include <Urho3D/Engine/EngineDefs.h>

#include <Urho3D/Core/ProcessUtils.h>
#include <Urho3D/Core/CoreEvents.h>
#include <Urho3D/Resource/ResourceCache.h>

#include <Urho3D/AngelScript/Script.h>
#include <Urho3D/AngelScript/ScriptFile.h>
#include <SampleProject/AngelScriptBindings/Bindings.cpp>

URHO3D_DEFINE_APPLICATION_MAIN (SampleProject)
SampleProject::SampleProject (Urho3D::Context *context) :
    Urho3D::Application (context)
{

}

SampleProject::~SampleProject ()
{

}

void SampleProject::Setup ()
{
    engineParameters_ [Urho3D::EP_FULL_SCREEN] = false;
    engineParameters_ [Urho3D::EP_WINDOW_RESIZABLE] = true;
    engineParameters_ [Urho3D::EP_WINDOW_TITLE] = "ASBindGen Sample Project";
}

void SampleProject::Start ()
{
    // Set mouse to free mode.
    Urho3D::Input *input = GetSubsystem <Urho3D::Input> ();
    input->SetMouseVisible (true);
    input->SetMouseMode (Urho3D::MM_FREE);

    // Generate random seed from system time.
    Urho3D::SetRandomSeed (Urho3D::Time::GetTimeSinceEpoch ());

    // Initialize AngelScript.
    Urho3D::Script *script = new Urho3D::Script (context_);
    context_->RegisterSubsystem (script);
    Bindings::RegisterAnything (script->GetScriptEngine ());

    // Execute test script
    Urho3D::ResourceCache *cache = context_->GetSubsystem <Urho3D::ResourceCache> ();
    Urho3D::ScriptFile *scriptFile = cache->GetResource <Urho3D::ScriptFile> ("TestScript.as");
    scriptFile->Execute ("void Start ()");

    if (!Urho3D::GetArguments ().Empty () && Urho3D::GetArguments ().At (0) == "--test")
    {
        engine_->Exit ();
    }
}

void SampleProject::Stop ()
{

}
