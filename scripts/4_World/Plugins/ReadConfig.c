modded class PluginManager
{
	override void Init()
	{
		super.Init();
		RegisterPlugin("MenuAnomalyManager", false, true); // Название мода, вкл/выкл на клиенте, вкл/выкл на сервере
	}
};