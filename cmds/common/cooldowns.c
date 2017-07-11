/* cooldowns command displays cooldowns
 * 11 June 2017
 * Duuk
 */
 
mixed cmd(string args) {
  object viewer = this_player();
  object who;
  string *cooldowns = ({ });
  string dis = "";
  
  if (playerp(viewer)) who = viewer;
  if (!args) who = viewer;
  if (creatorp(viewer) && args) {
    who = find_living(args);
    if (!who) {
    	viewer->eventPrint("Can't find anyone named " + args + ".");
    	return 1;
    }
  }
  if (creatorp(who)) {
  	viewer->eventPrint("That person has been on cooldown since 1994.");
  	return 1;
  }
  cooldowns = who->GetCooldowns();
  if (!sizeof(cooldowns)) {
  	viewer->eventPrint("No pending cooldowns for " + who->GetCapName() + ".");
  	return 1;
  }
  viewer->eventPrint("Cooldowns for " + who->GetCapName() + ":");
  foreach(string c in cooldowns) {
  	viewer->eventPrint(c + ": " + who->GetCooldown(c) + ".");
  }
  return 1;
}

string GetHelp() {
	return "Syntax:              cooldowns \n"
	       "                     cooldowns <target>\n\n"
	       "Shows cooldowns active on a person.";
}	       