//
// The 'blizzard' spell
// Created by Thoin@Haven
//

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("blizzard");
   SetSpellType(SPELL_COMBAT);
   SetAreaSpell(1);
   SetRules("");
   SetSkills( ([
      "natural magic" : 150,
      "evokation"     : 150,
   ]) );
   SetAutoDamage(0);
   SetDifficulty(150);
   SetDamageType(COLD);
   SetEnhanceSkills( ({ "ice magic" }) );
   SetHelp(
           "Natural magic users are able to create a powerful blizzard around "
           "themselves damaging everyone in the room. \n"
           "This spell must be cast outdoors or while under the effects of a natural charge."
           );
   SetMessages( ({
    ({ "form", "$agent_name%^BLUE%^ $agent_verb%^RESET%^ a swirling vortex of snow and ice around $target_name." }),
    ({ "form", "$agent_name%^BLUE%^ $agent_verb%^RESET%^ a mayhem of snow and ice around $target_name." }),
    ({ "form", "$agent_name%^BLUE%^ $agent_verb%^RESET%^ a howling fury of snow and ice around $target_name." }),
    }) );
}

int CanCast(object who, int level, mixed limb, object *targets) {
  if( (environment(who)->GetClimate() == "indoors") || (environment(who)->GetClimate() == "underground") ){
    if (!present("natural_charge", who)) {
      who->eventPrint("Your spell fizzles and refuses to work in these types of environmental settings.");
      return 0;
     }
  }
  return spell::CanCast(who, level, limb, targets);
}
