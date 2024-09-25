-- -------------------------------------------------------------------------
--    @FileName         :    excel.h
--    @Author           :    I0gan
--    @Module           :    Excel
-- -------------------------------------------------------------------------
-- Do not edit it, generated from excel files by sqkctl tools
Excel = {
	Group= {
		--Class name
		ThisName="Group",
		-- IObject
		ClassName="ClassName",-- string
		ConfigID="ConfigID",-- string
		ID="ID",-- string
		-- Property
		-- Record

	},
	IObject= {
		--Class name
		ThisName="IObject",
		-- Property
		ClassName="ClassName",-- string
		ConfigID="ConfigID",-- string
		ID="ID",-- string
		-- Record

	},
	Object= {
		--Class name
		ThisName="Object",
		-- IObject
		ClassName="ClassName",-- string
		ConfigID="ConfigID",-- string
		ID="ID",-- string
		-- Property
		Disable="Disable",-- int
		GroupID="GroupID",-- int
		MasterID="MasterID",-- object
		MoveTo="MoveTo",-- vector3
		Position="Position",-- vector3
		SceneID="SceneID",-- int
		-- Record

	},
	Player= {
		--Class name
		ThisName="Player",
		-- IObject
		ClassName="ClassName",-- string
		ConfigID="ConfigID",-- string
		ID="ID",-- string
		-- Property
		Account="Account",-- string
		GameID="GameID",-- int
		GateID="GateID",-- int
		LastOfflineTime="LastOfflineTime",-- object
		OnlineCount="OnlineCount",-- int
		OnlineTime="OnlineTime",-- object
		Position="Position",-- vector3
		TotalTime="TotalTime",-- int
		-- Record

	},
	Property= {
		--Class name
		ThisName="Property",
		-- IObject
		ClassName="ClassName",-- string
		ConfigID="ConfigID",-- string
		ID="ID",-- string
		-- Property
		Account="Account",-- string
		OnlineCount="OnlineCount",-- int
		-- Record

	},
	Record= {
		--Class name
		ThisName="Record",
		-- IObject
		ClassName="ClassName",-- string
		ConfigID="ConfigID",-- string
		ID="ID",-- string
		-- Property
		-- Record
		Inventory={
			-- Class name
			ThisName="Inventory",
			ConfigID=0,--string
			ItemCount=1,--int

		};
		InventoryEquipment={
			-- Class name
			ThisName="InventoryEquipment",
			GUID=0,--object
			ConfigID=1,--string
			RandPropertyID=2,--string
			RandPropertyValue=3,--int
			IntensifyLevel=4,--int
			Date=5,--int
			Equipped=6,--int
			Stone1=7,--string
			Stone2=8,--string
			Stone3=9,--string
			Stone4=10,--string
			Lock=11,--int
			Future=12,--int
			UserData=13,--string

		};

	},
	Scene= {
		--Class name
		ThisName="Scene",
		-- IObject
		ClassName="ClassName",-- string
		ConfigID="ConfigID",-- string
		ID="ID",-- string
		-- Property
		ActorID="ActorID",-- int
		GroupID="GroupID",-- int
		MaxGroup="MaxGroup",-- int
		MaxGroupPlayers="MaxGroupPlayers",-- int
		RelivePos="RelivePos",-- string
		RelivePosEx="RelivePosEx",-- string
		ResourcePos="ResourcePos",-- string
		SceneID="SceneID",-- int
		SceneName="SceneName",-- string
		SceneShowName="SceneShowName",-- string
		SoundList="SoundList",-- string
		SubType="SubType",-- int
		Type="Type",-- int
		Width="Width",-- int
		-- Record

	},

}