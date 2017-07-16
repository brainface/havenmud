/*  A spell to mend metal
 */
#include <lib.h>
#include <damage_types.h>
#include <magic.h>
inherit LIB_SPELL;

object getEquippedByMaterial(object target, string material);

static void create() {
  spell::create();
  SetSpell("mend metal");
  SetRules(({"OBJ","LIV"}));
  SetSpellType(SPELL_OTHER);
  SetDifficulty(20);
  SetSkills( ([
     "natural magic" : 60,
     "enchantment" : 60,
      ]) );
  SetRequiredMagic(80);
  SetMagicCost(60, 20);
  SetHelp(
       "Attempts to repair a given piece of metal.  If cast upon "
       "a living creature, the magic attempts to mend something "
       "they're wearing.");
  }

varargs int CanCast(object who, int level, mixed n, object *t) {
  object tg = t[0];

  if (!tg->is_living() && !tg->GetDeterioration()) {
    who->eventPrint("But " + tg->GetShort() + " needs no mending!");
    return 0;
  }
  
  if(tg->is_living()) tg = getEquippedByMaterial(tg,"metal");
  if(!tg) {
    message("system", "That person wears no damaged metal!", who);
    return 0;
  }
  
  return ::CanCast(who, level, n, t);
}

varargs int eventCast(object who, int level, mixed n, object *t) {
  object target = t[0];

  if(target->is_living()) target = getEquippedByMaterial(target,"metal");
  if(!target) {
    message("system", "That person wears no damaged metal!", who);
    return 0;
  }
  
  if (member_array("metal", target->GetMaterials()) == -1) {
    message("system", "That is not metallic", who);
    return 0;
    }
    
  if( (random(100) - (who->GetSkillLevel("metal working")) ) < level ) {
    send_messages( ({ "study" }),
      "$agent_name $agent_verb $target_name, causing it to "
      "look much better!",
      who, target, environment(who) );
      target->eventRepair(who, environment(who), 1);
      return 1;
     }
  send_messages( ({ "study" }),
       "$agent_name $agent_verb $target_name, but nothing happens.",
        who, target, environment(who) );
      return 1;
    }

    
object getEquippedByMaterial(object target, string material) {
  object item = 0;
  // if target is a npc/player, try to find something leather on them to fix.
  if(target->is_living()) {
    foreach( object thingy in target->GetUniqueWorn()) {
      if(thingy->NeedsRepairs()) {
        if(   member_array(material+" working",thingy->GetRepairSkills()) != -1) {
          item = thingy;
          break;
        }
      }
    }
  }
  
  return item;
}


