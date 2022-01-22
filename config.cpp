class CfgPatches
{
	class FalconLogs
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data"};
	};
};

class CfgMods
{
	class FalconLogs
	{
	    dir = FalconLogs
	    picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
	    name = FalconLogs
	    credits = "";
	    author = "zNitche";
	    authorID = "0";
	    version = "1.0";
	    extra = 0;
	    type = "mod";

	    dependencies[] = {"World", "Mission"};

		class defs
		{
			class missionScriptModule
			{
				value = "";
				files[] = {
										"FalconLogs/5_Mission",
										"FalconLogs/Defines"
									};
			};

			class worldScriptModule
			{
				value = "";
				files[] = {
										"FalconLogs/4_World",
										"FalconLogs/Defines"
									};
			};
		};
	};
};
