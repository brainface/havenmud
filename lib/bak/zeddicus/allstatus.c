#include <lib.h>

inherit LIB_DAEMON;

int sort(object alpha, object beta);

mixed cmd(string args)
{
  object *people = filter(users(), (: playerp :));
  people = people - filter(people, (: base_name($1) == LIB_CONNECT :));
  people = sort_array(people, (: sort :));

  message("info", "%^GREEN%^" + 
    sprintf("%-12s  %-10s  %-10s  %-10s  %-7s  %-8s  %-10s",
    "Name:",
    "Health:",
    "Magic:",
    "Stamina:",
    "Life:",
    "Sleep:",
    "Combat:%^RESET%^",this_player()),this_player());

  foreach(object who in people) {
    message("info",
    sprintf("%-12s  %-10s  %-10s  %-10s  %-7s  %-8s  %-10s",
    who->GetCapName(),
    who->GetHealthPoints() + "/" + who->GetMaxHealthPoints(),
    who->GetMagicPoints() + "/" + who->GetMaxMagicPoints(),
    who->GetStaminaPoints() + "/" + to_int(who->GetMaxStaminaPoints()),
    ( (who->GetUndead()) ? "Dead" : "Alive" ),
    ((who->GetSleeping()) ? "Yes (" + who->GetSleeping() + ")" : "No"),
    ( (who->GetInCombat()) ? "Yes" : "No" ),
    this_player()),this_player());
  }
  return 1;
}

string GetHelp(string foo)
{
  return "Syntax: <allstatus>\n\n"
         "Lists all of the players on the mud, including their "
         "health, magic, stamina, alive, sleeping, and in combat.";
}

int sort(object alpha, object beta)
{
  int x = beta->GetLevel() - alpha->GetLevel();
  if (x) return x;
  return strcmp(alpha->GetCapName(), beta->GetCapName());
}

