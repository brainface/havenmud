#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string str)
{
  object healer = this_player();
  object healed;

  if (angelp(healer)) return "Practicing medicine without a license? Tsk tsk.";
  if (!str) return "Arguments?  That might help.  Yeah, maybe.";
  if (!healed = find_player(str)) return "No such player.";
  if (!playerp(healed)) return "That person's wounds run far too deep to ever "
    "have any hope of being healed.";

  healed->NewBody(healed->GetRace());
  healed->eventCompleteHeal(5000);
  healed->SetUndead(0);
  healed->SetParalyzed(0);
  healed->SetSleeping(0);
  healed->AddFood(200);
  healed->AddDrink(200);
  healed->AddPoison(-(healed->GetPoison()));
  healed->AddRecoveryTime(-(healed->GetRecoveryTime()));
  if (healed->GetBlind()) healed->RemoveBlindness();
  foreach(object ob in all_inventory(healed)) {
    if (ob->GetProperty("germ")) ob->eventDestruct();
    }
  healed->eventPrint("You have been healed by the touch of an immortal.");
  healer->eventPrint("Ok.");
  if (!healed->GetTestChar() && !archp(this_player()))
  {
  unguarded( (: log_file, "wizheal", capitalize(healer->GetKeyName()) + " wizhealed " +
                capitalize(healed->GetKeyName()) + " at " + ctime(time()) + ".\n" :) );
  }
  return 1;
}

string GetHelp(string arg)
{
    return "Syntax: wizheal <player>\n\n"
    "Wizheals a player, which will return them to life, "
    "as well as full hp, mp, sp. This command can be "
    "freely used on registered test characters (see tc command ) "
    "but should NOT be used on regular mortals unless their "
    "injury or death was caused by a mud issue, such as a bug. "
    "Deaths due to link death or their own stupidity are their own "
    "problem. If you are unsure about a wizheal being justified, "
    "you can consult with an Assist+ when they arrive. "
    "If the mortal died while performing an action you requested "
    "of them (such as demonstrating a bug for you) then that is "
    "also a reasonable circumstance in which to wizheal them.";
}
