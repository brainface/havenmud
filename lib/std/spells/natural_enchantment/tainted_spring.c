#include <lib.h>
#include <std.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("create tainted spring");
  SetRules("");
  SetMagicCost(50, 100);
  SetDifficulty(25);
  SetSkills( ([
    "natural magic" : 55,
    "enchantment"   : 55,
    ]) );
  SetHelp(
    "Using this spell, the caster summons a small spring of water which "
    "bursts from the ground spewing a liquid that is almost, but not entirely, "
    "unlike spring water.  The liquid that is most commonly cited is vodka."
    );
}
  
varargs int CanCast(object who, int level, string bleh, object *t) {
  object room = environment(who);
  
  if ((room->GetClimate() == "indoors" || room->GetClimate() == "underground") && 
  	  !present("natural_charge", who)) {
    send_messages( ({ "attempt", "realize", "are", }),
        "$agent_name $agent_verb to call forth a cool, refreshing spring of %^BLUE%^water%^RESET%^ "
        "but then $agent_verb that $agent_objective $agent_verb indoors!", who, 0, room);
    return 0;
  }
  return ::CanCast(who, level, bleh, t);
}

varargs int eventCast(object who, int level, string bleh, object *t) {
  object room = environment(who);
  object spring = new(STD_SPELLS "obj/tainted_spring_ob");
  
  if (!spring) {
    who->eventPrint("Error with obj/tainted_spring_ob.c");
    return 0;
    }
  send_messages( ({ "call", }),
    "$agent_name $agent_verb forth a cool, %^BLUE%^refreshing spring%^RESET%^ that bubbles up from the ground.",
    who, 0, room);
  spring->eventMove(room);
  spring->SetPortions(level/5 + 1);
  return 1;
}
