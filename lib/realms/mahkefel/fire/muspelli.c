// copy of two zaxan spells added together
// by mahkefel, 2013
#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("muspelli");
   SetSpellType(SPELL_COMBAT);
   SetRules("", "LIV");
   SetSkills( ([
     "natural magic" : 400,
     "evokation"     : 400,
    ]) );
   SetDifficulty(30);
   SetAutoDamage(0);
   SetDamageType(HEAT|BLUNT);
   SetEnhanceSkills( ({ "fire magic" }) );
   SetHelp(
     "This spell causes the end of the world in fire and ash. For "
     "a select few near the blast, at least. "
     "Like many natural spells, this spell may only be used "
     "outside or while under the influence of a natural charge."
   );
   
}

int eventCast(object who, int level, string limb, object array targets) {
   object target = targets[0];
   int damage = GetDamage(level);
   int num = who->GetSkillLevel("fire magic")/20;
    if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
    who->eventPrint("Your powers fail you.");
    return 0;
  }

   sen   send_messages(({ "create" }), "$agent_name $agent_verb a huge cloud "
                 "of %^RED%^acid%^RESET%^ which promptly rains on "+
                  conjunction(targets->GetName())+".",who,targets,
                  environment(who));

   target->eventReceiveDamage(who, GetDamageType(), damage, GetAutoDamage(), target->GetRandomLimb(target->GetTorso()));
   for(int i=0;i<num;i++) {
    if(sizeof(all_inventory(target))) {
      object thing = (all_inventory(target)[random(sizeof(all_inventory(target)))]);
         if(thing->GetMealType()) {
            send_messages("",
              "$target_possessive_noun " + remove_article(thing->GetShort()) + " %^BOLD%^RED%^bursts into flame!%^RESET%^",
              who, target, environment(who));
            thing->eventDestruct();
         } else {
           send_messages("", 
             "$target_possessive_noun " + remove_article(thing->GetShort()) + " %^RED%^warps and melts%^RESET%^ under the volcanic blast!",
               who, target, environment(who));
           thing->eventDeteriorate(GetDamageType());
          }
      }
   }
   return 1;
}
