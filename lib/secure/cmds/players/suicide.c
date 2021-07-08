/*  /secure/cmds/player/suicide.c
 *  from the Nightmare IVr2 Object Library
 *  Allows players to obliterate their character
 *  created by Blitz@Nightmare
 */

#include <lib.h>
#include <daemons.h>
#include <dirs.h>
#include <flags.h>
#include <privs.h>
#include <message_class.h>
#include <daemons.h>

inherit LIB_DAEMON;

static private void GetPassword(string input);
static private void GetYesOrNo(string input);
static private void EndSuicide(string who);

mixed cmd(string str) {
  string who;
  string jeremy;
  object ob;

  if( sizeof(str) ) return "Suicide does not require any arguments.";
  ob = previous_object();
  if( this_player(1) != ob || !userp(ob) ) {
    log_file("security", "** Illegal suicide attempt **\n "
             "Call stack:\n"+ sprintf("%O\n", previous_object(-1)));
    return "Suicide failed.";
  }
  if (creatorp(ob)) {
    CHAT_D->eventSendChannel("Suicide Attempt", "reports",
       capitalize(this_player()->GetKeyName()) + " attempted to end " +
       possessive(this_player()) + " own life!");
    log_file("security", "** Suicide Attempt : " +
        ob->GetKeyName() + " -- " + ctime(time()) + "\n" );
    return "Only mortals may suicide!";
   }
  if( this_player()->GetForced() ) {
    log_file("security", "*** Illegal \"Forced\" Suicide **\n"
             "Call stack:\n"+ sprintf("%O\n", previous_object(-1)));
    return 0;
  }
  who = (string)this_player()->GetKeyName();
  jeremy = (string)this_player()->GetOOCName();
  if (jeremy == "Jeremy Ritter") {
    this_player()->eventPrint("Who ARE you, Jeremy Ritter? Why do you log in twice a "
    "month to suicide a character after 12 seconds? Are you part of the "
    "internet gaining sentience and trying to break into the real world "
    "but you've accidently into a mud? Are you trying to scam a mud, "
    "because we don't have any money! We don't know, please tell us.\n"
    "But most of all, please stop dying on us!\n"
    "Say 'ooc blahblahblah' and tell us because we've been asking each "
    "other what the deal is for about 2 years. More?\n");
    return 0;
  }
  if (!who) return;
  if( who == "guest" ) return "Guest is not suicidal!";
  if( member_group(who, PRIV_SECURE) || member_group(who, PRIV_ASSIST) )
    return "You must first have your security privledges removed.";

  this_player()->eventPrint("Committing suicide means having your character "
           "completely erased from "+mud_name()+"'s database.  If you "
           "are certain this is what you want, enter in your correct "
           "password.  Otherwise enter in a wrong password.");
  this_player()->eventPrint("Password: ", MSG_EDIT);
  input_to((: GetPassword :), I_NOECHO | I_NOESC);
  return 1;
}

static private void GetPassword(string input) {
  string tmp;
  if( !sizeof(input) ) {
    this_player()->eventPrint("Suicide aborted.");
    return;
  }
  tmp = (string)this_player()->GetPassword();
  if( tmp != crypt(input, tmp) ) {
    this_player()->eventPrint("Wrong password.  Suicide aborted.");
    return;
  }
  EndSuicide(this_player()->GetKeyName());
  return;
}

static private void EndSuicide(string who) {
  string tmp, file, newfile;
  object *ob;

  log_file("players/suicide", who+" suicided at "+ctime(time()) + ". (from " + query_ip_name(this_player())+")\n");
  tmp = save_file(who) + __SAVE_EXTENSION__;
  message("system", "You have suicided.  Please try again!", this_player() );
  this_player()->eventDestruct();
  unguarded( (: rm, tmp :) );
  PLAYERS_D->RemovePlayer(who);
  CHAT_D->eventSendChannel("suicide", "notify",    capitalize(who) + " has suicided.  Icky.", 1);
  CHAT_D->eventSendChannel("suicide", "allnotify", capitalize(who) + " has committed suicide. Icky.", 1);
  return;
}

string GetHelp(string str) {
    return "Syntax: suicide\n\n"
      "Ends your character's existence on "+mud_name()+" FOREVER.  "
      "It is non-reversible.  Once you issue this command, you will be asked"
      "for a password to confirm your identity.  Once password is confirmed, "
      "you will no longer exist in the MUD's database.  \n\n"
      "NOTE: If you suicide from a restricted site, you will have to "
      "reregister!";
}

