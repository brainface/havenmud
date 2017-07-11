/*  The ldsmack Imm+ emote */
#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

mixed cmd(string name) {
  object who, target;
  who = this_player();
  if (!name) { return "Idiot."; }
  target = find_player(name);

  if (!target) return "No such target.";
  if (target->GetInvis() > rank(who)) return "No such target.";
  if (who == target) return "Smack yourself?";
  if (in_edit(target)) return "That person is in edit!";
  if (playerp(target)) {
    if (target->GetEmail() != "bjorn.brown@yahoo.com")
      return "That person is a player!";
  }
  if (rank(target) > rank(who) && !(target->GetRetired())) 
    return "That person is higher rank than you!";
  CHAT_D->eventSendChannel("SMACK!", "ooc",
    capitalize(who->GetKeyName()) + " smacks " + 
    capitalize(target->GetKeyName()) + " into linkdeath.", 0);
    target->eventDestruct();
  return 1;
 }

string GetHelp(string blah) {
  return "Smacks a target into linkdeath.";
 }
