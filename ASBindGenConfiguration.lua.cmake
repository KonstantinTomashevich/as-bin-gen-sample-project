configuration = {}
configuration.pathPrefix = "./sources"
configuration.projectDir = "SampleProject"
configuration.bindingsDir = "AngelScriptBindings"
configuration.bindingsFileName = "Bindings"
configuration.bindingsGeneratorCommand = "//@ASBindGen"

configuration.files = {
${COLONIZATION_HEADERS_LIST}
}

configuration.outputHppFileTemplate = "./sources/SampleProject/Bindings.hpp.template"
configuration.outputCppFileTemplate = "./sources/SampleProject/Bindings.cpp.template"
return configuration
