using UnrealBuildTool;

public class ALSEditor : ModuleRules
{
	public ALSEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;

		bEnableNonInlinedGenCppWarnings = true;

		PublicDependencyModuleNames.AddRange(new[]
		{
			"Core", "CoreUObject", "Engine", "AnimationModifiers", "AnimationBlueprintLibrary", "ALS"
		});

		if (Target.bBuildEditor)
		{
			PublicDependencyModuleNames.AddRange(new[]
			{
				"AnimGraph"
			});

			PrivateDependencyModuleNames.AddRange(new[]
			{
				"BlueprintGraph"
			});
		}
	}
}