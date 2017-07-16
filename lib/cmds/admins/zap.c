/*  A new command to kill a living.
 *  Duuktsaryth
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string str)
{
  object who = this_player();
  object target;

  if (!str)
  {
    return "Kill whom?";
  }
  if (!(target = find_living(str)))
  {
    return "Unable to find that person.";
  }
  /*
  if(creatorp(target))
  {
      return "Duuktsaryth stays your hand.";
  }
  */

  if (creatorp(target) && !archp(this_player()))
  {
    return "Send an Immortal to hell?";
  }

  if(userp(target))
  message("system", "%^YELLOW%^" +
      capitalize(who->GetKeyName()) + " looks down on Kailie in anger. \n" +
    "Finding " + "%^RED%^" + capitalize(target->GetKeyName()) + " %^YELLOW%^" +
     nominative(who) + " waves " + possessive(who) + " hand in an arc, " +
     "causing flames to reach out, aiming for the foul creature.  As the "
     "flames strike %^RED%^" + capitalize(target->GetKeyName()) +
      "%^YELLOW%^" +
     " they incinerate " + possessive(target) + " corpse. %^RESET%^", users() );
    target->eventDie(this_player());
  return 1;
  }

string GetHelp(string blah) {
    return "Syntax: <zap [player]>\n\n"
           "This command is used to vent the wrath of the gods "
           "upon a mortal. It send a message of the event to all "
           "players on the mud, and makes the targeted player dead. "
           "Used at the final level in-mud level of punishment, before "
           "rid and ban are considered.\n\n"
           "See also: channel, damn, rid, viking";
}