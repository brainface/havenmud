/*    /verbs/common/yell.c
 *    from the Dead Souls  Object Library
 *    yell
 *    yell in WRD STR
 *    yell STR
 *    created by Descartes of Borg 951119
 */

#pragma save_binary

#include <lib.h>
#include <talk_type.h>
#include "include/yell.h"

inherit LIB_VERB;

static void create() {
	::create();
	SetVerb("yell");
	SetSynonyms(({"shout"}));
	SetRules("", "in WRD STR", "STR");
	SetHelp("This command allows you to bellow out a phrase.  "
	        "It will carry in all directions.");
}
	      

mixed can_yell() { return "Yell what?"; }

mixed can_yell_str(string str) {
    string lang;

   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    if( !str ) return 0;
    lang = (string)this_player()->GetNativeLanguage() || "english";
    return can_yell_in_wrd_str(lang, str);
}

mixed can_yell_in_wrd_str(string lang, string str) {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    if( !lang || !str ) return 0;
    return (mixed)this_player()->CanSpeak(0, TALK_AREA, str, lang);
}

mixed do_yell() { return 1; }

mixed do_yell_str(string str) {
    string lang;

    lang = (string)this_player()->GetNativeLanguage() || "english";
    return do_yell_in_wrd_str(lang, str);
}

mixed do_yell_in_wrd_str(string lang, string str) {
    if( str[<1] != '!' && str[<1] != '?' && str[<1] != '.' )
      str = capitalize(str) + ".";
    else str = capitalize(str);
    return (mixed)this_player()->eventSpeak(0, TALK_AREA, str, lang);
}

string GetHelp(string str) {
    return ("Syntax: <yell MESSAGE>\n"
	    "        <yell in LANGUAGE MESSAGE>\n\n"
	    "Sends a message to the area around you.  If you fail to "
	    "specify a language, your native language is used.\n\n"
	    "See also: reply, say, shout, speak, tell, whisper");
}
