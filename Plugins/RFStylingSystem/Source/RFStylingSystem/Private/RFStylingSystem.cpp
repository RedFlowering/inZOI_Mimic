// Copyright 2024 RedFlowering, All Rights Reserved.

#include "RFStylingSystem.h"

#define LOCTEXT_NAMESPACE "FRFStylingSystemModule"

DEFINE_LOG_CATEGORY(RFLogSystem);

void FRFStylingSystemModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FRFStylingSystemModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRFStylingSystemModule, RFStylingSystem)