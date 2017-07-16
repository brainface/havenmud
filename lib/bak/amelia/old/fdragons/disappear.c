#include <lib.h>
inherit LIB_VERB;

mixed can_disappear();

static void create() {
  verb::create();
  SetVerb("disappear");
  SetRules("");
  SetHelp(
    "Syntax :  \"disappear\" \n"
   "\nLets faerie dragons disappear at will.");
  }

mixed can_disappear() 
{
  if (!(this_player()->GetInCombat())) 
  {
    return "Not in combat.";
  }
  if ((this_player()->GetRace()) != "faerie dragon") 
  {
    return "Sorry, faerie dragons only.";
  }
  else
  {
    this_player()->SetInvis(1);
  }
}
