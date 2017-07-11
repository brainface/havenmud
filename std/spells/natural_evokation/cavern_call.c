//
// Cheater natural charge spell
//  for monsters
// Reno's spider queen was using natural spells in an underground
//  area with a buggy temperate climate, this spell allows me to 
//  make that area "inside" and not totally break his monster,
//  with the least amount of editing his stuff.
//  (Averath fields', in the tunnels)

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("cavern call");
   SetSpellType(SPELL_OTHER);
   SetRules("");
   SetRecoveryTime(1 + random(2));
   SetSkills( ([
     // other monsters of randomous levels could use these?
     "evokation"     : 200,
     "natural magic" : 200,
   ]) );

   SetMagicCost(15,50);
   SetDifficulty(10);
   SetUniqueSpell(1);
   SetHelp(
     "Certain primordial, inhuman beings can draw natural energy "
     "from the depths of the earth or even from worked "
     "stone around them, allowing them to channel natural "
     "magic in the most artificial of environments."
   );
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
  send_messages( ({ "call","draw" }),
    "$agent_name $agent_verb out with an %^BOLD%^RED%^inhuman "
    "ROAR%^RESET%^ and%^BOLD%^YELLOW%^ $agent_verb energy%^RESET%^ "
    "from the %^BOLD%^BLACK%^stone%^RESET%^ around $agent_objective.",
    who, 0, environment(who) );
  return 1;
}

