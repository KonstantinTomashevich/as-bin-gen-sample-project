#pragma once
#include <Urho3D/Core/Object.h>

//@ASBindGen Class ObjectType=Ref
class SampleObject : public Urho3D::Object
{
URHO3D_OBJECT (SampleObject, Object)
protected:
    float value_;

public:
    //@ASBindGen Constructor UseUrho3DScriptContext_arg0
    explicit SampleObject (Urho3D::Context *context);
    //@ASBindGen Constructor UseUrho3DScriptContext_arg0
    SampleObject (Urho3D::Context *context, float value);
    virtual ~SampleObject ();

    //@ASBindGen Function OverrideName=get_value
    float GetValue () const;
    //@ASBindGen Function OverrideName=set_value
    void SetValue (float value);
};
