/*    /verbs/players/say.c
 *    from the Dead Soulsr2 Object Library
 *    say
 *    say STR
 *    say in WRD STR
 */

#pragma save_binary

#include <lib.h>
#include <talk_type.h>
#include "include/say.h"

inherit LIB_DAEMON;

static void create() {
    daemon::create();
    SetNoClean(1);
    parse_init();
    parse_add_rule("say", "");
    parse_add_rule("say", "in WRD");
    parse_add_rule("say", "in WRD STR");
    parse_add_rule("say", "STR");
}

mixed can_say() { return "Speak what? In what language?"; }

mixed can_say_in_wrd(string str) {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    if( str ) return "What do you wish to say?";
    else return 0;
}

mixed can_say_str(string str) {
    string lang;
    if( !str ) return 0;
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    lang = (string)this_player()->GetNativeLanguage() || "common";
    return (mixed)this_player()->CanSpeak(0, TALK_LOCAL, str, lang);
}

mixed can_say_in_wrd_str(string lang, string str) {
    if( !lang || !str ) return 0;
    if( !environment(this_player()) ) return "You are nowhere right now.";
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    return (mixed)this_player()->CanSpeak(0, TALK_LOCAL, str, lang);
}

mixed do_say() { return 1; }

mixed do_say_in_wrd(string str) { return 1; }

mixed do_say_str(string str) {
    string nativelang;
    string defaultlang;
    nativelang = (string)this_player()->GetNativeLanguage() || "common";
    if (defaultlang = this_player()->GetProperty("defaultlanguage"))
        return do_say_in_wrd_str(defaultlang, str);
    return do_say_in_wrd_str(nativelang, str);
}

mixed do_say_in_wrd_str(string lang, string str) {
    if( str[<1] != '.' && str[<1] != '?' && str[<1] != '!' )
      str = capitalize(str) + ".";
    else str = capitalize(str);
    return (mixed)this_player()->eventSpeak(0, TALK_LOCAL, str, lang);
}


string GetHelp(string str) {
    return ("Syntax: <say MESSAGE>\n"
            "        <say in LANGUAGE MESSAGE>\n\n"
            "Sends the message you specify to all people in the same room "
            "as you.  If you are an avatar, you have the ability to customize "
            "the way these messages come out through the \"message\" "
            "command.  If you fail to specify a language, your native "
            "language will be used.\n\n"
            "See also: message, say, shout, say, tell");
}

