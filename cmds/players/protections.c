//
// The 'protections' cmd
// Lists a player's protections
// Created by Duuk@Haven
// Immortal syntax added by Zaxan@Haven
//

#include <lib.h>
#include <magic_protection.h>

inherit LIB_DAEMON;
inherit LIB_HELP;

mixed cmd(string args) {
  object target;
  string name, pro_type;
  string protect;
  int i;

  if ((creatorp(this_player())) && ((!args) || (args == "")))
  {
    return "You must specify a player to get the protections of.";
  }
  if (creatorp(this_player())) target = find_living(args);
  else target = this_player();
  if (!target) return "No such player.";
  if (creatorp(target)) return "Do you like the taste of lead paint chips?";
  if (!sizeof(target->GetMagicProtection()))  {
    return ""+((target == this_player()) ? "You have " : target->GetName()+" has ")+"no magical protection.";
    }
  this_player()->eventPrint("Magical Protection Summary:");
  i = 1;
  foreach (class MagicProtection pro in target->GetMagicProtection())  {
    pro_type = "";
    if (pro->time)   pro_type = " Time: " + pro->time + " Amount: " + pro->protect;
    if (pro->absorb) pro_type = " Absorption: " + pro->absorb + "";
    protect = sprintf("%d) %-25s %s", i, pro->name, pro_type);
    this_player()->eventPrint(protect);
    i++;
    }
  return 1;
}

string GetHelp()
{
  if (creatorp(this_player()))
    return "Syntax: <protections player>\n\n"
           "Display magical protections currently applied to <player>.\n";

  return "Syntax: <protections>\n\n"
         "Display magical protections currently applied to you.\n";
}
