modded class MissionServer
{
	override void InvokeOnDisconnect(PlayerBase player)
	{
		super.InvokeOnDisconnect(player);
		
		FalconLogsUtils.logPlayerData(player, true);
	}
	
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		FalconLogsUtils.logPlayerData(player, false);
		
		super.InvokeOnConnect(player, identity);
		
	}
}