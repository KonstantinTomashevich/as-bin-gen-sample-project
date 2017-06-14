#include "SampleObject.hpp"

SampleObject::SampleObject (Urho3D::Context *context) : Urho3D::Object (context),
    value_ (0.0f)
{

}

SampleObject::SampleObject (Urho3D::Context *context, float value) : Urho3D::Object (context),
    value_ (value)
{

}

SampleObject::~SampleObject ()
{

}

float SampleObject::GetValue () const
{
    return value_;
}

void SampleObject::SetValue (float value)
{
    value_ = value;
}
