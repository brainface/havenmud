#include <damage_types.h>
#include <lib.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  object who;
  object tp = this_player();

  if (!args) return "Show resistances for who?";
  if (!who = find_player(args)) return "Can't find \"" + args + "\"."; 
  tp->eventPrint("BLUNT       : " + who->GetResistance(BLUNT       ) );
  tp->eventPrint("SLASH       : " + who->GetResistance(SLASH       ) );
  tp->eventPrint("PIERCE      : " + who->GetResistance(PIERCE      ) );
  tp->eventPrint("WATER       : " + who->GetResistance(WATER       ) );
  tp->eventPrint("SHOCK       : " + who->GetResistance(SHOCK       ) );
  tp->eventPrint("COLD        : " + who->GetResistance(COLD        ) );
  tp->eventPrint("HEAT        : " + who->GetResistance(HEAT        ) );
  tp->eventPrint("GAS         : " + who->GetResistance(GAS         ) );
  tp->eventPrint("ACID        : " + who->GetResistance(ACID        ) );
  tp->eventPrint("MAGIC       : " + who->GetResistance(MAGIC       ) );
  tp->eventPrint("HUNGER      : " + who->GetResistance(HUNGER      ) );
  tp->eventPrint("DISEASE     : " + who->GetResistance(DISEASE     ) );
  tp->eventPrint("POISON      : " + who->GetResistance(POISON      ) );
  tp->eventPrint("VACUUM      : " + who->GetResistance(VACUUM      ) );
  return 1;
}

string GetHelp(string s) {
  return "Syntax:    resistances <player>\n\n"
         "Shows resistance information for a target player.";
}