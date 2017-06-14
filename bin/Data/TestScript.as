void Start ()
{
    log.Info ("Script executed!");
    XMLFile @defaultStyle = cache.GetResource ("XMLFile", "UI/DefaultStyle.xml");
    ui.root.defaultStyle = defaultStyle;

    Text @text = ui.root.CreateChild ("Text");
    text.SetStyleAuto ();
    text.SetPosition (50, 50);
    text.fontSize = 15;
    text.text = "Hello, world!";

    SampleContainer @container = SampleContainer ();
    text.text = text.text + "\nSampleContainer created.";

    SampleObject @object = SampleObject (Random (10.0f) * Random (10.0f));
    text.text = text.text + "\nSampleObject with value " + object.value + " created. Refs count: " + object.refs + ".";

    container.AddObject (object);
    text.text = text.text + "\nSampleObject with value " + object.value + " added to container. Refs count: " + object.refs + ".";

    container.RemoveObject (object);
    text.text = text.text + "\nSampleObject with value " + object.value + " removed from container. Refs count: " + object.refs + ".\n";

    text.text = text.text + "\nAdding 10 objects to container...";
    for (uint index = 0; index < 10; index++)
    {
        container.AddObject (SampleObject (Random (10.0f) * Random (10.0f)));
    }

    text.text = text.text + "\nContainer size is " + container.objectsCount + ". Objects values:";
    for (uint index = 0; index < container.objectsCount; index++)
    {
        text.text = text.text + "\n    " + container.GetObjectByIndex (index).value;
    }
    log.Info (text.text);
}
