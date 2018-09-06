// mahkefel 2017
// ripping opposing Factions out of /lib/living/reputation.c
// because it's interacting weirdly with player save code
// (permanently saving the list of opposed factions to new
// players at the creation date of the character, allowing
// no future edits. Daemons sound like the solution to this.)

#include <lib.h>
inherit LIB_DAEMON;

mapping OpposingFactions = ([
    "Haven"        :    "Malveillant",
    "Karak"        :    "Glimmerdin",
    "Glimmerdin"   :    "Karak",
    "Malveillant"  :    "Haven",
    "Gwonish"      :    "Lloryk",
    "Lloryk"       :    "Gwonish",
    "Durgoroth"    :    "Grymxoria",
    "Grymxoria"    :    "Durgoroth",
    "Ungkh"        :    "Jidoor",
    "Jidoor"       :    "Ungkh",
    "Averath"      :    "Dalnairn",
]);  

mixed GetOpposingFaction(string faction) {
  if (OpposingFactions[faction]) return OpposingFactions[faction];
  return 0;
}


