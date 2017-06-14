#include "SampleContainer.hpp"

SampleContainer::SampleContainer (Urho3D::Context *context) : Urho3D::Object (context),
    objects_ ()
{

}

SampleContainer::~SampleContainer ()
{

}

Urho3D::Vector <Urho3D::SharedPtr <SampleObject> > SampleContainer::GetObjects() const
{
    return objects_;
}

unsigned SampleContainer::GetObjectsCount () const
{
    return objects_.Size ();
}

void SampleContainer::AddObject (SampleObject *object)
{
    objects_.Push (Urho3D::SharedPtr <SampleObject> (object));
}

SampleObject *SampleContainer::GetObjectByIndex (unsigned index) const
{
    return objects_.At (index);
}

bool SampleContainer::RemoveObject (SampleObject *object)
{
    objects_.Remove (Urho3D::SharedPtr <SampleObject> (object));
}
