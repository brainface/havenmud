/*
 * News cmd
 *
 * Lauches a user into the news system
 * 
 * Created by Zaxan@Haven 
 * 25-Jul-2004
 *
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

string GetHelp();

mixed cmd(string args)
{
    object who = this_player();
    string group;

  if (who->GetRetired()) return "Sorry, you're retired.";
    if (!args || !creatorp(who))
    {
	NEWSGROUP_D->eventMainMenu(who);
	return 1;
    }
    
    if (sscanf(args, "-r %s", group) == 1)
    {
	NEWSGROUP_D->eventReadGroup(who, group);
	return 1;
    }
    else if (sscanf(args, "-s %s", group) == 1)
    {
	NEWSGROUP_D->eventSettingsMenu(who, group);
	return 1;
    }

    return "Syntax: news ([-r|-s] <group>)";
    
}

string GetHelp()
{
    if (creatorp(this_player()))
    {
	return ("Syntax: news\n"
		"        news -r <group>\n"
		"        news -s <group>\n\n"
		"Allows you to read the news. In the first form, it simply enters you into\n"
		"the news system so you can read your groups and change settings. The second\n"
		"form allows you to immediately start reading the given group. " +
		(sagep(this_player()) ? "The third\nform allows you to change the given "
		 "group's settings as well as your\npersonal settings." : "The third\nform allows you"
		 "to change your personal settings for the given group.")+"\n");
    }
    else
    {
	return ("Syntax: news\n\n"
		"Allows you to read the news and change your newsgroup notification\n"
		"preferences. Be aware that your groups may only be available at\n"
		"certain locations. Post offices will always allow access to the\n"
		"Out of Character Discussion and Haven Announcements groups.\n");
    }
}
