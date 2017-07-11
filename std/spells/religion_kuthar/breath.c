// torak 10/28/12
#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <std.h>

inherit LIB_SPELL;

static void create() {
  spell::create();
  SetSpell("breath of ancestors");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
    "necromancy" : 50,
    "natural magic"    :50,
    "faith"      : 50,
  ]) );
  SetRequiredMagic(100);
  SetMagicCost(75, 75);
  SetDifficulty(35);
  SetMorality(0);
  SetAutoDamage(0);
  SetReligions("Kuthar");
  SetHelp(
    "This spell allows faithful Kuthar shaman to invigorate "
    "themselves though the power of their ancestors."
    );
}

int CanCast(object who, int level, mixed limb, object *targets) {
  object *germ;
  germ = filter(all_inventory(who), (: $1->GetProperty("germ") :) );
  
   foreach(object germ2 in germ) {
      if (germ2->GetKeyName("breath")) {
      message("system", 
        "But you have already been imbued with the breath of your ancestors.", who);
      return 0;
      }
   }
  return spell::CanCast(who, level, limb, targets);
}

int eventCast(object who, int level, mixed limb, object *targets) {
  object target = targets[0];

          send_messages( ({""}), 
            "%^CYAN%^A shadowy mist of spirits swirls around $agent_name, "
            "enveloping $agent_possessive_noun body with a glow before "
            "disappearing.%^RESET%^" 
            ,who, 0,environment(who) );

     STD_GERMS "breath"->eventInfect(who);
    return 1;
  }
