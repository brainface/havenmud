/*    /cmds/common/help.c
 *    from the Nightmare IV Object Library
 *    created by Descartes of Borg 951021
 *    Version: @(#) help.c 1.2@(#)
 *    Last Modified: 96/10/21
 */

#include <lib.h>
#include <daemons.h>
#include <message_class.h>

inherit LIB_DAEMON;

varargs void HelpMenu(string index);

mixed cmd(string arg) {
    object who = previous_object();
    int array screen = (who->GetScreen() || ({ 80, 24 }));
    string help;
    
    if( !arg ) arg = "index";
    if( arg == "index" || SPELL_HELP_D->GetTopics(arg) ) {
	if( arg == "index" ) {
	    HelpMenu();
	    return 1;
	}
	HelpMenu(arg);
	return 1;
    }
    if( !(help = SPELL_HELP_D->GetHelp(arg)) ) {
	return SPELL_HELP_D->GetLastError();
    }
    help = center("Haven Spell Help System", screen[0]) + help;
    help = wrap(help, screen[0]);
    who->eventPage(explode(help, "\n"), MSG_HELP);
    return 1;
}

static int CanAccess(object who, string index) {
    return SPELL_HELP_D->CanAccess(who, index);
}

varargs void HelpMenu(string index) {
    function f;
    string tmp;
    string array indices;
    int array scr;

    scr = this_player()->GetScreen() || ({ 80, 25 });
    tmp = center("Haven Spell Help System", scr[0]);
    if( !index ) {
	tmp += "Index: %^GREEN%^main index%^RESET%^\n\n";
	indices = filter(SPELL_HELP_D->GetIndices(),
			 (: CanAccess(this_player(), $1) :));
	tmp += format_page(map(indices, function(string str, string array ind) {
	    int num = member_array(str, ind) + 1;
	    return ("[%^CYAN%^"+(num)+"%^RESET%^] " + str);
	}, indices), 3);
    }
    else if( !SPELL_HELP_D->CanAccess(this_player(), index) ) {
	message("help", "Invalid index choice.", this_player());
	message("prompt", "Hit <return>: ", this_player());
	input_to(function(string str) { HelpMenu(0); });
	return;
    }
    else {
	string array topics = SPELL_HELP_D->GetTopics(index);
	string array bing = allocate(sizeof(topics));
	int i = 0;

	tmp += "Index: %^GREEN%^" + index + "%^RESET%^\n\n";
	foreach(string topic in topics) {
	    bing[i++] = "[%^CYAN%^" + (i+1) + "%^RESET%^] " + topic;
	}
	tmp += format_page(bing);
    }
    f = function(string ind) {
	if( !ind )
	    message("prompt", "\n\nEnter a index or 'q' to quit help: ",
		    this_player());
	else
	    message("prompt", "\n\nEnter a topic, 'q' to quit help, or "
		    "<return> for main menu: ", this_player());
	input_to(function(string str, string ind) {
	    string ret;
	    int ind_num;
	    int *scr;
	    
	    if( str == "q" ) {
		message("system", "Exiting help.", this_player());
		return;
	    }
	    if( !str || str == "" ) {
		HelpMenu(0);
		return;
	    }
	    scr = (int *)this_player()->GetScreen() || ({ 80 });
	    if( ind_num = to_int(str) ) {
		string array tmp2;
		if( !ind ) tmp2 = filter(SPELL_HELP_D->GetIndices(),
					 (: CanAccess(this_player(), $1) :));
		else tmp2 = SPELL_HELP_D->GetTopics(ind);    
		if( ind_num < 1 || ind_num > sizeof(tmp2) ) {
		    str = 0;
		    SPELL_HELP_D->SetError("Index number out of range.");
		}
		else str = tmp2[ind_num - 1];
	    }
	    if( !ind && !SPELL_HELP_D->GetTopics(str) ) {
		message("help", "Invalid index choice.", this_player());
		message("prompt", "Hit <return>: ", this_player());
		input_to(function(string str) { HelpMenu(); });
		return;
	    }
	    else if( !ind ) {
		HelpMenu(str);
		return;
	    }
	    if( !(ret = SPELL_HELP_D->GetHelpByIndex(ind, str)) ) {
		message("help", SPELL_HELP_D->GetLastError(), this_player());
		message("prompt", "\nHit <return>: ", this_player());
		input_to(function(string str) { HelpMenu(); });
		return;
	    }
	    ret = center("Haven Spell Help System", scr[0])+wrap(ret, scr[0]);
	    this_player()->eventPage(explode(ret, "\n"), "help",
				     function(string ind) {
		message("prompt", "\n\nHit <return>: ",
                        this_player());
		input_to(function(string str, string ind) {
                    HelpMenu(ind); }, ind);
		return;
	    }, ind);
	}, ind);
    };
    this_player()->eventPage(explode(tmp, "\n"), "help", f, index);
}

string GetHelp(string blah) {
    return "Syntax: <spellhelp>\n"
           "        <spellhelp [spell]>\n\n"
           "Used without argument this command will put you "
           "into Haven's spellhelp database, which works in a "
           "similar manner to the main help index. Used with the "
           "name of a song this command will show you the help "
           "information for that specific spell.\n\n"
           "See also: help, songhelp";
}
