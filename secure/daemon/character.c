/*    /secure/daemon/character.c
 *    from the Dead Souls V Object Library
 *    the multi-character management daemon
 *    created by Descartes of Borg 951216
 */

#include <lib.h>
#include <save.h>
#include <privs.h>
#include <link.h>
#include <config.h>
#include <daemons.h>
#include "include/character.h"

inherit LIB_DAEMON;

private mapping Links;
private string *AdvancedStart;

static void create() {
    daemon::create();
    SetNoClean(1);
    Links = ([]);
    AdvancedStart = ({ });
    if( unguarded( (: file_size(SAVE_CHARACTER __SAVE_EXTENSION__) :)) > 0 )
      unguarded((: restore_object, SAVE_CHARACTER :));
    CleanLinks();
}

string *ResetAdvancedStart() {
  AdvancedStart = ({ });
  unguarded( (: save_object, SAVE_CHARACTER :) );  
}

string *AddAdvancedStart(string who) {
  string *tmp = AdvancedStart + ({ who });
  if (member_array(who, AdvancedStart) == -1) {
    CHAT_D->eventSendChannel("Advanced", "reports", "Advanced Start enabled for " + who);
  }
  AdvancedStart = distinct_array(tmp);
  unguarded( (: save_object, SAVE_CHARACTER :) );
  return AdvancedStart;
}

string *GetAdvancedStart() { return AdvancedStart; }

int CanAdvancedStart(string who) {
  if (member_array(who, AdvancedStart) != -1) return 1;
  return 0;
}

varargs mixed eventConnect(string email, string name, string login) { 
    class char_link c;
    string *chars;
    if (!c = Links[email]) {
      return 1;
    }
    chars = c->Characters;
    foreach(string chr in chars) {
    	//debug("character: " + chr);
      if (immortal_exists(chr)) { /* debug("immortal: " + chr); */ return 1; }
      }
    foreach(string chr in chars) {
      if (find_player(chr) && chr != login)
        if (interactive(find_player(chr))) return 0;
    }
    return 1;
}
	
mixed eventLink(string email, string character) {
  class char_link c;
  if (!c = Links[email]) {
    c = new(class char_link);
    c->Email = email;
    c->Characters = ({ });
    c->LastOnWith = 0;
    c->LastOnDate = 0;
    Links[email]  = c;
  }
  c->LastOnWith = character;
  c->LastOnDate = time();
  c->Characters = distinct_array(c->Characters + ({ character }) );
  unguarded( (: save_object, SAVE_CHARACTER :) );
  return 1;
}

mixed eventSaveTime() {
  return 1;
}

mixed eventUnlink(string email, string character) {
  class char_link c;
  if (!c = Links[email]) return -1;
  c->Characters -= ({ character });
  Links[email] = c;
  unguarded( (: save_object, SAVE_CHARACTER :) );
  return 1;
}

mapping GetLinks() {
    if( !((int)master()->valid_apply(({ PRIV_ASSIST }))) ) return ([]);
    else return Links;
}

mapping GetLink(string email) {
    class char_link ch;

    if( Links[email] ) ch = Links[email];
  	if( !ch ) return ([ ]);
    return ([ "email" : email, "last char" : ch->LastOnWith,
	   "characters" : ch->Characters, "last on" : ch->LastOnDate ]);
}

string *GetEmails() {
  return keys(Links);
}

void CleanLinks() {
  class char_link c;
  string *emails = GetEmails();
  
  foreach(string email in emails) {
    c = Links[email];
    foreach(string person in c->Characters) {
      if (!user_exists(person)) c->Characters -= ({ person });
      }
    if (!sizeof(c->Characters)) map_delete(Links, email);
  }
  unguarded( (: save_object, SAVE_CHARACTER :) );
}
  
string GetPastableEmails() {
	return implode(keys(Links), "; ");
}