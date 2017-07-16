//
// The 'harmony wind' spell
// Created by Zaxan@Haven
//

#include <lib.h>
#include <magic.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("harmony wind");
   SetSpellType(SPELL_HEALING);
   SetAreaSpell(1);
   SetRules("");
   SetSkills( ([ 
      "healing" : 50,
      "natural magic"   : 50,
      ]) );
   SetAutoHeal(1); 
   SetHealing(200,200);
   SetMagicCost(125,25);
   SetDifficulty(60);
   SetMessages( ({
      ({ ({ "look" }), "$target_name $target_verb unaffected by the "
                       "passing wind." }),
      ({ ({ "shiver", "look" }), "$target_name $target_verb from the "
                                 "cold wind passing through, but "
                                 "$target_nominative quickly $target_verb "
                                 "much healthier." }),
      ({ ({ "look" }), "As the wind touches $target_name, "
                       "$target_nominative $target_verb much more "
                       "healthier and powerful." }),
      }) );
  SetReligions("Eclat");
  SetHelp(
           "Upon the cast of this spell by a powerful Eclat priest, a "
           " swift wind "
           "will sweep through the area, healing everything that it "
           "makes contact with, not including the caster.");
}

int eventCast(object who, int level, mixed limb, object array targets) {
   message("system","%^CYAN%^BOLD%^A swift, cold wind flows through the "
                    "area.", ({ targets, environment(who) }) );
   return spell::eventCast(who, level, limb, targets);
}
