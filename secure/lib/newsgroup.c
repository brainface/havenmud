/*
 * Newsgroup object
 *
 * Created by NEWS_D for each instance of
 * a newsgroup.
 * 
 * Created by Zaxan@Haven
 * 24-Jul-2004
 */

#include <lib.h>
#include <dirs.h>
#include <daemons.h>
#include <commands.h>

#include "include/newsgroup.h"

inherit LIB_DAEMON;

private string	    __GroupId			= "";
private string	    __RaceRestriction		= "";
private string	    __TownRestriction		= "";
private string	    __GuildRestriction		= "";
private string	    __ClassRestriction		= "";
private string	    __ReligionRestriction	= "";
private string      __FriendlyName              = "New Newsgroup";
private int	    __ReadRankRestriction	= 2; // Start out angel+ only
private int	    __PostRankRestriction	= 2; // Start out angel+ only
private mapping	   *__Posts			= ({ });

private void create(string GroupId)
{
    daemon::create();

    if (base_name(previous_object()) != NEWSGROUP_D &&
	    base_name(previous_object()) != CMD_UPDATE)
    {
	CHAT_D->eventSendChannel("Newsgroups ("+GroupId+")", "error",
		"Unauthorized newsgroup creation. Previous objects = "+
		print_previous_objects());
	error("Unauthorized newsgroup creation. Previous objects = "+
		print_previous_objects());
	Destruct();
	return;
    }

    if (!GroupId) return;

    __GroupId = GroupId;

    if (unguarded( (: file_size(DIR_NEWSGROUPS + "/" + __GroupId + __SAVE_EXTENSION__) :) ) > 0)
    {
	unguarded( (: restore_object, DIR_NEWSGROUPS + "/" + __GroupId + __SAVE_EXTENSION__ :));
    }

}

nomask void save_newsgroup()
{
    if (!__GroupId) return;

    unguarded( (: save_object, DIR_NEWSGROUPS + "/" + __GroupId + __SAVE_EXTENSION__ :));    
}

nomask int eventDestruct()
{
    if (!securep(this_player()))
    {
	return 0;
    }
    else return Destruct();
}

private string print_previous_objects()
{
    string str = "({ ";
    string *strobj = ({ });
    object *prevobj = all_previous_objects();

    foreach(object obj in prevobj)
    {
	strobj += ({ base_name(obj) });
    }

    str += implode(strobj, ", ") + " })";

    return str;
}

private int check_security()
{
    if (base_name(previous_object()) != NEWSGROUP_D)
    {
	CHAT_D->eventSendChannel("Newsgroups ("+__GroupId+")", "error",
		"Unauthorized newsgroup operation. Previous objects = "+
		print_previous_objects());
	error("Unauthorized newsgroup operation. Previous objects = "+
		print_previous_objects());
	return 0;
    }

    return 1;
}

private int check_master_access()
{
    object who = this_player();
    
    if (!who) return 0;
    
    if (creatorp(who)) return 1;
    
    if (__RaceRestriction != "" && who->GetRace() &&
	    lower_case(who->GetRace()) != lower_case(__RaceRestriction))
	return 0;

    if (__TownRestriction != "" && who->GetTown() &&
	    lower_case(who->GetTown()) != lower_case(__TownRestriction))
	return 0;

    if (__GuildRestriction != "" && who->GetGuild() &&
	    lower_case(who->GetGuild()) != lower_case(__GuildRestriction))
	return 0;

    if (__ClassRestriction != "" && who->GetClass() &&
	    lower_case(who->GetClass()) != lower_case(__ClassRestriction))
	return 0;

    if (__ReligionRestriction != "" && who->GetReligion() &&
	    lower_case(who->GetReligion()) != lower_case(__ReligionRestriction))
	return 0;
    
    return 1;
}

nomask int check_post_access()
{
    object who = this_player();

    if (!who) return 0;

    if (rank(who) < __PostRankRestriction)
	return 0;

    return check_master_access();
}

nomask int check_read_access()
{
    object who = this_player();

    if (!who) return 0;

    if (rank(who) < __ReadRankRestriction)
	return 0;

    return check_master_access();
}

string GetGroupId()
{
    return __GroupId;
}

string SetRaceRestriction(string race)
{
    if (!check_security()) return __RaceRestriction;

    __RaceRestriction = race;
    save_newsgroup();
    return __RaceRestriction;
}

