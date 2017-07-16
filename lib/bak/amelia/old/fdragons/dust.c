//  Dust verb for faerie dragons
//  blesses target
//  coded by Gabriel@Haven 11/15/99

#include <lib.h>
#include <position.h>
#include <rounds.h>
inherit LIB_VERB;

static void create() 
{
  verb::create();
  SetVerb("dust");
  SetRules("", "LIV");
  SetHelp("Syntax:          \"dust LIV\"    \n"
          "\nAdd bless to a target.");
}

mixed can_dust_liv(object who) 
{
  if (this_player()->GetPosition() == POSITION_SITTING ||
    this_player()->GetPosition() == POSITION_LYING) 
  {
    return "You cannot dust someone from that position.";     
  }
  if (this_player()->GetParalyzed()) 
  {
    return "You cannot move!";
  }
  if (!(this_player()->GetInCombat())) 
  {
    return "Not while your fighting.";
  }
  if ((this_player()->GetAge()) != 35000) 
  {
    return "Your not old enough little one.";
  }
  if ((this_player()->GetRace()) != "faerie dragon") 
  {
    return "Sorry, faerie dragons only.";
  }
  return 1;
}

mixed do_dust_liv(object target) 
{
  int dur = ((this_player()->GetAge()) / 10000);
  int amt = ((this_player()->GetAge()) / 35000);

  this_player()->AddMagicPoints(-50);
  send_messages( ({"hover","sprinke"}),
    "$agent_name $target_verb over $target_name and $target_verb "
    "down a glittery dust.",
    this_player(),target,environment(this_player()) );
  target->eventBless(amt,dur);
}
