#include <lib.h>
#include <std.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("create natural herbs");
  SetRules("");
  SetMagicCost(50, 50);
  SetDifficulty(45);
  SetSkills( ([
    "natural magic" : 60,
    "enchantment"   : 60,
    ]) );
  SetHelp(
    "Using this spell, the caster quickly grows a sprig of natural herbs which "
    "can, if lit, be smoked.  The natural herbs have been known to have a calming "
    "effect on most souls and can reduce tension."
    );
}
  
varargs int CanCast(object who, int level, string bleh, object *t) {
  object room = environment(who);
  
  if ((room->GetClimate() == "indoors" || room->GetClimate() == "underground" ) 
  	   && !present("natural_charge", who)) {
    send_messages( ({ "attempt", "realize", "are" }),
        "$agent_name $agent_verb to grow a sprig of %^GREEN%^natural herbs%^RESET%^ "
        "but then $agent_verb that $agent_objective $agent_verb indoors!", who, 0, room);
    return 0;
  }
  return ::CanCast(who, level, bleh, t);
}

varargs int eventCast(object who, int level, string bleh, object *t) {
  object room = environment(who);
  object spring = new(STD_SPELLS "obj/natural_herb_ob");
  
  if (!spring) {
    who->eventPrint("Error with obj/natural_herb_ob.c");
    return 0;
    }
  send_messages( ({ "grow", }),
    "$agent_name magically $agent_verb a small %^GREEN%^sprig%^RESET%^ of natural herbs.",
    who, 0, room);
  send_messages( ({ "pick", }),
    "$agent_name $agent_verb a sprig of natural herbs from the now fully grown plant.",
    who, 0, room);
  room->eventPrint("The plant turns to dust once the herbs have been picked.");  
  spring->eventMove(who);
  spring->SetPortions(level/5 + 1);
  return 1;
}
