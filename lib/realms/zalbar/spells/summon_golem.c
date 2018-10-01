/* Summon Golem 
   Summary: merge of animate dead and summon effigy spell
            
 */

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <daemons.h>
#include <magic.h>
inherit LIB_SPELL;

void CrumbleCorpse(object corpse);

static void create() {
  ::create();
  SetSpell("summon golem");
  SetSpellType(SPELL_OTHER);
  SetRules("OBJ");
  SetSkills( ([
    "conjuring"   : 200,
	"enchantment" : 200,
    ]) );
  SetMagicCost(100, 400);
  SetStaminaCost(100, 100);
  SetDifficulty(50);
  SetHelp("This spell opens a rift into the planar realm to bring life into "
          "a golem's body. The body of the golem must be created before this "
		  "this spell is cast. \n"
          "%^BLACK%^%^B_RED%^DO NOT attempt to create a second golem if one is "
		  "already active!%^RESET%^");
}


int CanCast(object who, int level, mixed x, object array targets) {
  object target = targets[0];
  object *golems;
  debug("iterating thru inventory");
  golems = filter(all_inventory(who),
    (: member_array("golem_body", $1->GetId() ) > -1 :) );
  debug(sizeof(golems));
  if (sizeof(golems) < 1 ) {
    send_messages( "mutter", "$agent_name $agent_verb a few words of magic that "
      "sound impressive but have little effect", who, 0, environment(who) );
    message("system", "You must have a golem body to cast this spell!", who);
    who->eventPrint();
    return 0;
    }
   if (who->GetProperty("golem")) {
    if (find_object(who->GetProperty("golem"))) {
      who->eventPrint("%^RED%^Your attempts to create more than one golem causes planar energy to backfire!%^RESET%^");
      who->eventReceiveDamage(load_object(STD_DUMMY "magicshock"), MAGIC, (who->GetLevel() + 1) * 5, 1);
      return 0;
	  
    }
   }
   if (golems[0]) golems[0]->eventDestruct();
   send_messages( ({"grasp","chant"}), "$agent_name $agent_verb the body of the "
        "golem and $agent_verb a few words of magic.", who, 0, environment(who) );
  
  return ::CanCast(who, level, x, targets);
}

varargs int eventCast(object who, int level, mixed x, object *targets) {
  object golem = new("realms/zalbar/spells/obj/golem.c");

  if (!golem) {
    who->eventPrint("Something has gone wrong!");
    return 1;
    }
  golem->eventMove(environment(who));
  golem->SetReligion(who->GetReligion());
  golem->SetSummoner(who->GetKeyName());
  golem->SetOwner(who->GetKeyName());
  golem->SetLevel(golem->GetLevel() + who->GetLevel()/5);

  /*switch(level) {
      case 0..20:
        zombielevel = who->GetLevel() - 50;
        break;
      case 21..50:
        zombielevel = who->GetLevel() - 20;
        break;
      case 51..100:
        zombielevel = who->GetLevel() - 10;
        break;
      }
	  */
   who->SetPermanentProperty("golem", file_name(golem));
   return 1;
  }

