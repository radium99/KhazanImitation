// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProjectPart4 : ModuleRules
{
	public ProjectPart4(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"ProjectPart4",
			"ProjectPart4/Variant_Platforming",
			"ProjectPart4/Variant_Platforming/Animation",
			"ProjectPart4/Variant_Combat",
			"ProjectPart4/Variant_Combat/AI",
			"ProjectPart4/Variant_Combat/Animation",
			"ProjectPart4/Variant_Combat/Gameplay",
			"ProjectPart4/Variant_Combat/Interfaces",
			"ProjectPart4/Variant_Combat/UI",
			"ProjectPart4/Variant_SideScrolling",
			"ProjectPart4/Variant_SideScrolling/AI",
			"ProjectPart4/Variant_SideScrolling/Gameplay",
			"ProjectPart4/Variant_SideScrolling/Interfaces",
			"ProjectPart4/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
