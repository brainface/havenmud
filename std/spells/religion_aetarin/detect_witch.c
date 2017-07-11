// detect sorcery
// mahk 2017
#include <lib.h>
#include <magic.h>
inherit LIB_SPELL;
static void create() {
  spell::create();
  SetSpell("detect witchery");
  SetSpellType(SPELL_OTHER);
  SetRules("");
  SetSkills( ([
    "enchantment" : 1,
    "faith" : 1,
  ]) );
  SetRequiredMagic(30);
  SetMagicCost(20,10);
  SetDifficulty(20);
  SetReligions("Aetarin");
  SetHelp(
    "Identifying witchcraft is the first lesson taught to Aetarin priests. "
    "Novices can merely sense that a conjurer is nearby, but precision "
    "is quickly learned.");
  }

varargs int eventCast(object who, int level, mixed limb, object *targets) {
   int i, maxi, fail = 0;
   object *people = filter(all_inventory(environment(who)), (: living :));
   object *witches = ({ });
   
   people -= ({ who });
   foreach(object person in people) {
      if(person->GetSkillLevel("conjuring")) {
        witches += ({ person });        
      }
   }
   
   if (level < 50 && sizeof(witches)) {
     who->eventPrint("Something stinks of witchery nearby.");
   } else if (level >= 50 && sizeof(witches)) {
     foreach(object witch in witches) {
       who->eventPrint(capitalize(witch->GetShort() + " reeks of conjuring."));
     }
   } else {
     who->eventPrint("You sense a comforting lack of witches and conjurers.");
   }
   
   return 1;
}


