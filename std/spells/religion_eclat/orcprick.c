#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
    spell::create();
    SetSpell("orc prick");
  SetReligions("Eclat");    
    SetRules("", "LIV");
    SetSpellType(SPELL_COMBAT);
    SetSkills( ([
     "natural magic" : 10,
     "enchantment" : 10,
             ]) );
    SetDifficulty(20);
    SetMorality(10);
    SetAutoDamage(0);
    SetDamage(PIERCE|SHOCK, 60, 60);
    SetEnhanceSkills( ({ "shock magic" }) );
    SetMessages(({ ({ "accept", "$target_name $target_verb "
                                "$agent_possessive_noun spear with a "
                                "smile." }),
                         ({ "", "$agent_possessive_noun spear "
                                "grazes $target_name." }),
                         ({ "", "$agent_possessive_noun spear "
                                "stabs $target_name." }),
                         ({ "", "Filled with the powers of goodness, "
                                "$agent_possessive spear strikes "
                                "$target_name." }) }));
    SetHelp("This spell weaves the wind into a spear that hurtles at the "
            "target.  The target must be an orc, or the spear will not "
            "harm them.");
}

int CanCast(object who, int level, mixed limb, object array targets) {
   if(targets[0]->GetRace() != "orc") {
        who->eventPrint("But that is not an orc!");
        return 0;
   }
   return ::CanCast(who, level, limb, targets);
}
