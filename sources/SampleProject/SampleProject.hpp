#pragma once
#include <Urho3D/Engine/Application.h>

class SampleProject : public Urho3D::Application
{
URHO3D_OBJECT (SampleProject, Object)
public:
    explicit SampleProject (Urho3D::Context *context);
    virtual ~SampleProject ();

    virtual void Setup ();
    virtual void Start ();
    virtual void Stop ();
};

