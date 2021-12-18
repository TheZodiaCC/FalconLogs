modded class PlayerBase
{
	override void EEKilled(Object killer)
    {
		if (!CommitedSuicide()) 
		{
			Weapon_Base weapon = Weapon_Base.Cast(killer);
			
			PlayerBase playerKiller = PlayerBase.Cast(weapon.GetHierarchyRootPlayer());
			
			FalconLogsUtils.logKillFeed(this, playerKiller, weapon.GetName());
		}
		
		super.EEKilled(killer);
    }
}