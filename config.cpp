class CfgPatches
{
	class NR_AnomalySystem_Admin
	{
		requiredVersion=1;
		requiredAddons[] = {"JM_CF_Scripts","DZM_VPPAdminToolsScripts"};
	};
};

class CfgMods
{
	class NR_AnomalySystem_Admin
	{
		type="mod";
		dependencies[]= { "Game", "World", "Mission" };
		
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"NR/NR_AnomalySystem_Admin/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[] = {"NR/NR_AnomalySystem_Admin/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"NR/NR_AnomalySystem_Admin/scripts/5_Mission"};
			};
		};
	};
};