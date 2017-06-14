#pragma once
#include <Urho3D/Core/Object.h>
#include <SampleProject/SampleObject.hpp>

//@ASBindGen Class ObjectType=Ref
class SampleContainer : public Urho3D::Object
{
URHO3D_OBJECT (SampleContainer, Object)
protected:
    Urho3D::Vector <Urho3D::SharedPtr <SampleObject> > objects_;

public:
    //@ASBindGen Constructor UseUrho3DScriptContext_arg0
    SampleContainer (Urho3D::Context *context);
    virtual ~SampleContainer ();

    //@ASBindGen Function ReturnHandleArray
    Urho3D::Vector <Urho3D::SharedPtr <SampleObject> > GetObjects () const;
    //@ASBindGen Function OverrideName=get_objectsCount
    unsigned GetObjectsCount () const;
    //@ASBindGen Function AddRef_arg0
    void AddObject (SampleObject *object);
    //@ASBindGen Function AddRef_arg-1
    SampleObject *GetObjectByIndex (unsigned index) const;
    //@ASBindGen Function AddRef_arg0
    bool RemoveObject (SampleObject *object);
};
