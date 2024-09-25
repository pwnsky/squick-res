// -------------------------------------------------------------------------
//    @FileName         :    excel.h
//    @Author           :    I0gan
//    @Module           :    Excel
// -------------------------------------------------------------------------

#ifndef SQUICK_PR_NAME_HPP
#define SQUICK_PR_NAME_HPP

#include <string>
namespace excel
{
	class Group
	{
	public:
		//Class name
		static const std::string& ThisName(){ static std::string x = "Group"; return x; };		// IObject
		static const std::string& ClassName(){ static std::string x = "ClassName"; return x; };// string
		static const std::string& ConfigID(){ static std::string x = "ConfigID"; return x; };// string
		static const std::string& ID(){ static std::string x = "ID"; return x; };// string
		// Property
		// Record

	};
	class IObject
	{
	public:
		//Class name
		static const std::string& ThisName(){ static std::string x = "IObject"; return x; };		// Property
		static const std::string& ClassName(){ static std::string x = "ClassName"; return x; };// string
		static const std::string& ConfigID(){ static std::string x = "ConfigID"; return x; };// string
		static const std::string& ID(){ static std::string x = "ID"; return x; };// string
		// Record

	};
	class Object
	{
	public:
		//Class name
		static const std::string& ThisName(){ static std::string x = "Object"; return x; };		// IObject
		static const std::string& ClassName(){ static std::string x = "ClassName"; return x; };// string
		static const std::string& ConfigID(){ static std::string x = "ConfigID"; return x; };// string
		static const std::string& ID(){ static std::string x = "ID"; return x; };// string
		// Property
		static const std::string& Disable(){ static std::string x = "Disable"; return x; };// int
		static const std::string& GroupID(){ static std::string x = "GroupID"; return x; };// int
		static const std::string& MasterID(){ static std::string x = "MasterID"; return x; };// object
		static const std::string& MoveTo(){ static std::string x = "MoveTo"; return x; };// vector3
		static const std::string& Position(){ static std::string x = "Position"; return x; };// vector3
		static const std::string& SceneID(){ static std::string x = "SceneID"; return x; };// int
		// Record

	};
	class Player
	{
	public:
		//Class name
		static const std::string& ThisName(){ static std::string x = "Player"; return x; };		// IObject
		static const std::string& ClassName(){ static std::string x = "ClassName"; return x; };// string
		static const std::string& ConfigID(){ static std::string x = "ConfigID"; return x; };// string
		static const std::string& ID(){ static std::string x = "ID"; return x; };// string
		// Property
		static const std::string& Account(){ static std::string x = "Account"; return x; };// string
		static const std::string& GameID(){ static std::string x = "GameID"; return x; };// int
		static const std::string& GateID(){ static std::string x = "GateID"; return x; };// int
		static const std::string& LastOfflineTime(){ static std::string x = "LastOfflineTime"; return x; };// object
		static const std::string& OnlineCount(){ static std::string x = "OnlineCount"; return x; };// int
		static const std::string& OnlineTime(){ static std::string x = "OnlineTime"; return x; };// object
		static const std::string& Position(){ static std::string x = "Position"; return x; };// vector3
		static const std::string& TotalTime(){ static std::string x = "TotalTime"; return x; };// int
		// Record

	};
	class Property
	{
	public:
		//Class name
		static const std::string& ThisName(){ static std::string x = "Property"; return x; };		// IObject
		static const std::string& ClassName(){ static std::string x = "ClassName"; return x; };// string
		static const std::string& ConfigID(){ static std::string x = "ConfigID"; return x; };// string
		static const std::string& ID(){ static std::string x = "ID"; return x; };// string
		// Property
		static const std::string& Account(){ static std::string x = "Account"; return x; };// string
		static const std::string& OnlineCount(){ static std::string x = "OnlineCount"; return x; };// int
		// Record

	};
	class Record
	{
	public:
		//Class name
		static const std::string& ThisName(){ static std::string x = "Record"; return x; };		// IObject
		static const std::string& ClassName(){ static std::string x = "ClassName"; return x; };// string
		static const std::string& ConfigID(){ static std::string x = "ConfigID"; return x; };// string
		static const std::string& ID(){ static std::string x = "ID"; return x; };// string
		// Property
		// Record
		class Inventory
		{
		public:
			//Class name
			static const std::string& ThisName(){ static std::string x = "Inventory"; return x; };
			static const int ConfigID = 0;//string
			static const int ItemCount = 1;//int

		};
		class InventoryEquipment
		{
		public:
			//Class name
			static const std::string& ThisName(){ static std::string x = "InventoryEquipment"; return x; };
			static const int GUID = 0;//object
			static const int ConfigID = 1;//string
			static const int RandPropertyID = 2;//string
			static const int RandPropertyValue = 3;//int
			static const int IntensifyLevel = 4;//int
			static const int Date = 5;//int
			static const int Equipped = 6;//int
			static const int Stone1 = 7;//string
			static const int Stone2 = 8;//string
			static const int Stone3 = 9;//string
			static const int Stone4 = 10;//string
			static const int Lock = 11;//int
			static const int Future = 12;//int
			static const int UserData = 13;//string

		};

	};
	class Scene
	{
	public:
		//Class name
		static const std::string& ThisName(){ static std::string x = "Scene"; return x; };		// IObject
		static const std::string& ClassName(){ static std::string x = "ClassName"; return x; };// string
		static const std::string& ConfigID(){ static std::string x = "ConfigID"; return x; };// string
		static const std::string& ID(){ static std::string x = "ID"; return x; };// string
		// Property
		static const std::string& ActorID(){ static std::string x = "ActorID"; return x; };// int
		static const std::string& GroupID(){ static std::string x = "GroupID"; return x; };// int
		static const std::string& MaxGroup(){ static std::string x = "MaxGroup"; return x; };// int
		static const std::string& MaxGroupPlayers(){ static std::string x = "MaxGroupPlayers"; return x; };// int
		static const std::string& RelivePos(){ static std::string x = "RelivePos"; return x; };// string
		static const std::string& RelivePosEx(){ static std::string x = "RelivePosEx"; return x; };// string
		static const std::string& ResourcePos(){ static std::string x = "ResourcePos"; return x; };// string
		static const std::string& SceneID(){ static std::string x = "SceneID"; return x; };// int
		static const std::string& SceneName(){ static std::string x = "SceneName"; return x; };// string
		static const std::string& SceneShowName(){ static std::string x = "SceneShowName"; return x; };// string
		static const std::string& SoundList(){ static std::string x = "SoundList"; return x; };// string
		static const std::string& SubType(){ static std::string x = "SubType"; return x; };// int
		static const std::string& Type(){ static std::string x = "Type"; return x; };// int
		static const std::string& Width(){ static std::string x = "Width"; return x; };// int
		// Record

	};

}
#endif