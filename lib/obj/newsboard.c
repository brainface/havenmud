/*
 * The object that tells players they can use
 * 'news' here.
 *
 * Created by Zaxan@Haven
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_ITEM;

void create()
{
    item::create();
    SetPreventGet("You cannot get that!");
    SetPreventPut("You cannot put that in there!");
    SetShort("a large news board");
    SetKeyName("newsboard");
    SetId( ({ "board" }) );
    SetAdjectives( ({ "news", "large" }) );
}

string GetExternalDesc()
{
    string desc = "";
    string *roomgroups = environment(this_player())->GetNewsgroups();
    string *allowed = NEWSGROUP_D->GetAllowedGroupList(this_player());
    string *list = ({ });

    foreach (string rgroup in roomgroups)
    {
	if (member_array(rgroup, allowed) != -1)
	{
	    object grp = NEWSGROUP_D->GetGroup(rgroup);
	    list += ({ grp->GetFriendlyName() });
	}
    }

    if (sizeof(list))
    {
	int onlyone = (sizeof(list) == 1);

	desc = "Use the 'news' command to access this board. The "
	    "topic"+(onlyone ? "" : "s")+" "
	    "available at this location "+
	    (onlyone ? "is" : "are")+" "+item_list(list)+".";
    }
    else
    {
	desc = "There is nothing of importance to you on this board.";
    }

    return desc;
}
