//
// The 'lunar charge' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("natural charge");
   SetSpellType(SPELL_OTHER);
   SetRules("");
   SetRecoveryTime(1 + random(2));
   SetSkills( ([
     "evokation"     : 20,
     "natural magic" : 20,
   ]) );
   SetMagicCost(15,10);
   SetMagicCost(10,10);
   SetDifficulty(10);
   SetHelp(
           "Using this spell, a natural magic user is "
           "able to charge up the energy given off by the "
           "nature to be later channeled through spells that "
           "may require additional energy.. This spell may "
           "only be used outdoors.");
}

int CanCast(object who, int level, mixed limb, object *targets) {
   if( (environment(who)->GetClimate() == "indoors") ) {
      who->eventPrint("Your spell fizzles and refuses to work in these types of environmental settings.");
      return 0;
   }
   return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed l, object *t) {
  object charge = new(DIR_SPELLS "/obj/natural_charge_obj");
  
  if (!charge) {
    who->eventPrint("A supernatural issue prevents that.");
    debug("Problem loading DIR_SPELLS /obj/natural_charge_obj");
    return 1;
  }
  
  charge->eventMove(who);
  charge->SetLifeSpan(level * 18);
  send_messages( ({ "charge" }),
    "$agent_name%^GREEN%^ $agent_verb%^RESET%^ $agent_reflexive with natural energies.",
    who, 0, environment(who) );
  return 1;
}