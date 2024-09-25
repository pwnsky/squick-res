// -------------------------------------------------------------------------
//    @FileName         :    Excel.cs
//    @Author           :    I0gan
//    @Module           :    Excel
// -------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
namespace Excel
{
	public class Group
	{
		//Class name
		public static readonly String ThisName = "Group";
		// IObject
		public static readonly String ClassName = "ClassName";// string
		public static readonly String ConfigID = "ConfigID";// string
		public static readonly String ID = "ID";// string
		// Property
		// Record

	}
	public class IObject
	{
		//Class name
		public static readonly String ThisName = "IObject";
		// Property
		public static readonly String ClassName = "ClassName";// string
		public static readonly String ConfigID = "ConfigID";// string
		public static readonly String ID = "ID";// string
		// Record

	}
	public class Object
	{
		//Class name
		public static readonly String ThisName = "Object";
		// IObject
		public static readonly String ClassName = "ClassName";// string
		public static readonly String ConfigID = "ConfigID";// string
		public static readonly String ID = "ID";// string
		// Property
		public static readonly String Disable = "Disable";// int
		public static readonly String GroupID = "GroupID";// int
		public static readonly String MasterID = "MasterID";// object
		public static readonly String MoveTo = "MoveTo";// vector3
		public static readonly String Position = "Position";// vector3
		public static readonly String SceneID = "SceneID";// int
		// Record

	}
	public class Player
	{
		//Class name
		public static readonly String ThisName = "Player";
		// IObject
		public static readonly String ClassName = "ClassName";// string
		public static readonly String ConfigID = "ConfigID";// string
		public static readonly String ID = "ID";// string
		// Property
		public static readonly String Account = "Account";// string
		public static readonly String GameID = "GameID";// int
		public static readonly String GateID = "GateID";// int
		public static readonly String LastOfflineTime = "LastOfflineTime";// object
		public static readonly String OnlineCount = "OnlineCount";// int
		public static readonly String OnlineTime = "OnlineTime";// object
		public static readonly String Position = "Position";// vector3
		public static readonly String TotalTime = "TotalTime";// int
		// Record

	}
	public class Property
	{
		//Class name
		public static readonly String ThisName = "Property";
		// IObject
		public static readonly String ClassName = "ClassName";// string
		public static readonly String ConfigID = "ConfigID";// string
		public static readonly String ID = "ID";// string
		// Property
		public static readonly String Account = "Account";// string
		public static readonly String OnlineCount = "OnlineCount";// int
		// Record

	}
	public class Record
	{
		//Class name
		public static readonly String ThisName = "Record";
		// IObject
		public static readonly String ClassName = "ClassName";// string
		public static readonly String ConfigID = "ConfigID";// string
		public static readonly String ID = "ID";// string
		// Property
		// Record
		public class Inventory
		{
			//Class name
			public static readonly String ThisName = "Inventory";
			public const int ConfigID = 0;//string
			public const int ItemCount = 1;//int

		}
		public class InventoryEquipment
		{
			//Class name
			public static readonly String ThisName = "InventoryEquipment";
			public const int GUID = 0;//object
			public const int ConfigID = 1;//string
			public const int RandPropertyID = 2;//string
			public const int RandPropertyValue = 3;//int
			public const int IntensifyLevel = 4;//int
			public const int Date = 5;//int
			public const int Equipped = 6;//int
			public const int Stone1 = 7;//string
			public const int Stone2 = 8;//string
			public const int Stone3 = 9;//string
			public const int Stone4 = 10;//string
			public const int Lock = 11;//int
			public const int Future = 12;//int
			public const int UserData = 13;//string

		}

	}
	public class Scene
	{
		//Class name
		public static readonly String ThisName = "Scene";
		// IObject
		public static readonly String ClassName = "ClassName";// string
		public static readonly String ConfigID = "ConfigID";// string
		public static readonly String ID = "ID";// string
		// Property
		public static readonly String ActorID = "ActorID";// int
		public static readonly String GroupID = "GroupID";// int
		public static readonly String MaxGroup = "MaxGroup";// int
		public static readonly String MaxGroupPlayers = "MaxGroupPlayers";// int
		public static readonly String RelivePos = "RelivePos";// string
		public static readonly String RelivePosEx = "RelivePosEx";// string
		public static readonly String ResourcePos = "ResourcePos";// string
		public static readonly String SceneID = "SceneID";// int
		public static readonly String SceneName = "SceneName";// string
		public static readonly String SceneShowName = "SceneShowName";// string
		public static readonly String SoundList = "SoundList";// string
		public static readonly String SubType = "SubType";// int
		public static readonly String Type = "Type";// int
		public static readonly String Width = "Width";// int
		// Record

	}

}