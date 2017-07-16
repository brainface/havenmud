#include <lib.h>
inherit LIB_VERB;

mixed can_appear();

static void create() {
  verb::create();
  SetVerb("appear");
  SetRules("");
  SetHelp(
    "Syntax :  \"appear\" \n"
   "\nLets faerie dragons appear at will.");
  }

mixed can_appear() 
{
  if (!(this_player()->GetInCombat())) 
  {
    return "Not in combat.";
  }
  if ((this_player()->GetAge()) != 10000) 
  {
    return "Your not old enough little one.";
  }
  if ((this_player()->GetRace()) != "faerie dragon") 
  {
    return "Sorry, faerie dragons only.";
  }
  else
  {
    this_player()->SetInvis(0);
  }
}
