//                
// Whirlwind
// Anteky, knocks things down
//   for great escape 
// damage is gimped.                     

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();   
   SetSpell("whirlwind");
   SetSpellType(SPELL_COMBAT);
   SetAreaSpell(1);           
   SetRules("");              
   SetSkills( ([              
     "faith"       : 20,       
     "evokation"   : 20,       
   ]) );                      
   SetMorality(0);            
   SetDifficulty(40);         
   SetDamageType(PIERCE);       
   SetReligions("Anteky"); 
   SetHelp(
     "This spell allows a faithful cleric to summon a "
     "small whirlwind to distract and harass their foes. "
     "The faithful of Anteky are not harmed by the whirling wind."
   );                                                                  
}                                                                             

int eventCast(object who, int level, string limb, object array targets) {
   int damage = GetDamage(level)/4; // NURFED DAMAGE                                        
   if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
     who->eventPrint("Your powers fail you.");
     return 0;
   }
   send_messages(({ "summon" }), "$agent_name $agent_verb a swirling "
     "of %^BOLD%^YELLOW%^whirlwind%^RESET%^ full of %^GREEN%^brambles%^RESET%^!.",
       who,0, environment(who));
   foreach(object target in targets) {
     if (!target) continue;
      send_messages("",
        "The whirling winds %^BOLD%^CYAN%^whip%^RESET%^ around $target_name, piercing "
        "$target_objective with thorns!",
        who,target,environment(who));
     target->eventReceiveDamage(who, GetDamageType(), damage,
       0, target->GetRandomLimb(target->GetTorso()) );
     if ( random( target->GetStatLevel("coordination")+target->GetStatLevel("luck")+10) <                     
       random( who->GetStatLevel("wisdom")+who->GetSkillLevel("fire magic") ) ) {                           
       target->eventCollapse();
     }
   }
   return 1;
}

// override GetTargets to remove summoned animals from the list
// god, i do not know if this will work or randomly throw errors.
varargs object *GetTargets(object who, mixed args...) {
  object array targets = ({ });

  foreach(mixed arg in args) {
  }

  // damned spell shouldn't have args anyway
  targets = spell::GetTargets(who);
  if (!sizeof(targets)) return targets;

  // let's go ahead and not rain lightning down on the druid's pets?
  foreach(object target in targets) {
    if (!target) continue;
    if (
     target->GetOwner() == who->GetKeyName()
     || target->GetReligion()=="Anteky"
    ) {
      targets = targets - ({target});
    }
  }
  return targets;
}
