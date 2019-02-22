/* Quadrify */
// an enchanter spell used to make furniture
// mounts, and or a pet

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <daemons.h>
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("quadrify");
  SetSpellType(SPELL_OTHER);
  SetRules("OBJ");
  SetSkills( ([
    "conjuring"   : 120,
    "enchantment" : 120,
  ]) );
  SetMagicCost(  100, 100);
  SetStaminaCost(100, 100);
  SetDifficulty(50);
  SetHelp(
    "A legendary enchanter can utilize their magic to transform a mundane "
    "item into a better, four-legged mundane item, sometimes even breathing "
    "false life into the object. The composition of the item determines the "
    "resultant creation--textile, wood, leather, metal, and miscellaneous "
    "natural materials all produce different results.");
}

varargs int CanCast(object who, int level, mixed q, object *t) {
  object target = t[0];
  object *dags;
  
  if (target->living()) {
    who->eventPrint("Unfortunately, even your magic can't improve "
      +target->GetName());
    return 0;
  } else if (target->PreventGet()) {
    who->eventPrint("That's either too big or too stable for you to change.");
    return 0;
  } else if (target->GetProperty("magic")) {
    who->eventPrint("That item is too full of magic already to quadrify.");
    return 0;
  }

  if ( sizeof(target->GetMaterials()) < 1) {
    who->eventPrint("That appears to be made of nothing and you can make " 
      "nothing from it.");
    return 0;
  }

  if ( member_array("textile", target->GetMaterials()) != -1) {
    dags =  children(DIR_SPELLS "/obj/quadrify/dag");
    foreach(object dag in dags) {
      if(dag->GetOwner() == who->GetKeyName()) {
        who->eventPrint("You already have enough dags!");
        return 0;
      }
    }
  }

  if ( member_array("metal", target->GetMaterials()) != -1) {
    dags =  children(DIR_SPELLS "/obj/quadrify/horse");
    foreach(object dag in dags) {
      if(dag->GetOwner() == who->GetKeyName()) {
        who->eventPrint("You can only have one horse of course.");
        return 0;
      }
    }
  }

  // big dumb if block
  if ( member_array("metal", target->GetMaterials()) == -1   &&
       member_array("textile", target->GetMaterials()) == -1 &&
       member_array("wood", target->GetMaterials()) == -1    &&
       member_array("leather", target->GetMaterials()) == -1 &&
       member_array("natural", target->GetMaterials()) == -1 ){
     who->eventPrint("This is made of some strange stuff, and your "
       "magic can't affect it.");
     return 0;

  }
  
  return ::CanCast(who, level, q, t);
}

varargs int eventCast(object who, int level, mixed x, object *targets) {
  object quad;
  object scrap = targets[0];
  int daglevel;

  // check cloth (rag dag)
  if (member_array("textile", scrap->GetMaterials()) != -1) {
    quad = new(STD_SPELLS "obj/quadrify/dag");
    daglevel = who->GetSkillLevel("enchantment")/2;
    if (daglevel < 1) daglevel = 1;
    quad->SetLevel(daglevel);
    quad->SetOwner(who->GetKeyName());    
    //quad->eventForce("follow "+ who->GetKeyName());
    //who->eventForce("lead "+ quad->GetKeyName());
    //quad->eventForce("guard " + who->GetKeyName());
    // check leather (sofa)
  } else if (member_array("leather", scrap->GetMaterials()) != -1) {
    quad = new(STD_SPELLS "obj/quadrify/couch");
    // check natural (chair)    
  } else if (member_array("natural", scrap->GetMaterials()) != -1) {
    quad = new(STD_SPELLS "obj/quadrify/chair");
  // check metal (steel steer) (god that's an awful name)
  } else if (member_array("metal", scrap->GetMaterials()) != -1) {    
    quad = new(STD_SPELLS "obj/quadrify/horse");
    daglevel = who->GetSkillLevel("enchantment")/2;
    if (daglevel < 1) daglevel = 1;
    quad->SetLevel(daglevel);
    quad->SetOwner(who->GetKeyName());    
  // check wood (table);
  } else if (member_array("wood", scrap->GetMaterials()) != -1) {
    quad = new(STD_SPELLS "obj/quadrify/couch");    
  } else {  
    debug("oh no something's wrong with quadrify how can this be");
    who->eventPrint("something's wrong with this spell. Please submit a bug report.");
    return 0;
  }

  send_messages("blah", "$agent_possessive_noun magic%^MAGENTA%^ twists and "
    "warps%^RESET%^ $target_name into a new, four-legged shape.",
    who, scrap, environment(who));
  
  scrap->eventDestruct();
  quad->eventMove(environment(who));
  return 1;
}

