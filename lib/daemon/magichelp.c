/*    /verbs/common/help.c
 *    from the Nightmare IVr2 Object Library
 *    created by Descartes of Borg 951021
 *    Version: @(#) help.c 1.11@(#)
 *    Last Modified: 96/11/01
 */

#include <lib.h>
#include <dirs.h>
#include <daemons.h>

inherit LIB_DAEMON;

static private string Error;
static private mapping Indices;

static private void LoadIndices();
string GetHelp(string str);
string GetHelpByIndex(string index, string topic);
string GetTopic(string index, string topic);
varargs string array GetIndices(string topic);

static void create() {
    daemon::create();
    SetNoClean(1);
    Error = 0;
    LoadIndices();
}

int CanAccess(object who, string index) {
    return 1;
}
    
static private void LoadIndices() {
    string array tmp, tmp_spells;
    string dir;
    
    Indices = ([]);


  tmp_spells = ({ });
  foreach(string spell_type in get_dir(DIR_SPELLS "/")) {
    if (spell_type == "test_spells") continue;
    if (spell_type == "include") continue;
    if (spell_type == "obj") continue;
   Indices[spell_type] = ({ });
   tmp_spells = get_dir(DIR_SPELLS + "/" + spell_type + "/*.c");
   if (sizeof(tmp_spells)) {
      foreach(string file in tmp_spells) {
          file = DIR_SPELLS + "/" + spell_type + "/" + file;
          Indices[spell_type] += ({ file->GetSpell() });
        }
      }
   }

}

string GetHelp(string str) {
    string *tmp;
    string topic;
    int x;
    
    Error = 0;
    if( !str || str == "" || str == "help" ) {
	return ("Syntax: <spellhelp>\n"
		"        <spellhelp index>\n"
		"        <spellhelp TOPIC>\n"
		"        <spellhelp INDEX TOPIC>\n\n"
		"Without an argument, you get this spellhelp screen.  The same "
		"applies for trying to get help on the help command.  With "
		"an argument, you are given information on the topic you "
		"specified.  The special topic, \"help index\", puts you into "
		"a menu driven index of categories for which help exists.  In "
		"some cases, the same help topic will exist in two separate "
		"categories.  If help tells you that you have asked for "
		"help on such a topic, you may specify the index from which "
		"it comes by using the index name help gives you.  For "
		"example:\n"
		"> help list\n"
		"There exists help for \"list\" in the following indices:\n"
		"commands, channels\n"
		">\n"
		"You could then type \"help player commands list\" to get "
		"the help for the list player command.\n\n"
		"In general, most commands have only a single index, so there "
		"is generally no need to specify the index.\n"
		"Finally, to help you better understand how to issue commands "
		"on Haven, you should check out the document "
		"\"help syntax\".\n\n"
		"See also: faq, index, syntax");
    }
    tmp = GetIndices(str);
    if( sizeof(tmp) == 1 ) {
	return GetHelpByIndex(tmp[0], str);
    }
    else if( sizeof(tmp) > 1 ) {
	Error = "There exists help for \"" + str + "\" under the following "
	    "indices:\n" + implode(tmp, ", ");
	return 0;
    }
    topic = "";
    str = trim(str);
    while( (x = strsrch(str, " ")) != -1 ) {
	if( topic != "" ) {
	    topic = topic + " " + str[0..(x-1)];
	}
	else {
	    topic = str[0..(x-1)];
	}
	str = str[(x+1)..];
	if( Indices[topic] && strlen(str) ) {
	    return GetHelpByIndex(topic, str);
	}
    }
    Error = "Help for the topic \"" + str + "\" could not be found.";
    return 0;
}

string GetHelpByIndex(string index, string topic) {
    string spell, spell_dir;
    object ob;
    string help, file, tmpstr;

    if( this_player() && !CanAccess(this_player(), index) ) {
	Error = "You do not have access to that information.";
	return 0;
    }
	ob = SPELLS_D->GetSpell(topic);
	if( !ob ) {
	    Error = "No such spell exists.";
	    return 0;
	}
	if( !(help = ob->GetHelp(topic)) ) {
	    Error = "No help is available for that spell.";
	    return 0;
	}
       sscanf(base_name(ob), "/std/spells/%s/%s/", spell_dir, spell);
	help = "Index: %^GREEN%^" + spell_dir + "%^RESET%^\n" +
	    "Topic: %^GREEN%^" + topic + "%^RESET%^\n\n" + help;
	return help;
}

varargs string array GetIndices(string topic) {
    string array topics, val;
    string ind, tmp;

    if( !topic ) {
	return sort_array(keys(Indices), 1);
    }
    topics = ({});
    foreach(ind, val in Indices) {
	if( !CanAccess(this_player(), ind) ) {
	    continue;
	}
	tmp = GetTopic(ind, topic);
	if( member_array(tmp, val) != -1 ) {
	    topics += ({ ind });
	}
    }
    return sort_array(topics, 1);
}

string GetTopic(string index, string topic) {
	return topic;
}

string array GetTopics(string index) {
    string array topics = Indices[index];

    if( !topics ) {
	return 0;
    }
    else {
	return sort_array(topics, 1);
    }
}

string GetLastError() {
    return Error;
}

void Reload() {
    LoadIndices();
}
