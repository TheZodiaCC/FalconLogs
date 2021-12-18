#define FALCON_MISSIONS


class FalconLogsUtils
{
	static const string playersLogsDataPath = FalconLogsConsts.PLAYERS_LOGS_DATA_DIR_PATH;
	static const string actionsLogsDataPath = FalconLogsConsts.ACTIONS_LOGS_DATA_DIR_PATH;
	static const string tradesLogsDataPath = FalconLogsConsts.TRADES_LOGS_DATA_DIR_PATH;
	static const string couriersLogsDataPath = FalconLogsConsts.COURIERS_LOGS_DATA_DIR_PATH;
	static const string killsLogsDataPath = FalconLogsConsts.KILLS_LOGS_DATA_DIR_PATH;
	static const string adminsLogsDataPath = FalconLogsConsts.ADMINS_LOGS_DATA_DIR_PATH;
	
	
	static string getTimestamp()
	{
		int hour, minute, second;
		int year, month, day;
		
		GetHourMinuteSecondUTC(hour, minute, second);
		GetYearMonthDayUTC(year, month, day);
		
		string timestamp = year.ToString() + "-" + month.ToString() + "-" + day.ToString() + " " + hour.ToString() + ":" + minute.ToString();
		
		return timestamp;
	}
	
	static void logPlayerData(PlayerBase player, bool loggedOff)
	{
		string filePath = playersLogsDataPath + player.GetIdentity().GetId() + ".txt"; 
		string timestamp = getTimestamp();
		
		FileHandle file = OpenFile(filePath, FileMode.WRITE);
		
		FPrintln(file, "LogTimestamp: " + timestamp);
		FPrintln(file, "PlayerID: " + player.GetIdentity().GetId());
		FPrintln(file, "PlayerName: " + player.GetIdentity().GetName());
		FPrintln(file, "PlayerHealth: " + player.GetHealth());
		FPrintln(file, "PlayerLastPos: " + player.GetPosition().ToString());
		FPrintln(file, "LoggedOff: " + loggedOff.ToString());
		
		CloseFile(file);
	}
	
	static void logAdminAction(PlayerIdentity playerID, string message)
	{
		string timestamp = getTimestamp();
		
		string filePath = adminsLogsDataPath + playerID.GetId() + ".txt"; 
		string fullMessage = timestamp + ":" + message;
		
		FileHandle file;
		
		if (FileExist(filePath))
		{
			file = OpenFile(filePath, FileMode.APPEND);
			FPrintln(file, fullMessage);
		}
		else
		{
			file = OpenFile(filePath, FileMode.WRITE);
			FPrintln(file, fullMessage);
		}
		
		CloseFile(file);
	}
	
	static void logKillFeed(PlayerBase victim, PlayerBase killer, string weaponName)
	{
		#ifdef FALCON_MISSIONS
		if (victim.IsInherited(FalconAI) || killer.IsInherited(FalconAI))
		{
			return;
		}
		#endif
		
		string timestamp = getTimestamp();
		
		string filePath = killsLogsDataPath + killer.GetIdentity().GetId() + ".txt"; 
		string fullMessage = killer.GetIdentity().GetName() + "(" + killer.GetIdentity().GetId() + ") killed " + victim.GetIdentity().GetName() + "(" + victim.GetIdentity().GetName() + ") using " + weaponName;
		
		FileHandle file;
		
		if (FileExist(filePath))
		{
			file = OpenFile(filePath, FileMode.APPEND);
			FPrintln(file, fullMessage);
		}
		else
		{
			file = OpenFile(filePath, FileMode.WRITE);
			FPrintln(file, fullMessage);
		}
		
		CloseFile(file);
	}
}