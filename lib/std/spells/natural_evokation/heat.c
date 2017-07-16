//
// The 'heat' spell
//
// The 'heat' spell
// Created by Zaxan@Haven
//
// Mahkefel 2011: actually gave slight disarm chance.

#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

static void create() {
   spell::create();
   SetSpell("heat");
   SetSpellType(SPELL_COMBAT);
   SetRules("", "LIV");
   SetSkills( ([
     "natural magic" : 80,
     "evokation"     : 80,
   ]) );
   SetMorality(0);
   SetDifficulty(20);
   SetAutoDamage(0);
   SetDamageType(HEAT);
   SetEnhanceSkills( ({ "fire magic" }) );
   SetHelp(
           "This spell focuses the heat of the sun on the target and "
           "causes their limbs to burn. This spell also has the "
           "ability of causing the target to drop their wielded "
           "items. This spell may only be used outdoors or while "
           "under the influence of a natural charge.");
   SetMessages( ({
    ({ "warm", "$agent_name $agent_verb $target_name with a pleasant solar effect." }),
    ({ "burn", "$agent_name%^BOLD%^RED%^ $agent_verb%^RESET%^ $target_name with $agent_possessive solar heat." }),
    ({ "char", "$agent_name%^RED%^ $agent_verb%^RESET%^ $target_name with $agent_possessive solar heat." }),
    }) );
}

int CanCast(object who, int level, mixed limb, object *targets) {
  if( (environment(who)->GetClimate() == "indoors") ||
    (environment(who)->GetClimate() == "underground") ){
    if (!present("natural_charge", who)) {
      who->eventPrint("Your spell fizzles and refuses to work in these types of environmental settings.");
      return 0;
     }
  }
  return spell::CanCast(who, level, limb, targets);
}

// broadcast a message to the room
int eventCast(object who, int level, string limb, object array targets) {
  int result;

  result = spell::eventCast(who,level,limb,targets);

  if(result) {
    object *weapons;
    object weapon;
    object target = targets[0];

    int pro, con;

    //200 vs... ehhh 530
    pro = random( who->GetStatLevel("wisdom") + who->GetSkillLevel("fire magic") );
    con = random( target->GetStatLevel("coordination") + target->GetStatLevel("luck") + 300 );
    //debug( "heat disarm--pro: " + pro + " con: " + con);

    if ( pro > con ) {
      //debug("heat is disarming");
      weapons = target->GetWielded();
      if(sizeof(weapons)) {
        weapon = weapons[random(sizeof(weapons))];
        if (weapon->CanDisarm(who,target)) {
          send_messages( ({"scream", "throw"}),
            "$target_name%^YELLOW%^BOLD%^ $target_verb%^RESET%^ in pain and "
            "$target_verb $target_possessive " + weapon->GetKeyName() + " "
            "to the ground!", who, target, environment(who) );
          weapon->eventUnequip(target);
          weapon->eventDrop(target);
        } 
      }
    }
  }
  return result;
}