string GetRaceRestriction() { return __RaceRestriction; }

string SetTownRestriction(string town)
{
    if (!check_security()) return __TownRestriction;

    __TownRestriction = town;
    save_newsgroup();
    return __TownRestriction;
}

string GetTownRestriction() { return __TownRestriction; }

string SetGuildRestriction(string guild)
{
    if (!check_security()) return __GuildRestriction;

    __GuildRestriction = guild;
    save_newsgroup();
    return __GuildRestriction;
}

string GetGuildRestriction() { return __GuildRestriction; }

string SetClassRestriction(string cl)
{
    if (!check_security()) return __ClassRestriction;

    __ClassRestriction = cl;
    save_newsgroup();
    return __ClassRestriction;
}

string GetClassRestriction() { return __ClassRestriction; }

string SetReligionRestriction(string religion)
{
    if (!check_security()) return __ReligionRestriction;

    __ReligionRestriction = religion;
    save_newsgroup();
    return __ReligionRestriction;
}

string GetReligionRestriction() { return __ReligionRestriction; }

string SetFriendlyName(string name)
{
    if (!check_security()) return __FriendlyName;

    __FriendlyName = name;
    save_newsgroup();
    return __FriendlyName;
}

string GetFriendlyName() { return __FriendlyName; }

int SetReadRankRestriction(int rank)
{
    if (!check_security() || rank < 0) return __ReadRankRestriction;

    if (!check_post_access()) return 0;

    __ReadRankRestriction = rank;
    save_newsgroup();
    return __ReadRankRestriction;
}

int GetReadRankRestriction() { return __ReadRankRestriction; }

int SetPostRankRestriction(int rank)
{
    if (!check_security() || rank < 0) return __PostRankRestriction;

    if (!check_post_access()) return 0;

    __PostRankRestriction = rank;
    save_newsgroup();
    return __PostRankRestriction;
}

int GetPostRankRestriction() { return __PostRankRestriction; }

int AddPost(string author, string subject, string post)
{
    if (!check_security()) return 0;

    if (!check_post_access()) return 0;

    __Posts += ({ ([ "author" : author, "post" : post, "subject" : subject,
		     "time" : time(), "read" : ({ author }) ]) });

    save_newsgroup();
    
    return 1;
}

string GetPostText(string reader, int postnum)
{
    string txt = "";
    mapping post;
    
    if (!check_security()) return 0;
   
    if (!check_read_access()) return 0;

    if (postnum < 0 || postnum >= sizeof(__Posts)) return 0;

    post = __Posts[postnum];

    txt += "Post #%^YELLOW%^"+ (postnum+1) + "%^RESET%^ by %^YELLOW%^" +
	    capitalize(post["author"]) + "%^RESET%^\n";
    txt += "Subject: %^CYAN%^"+ post["subject"] + "%^RESET%^\n\n";
    txt += post["post"]+"\n"; 

    if (member_array(reader, __Posts[postnum]["read"]) == -1)
    {
	__Posts[postnum]["read"] += ({ reader });
	save_newsgroup();
    }

    return txt;
}

mapping GetPost(int postnum)
{
    if (!check_security()) return 0;
    
    if (!check_read_access()) return 0;

    if (postnum < 0 || postnum >= sizeof(__Posts)) return 0;

    return __Posts[postnum];
}

mapping *GetPosts()
{
    if (!check_security()) return 0;

    if (!check_read_access()) return 0;
    
    return __Posts;
}

int RemovePost(int postnum)
{
    if (!check_security()) return 0;
   
    if (!check_post_access()) return 0;

    if (postnum < 0 || postnum >= sizeof(__Posts)) return -1;

    if (postnum == 0)
    {
	__Posts = __Posts[1..];
    }
    else if (postnum == sizeof(__Posts)-1)
    {
	__Posts = __Posts[0..<2];
    }
    else
    {
	__Posts = __Posts[0..(postnum-1)] + __Posts[(postnum+1)..];
    }

    save_newsgroup();

    return 1;
}

int UserHasUnreadPosts(string username)
{
    if (!check_security()) return 0;

    foreach(mapping post in __Posts)
    {
	if (member_array(username, post["read"]) == -1)
	{
	    return 1;
	}
    }

    return 0;
}