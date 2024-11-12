modded class VPPAdminHud
{
   override void DefineButtons()
	{
       //super.DefineButtons();
       InsertButton("MenuAnomalyManager", "#VSTR_ANOMALY_MANAGER_TITLE", "set:ccgui_enforce image:Icon40Flares", "#VSTR_TOOLTIP_ANOMALY_MANAGER");
   };
};

class MenuAnomalyManager extends AdminHudSubMenu
{
	private bool m_Init;

    private Widget                 m_TeleportPresetsDropDown;
    private Widget                 m_StaticPresetsDropDown;
    private Widget                 m_DynamicPresetsDropDown;

    protected ref VPPDropDownMenu  m_TeleportPresetsDropDownInstance;
    protected ref VPPDropDownMenu  m_StaticPresetsDropDownInstance;
    protected ref VPPDropDownMenu  m_DynamicPresetsDropDownInstance;

    private TextListboxWidget      m_AnomalyListBox;
    private XComboBoxWidget        m_ComboAnomaly;
    //private TextListboxWidget      m_ScrollerAnomaly;

	static const string FOLDER_PATH = "$profile:NR_AnomalySystem/";
    static const string FILE_PATH = FOLDER_PATH + "SpawnerConfig.json";
	
	void MenuAnomalyManager()
	{
		GetRPCManager().AddRPC("RPC_MenuAnomalyManager", "HandleData", this, SingleplayerExecutionType.Client);
	}
	
	override void OnCreate(Widget RootW)
	{
		super.OnCreate(RootW);
		
		M_SUB_WIDGET  = CreateWidgets(NR_VPPATUIConstants.MenuAnomalyManager);
		M_SUB_WIDGET.SetHandler(this);
		m_TitlePanel  = Widget.Cast( M_SUB_WIDGET.FindAnyWidget( "Header") );
		m_closeButton = ButtonWidget.Cast( M_SUB_WIDGET.FindAnyWidget( "BtnClose") );

        m_AnomalyListBox    = TextListboxWidget.Cast( M_SUB_WIDGET.FindAnyWidget( "AnomalyListBox") );
        m_AnomalyZoneListBox    = TextListboxWidget.Cast( M_SUB_WIDGET.FindAnyWidget( "AnomalyZoneListBox") );
        m_ComboAnomaly      = XComboBoxWidget.Cast( M_SUB_WIDGET.FindAnyWidget( "ComboAnomaly") );

        //Preset Drop Downs
        m_TeleportPresetsDropDown = Widget.Cast( M_SUB_WIDGET.FindAnyWidget("TeleportPresetsDropDown") );
        m_TeleportPresetsDropDownInstance = new VPPDropDownMenu( m_TeleportPresetsDropDown, "" );
        m_TeleportPresetsDropDownInstance.AddElement("Вход в бункер Кордон");

        m_StaticPresetsDropDown = Widget.Cast( M_SUB_WIDGET.FindAnyWidget("StaticPresetsDropDown") );
        m_StaticPresetsDropDownInstance = new VPPDropDownMenu( m_StaticPresetsDropDown, "" );
        m_StaticPresetsDropDownInstance.AddElement("Дикая территория жарки");

        m_DynamicPresetsDropDown = Widget.Cast( M_SUB_WIDGET.FindAnyWidget("DynamicPresetsDropDown") );
        m_DynamicPresetsDropDownInstance = new VPPDropDownMenu( m_DynamicPresetsDropDown, "" );
        m_DynamicPresetsDropDownInstance.AddElement("Тест черно");
        //end
		
		m_Init = true;

        CreateAnomalyList();
		CreateTeleportList();
	}
	
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);
		
		if (!IsSubMenuVisible() && M_SUB_WIDGET == null)
			return;
	}
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
        return super.OnClick(w, x, y, button);
	}

	override void HideSubMenu()
	{
		super.HideSubMenu();
	}
	
	override void ShowSubMenu()
	{
		super.ShowSubMenu();
	}

    void CreateAnomalyList()
    {
        string path = "cfgVehicles";
		string child_name = "";
		int count = g_Game.ConfigGetChildrenCount(path);
		
		for (int p = 0; p < count; ++p)
		{
			GetGame().ConfigGetChildName(path, p, child_name);
			
			if (GetGame().ConfigGetInt(path + " " + child_name + " scope") == 2 && GetGame().IsKindOf(child_name, "AnomalySpawn_Burner"))
            {
                child_name.Replace("AnomalySpawn_", "");

				//m_AnomalyListBox.AddItem( child_name, NULL, 0 );
				m_ComboAnomaly.AddItem( child_name );
            }
		}
    }

	void CreateTeleportList()
	{

	}
};