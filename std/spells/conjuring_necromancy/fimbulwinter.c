// fimbulwinter
// demigod necromancy spell for max
// mahkefel 2013
// an area effect cold cloudkill, that stacks
#include <lib.h>
#include <magic.h>
#include <damage_types.h>

inherit LIB_SPELL;

void eventGas(object who, int level, object target, int length, int i);
// copy of cloudkill's dot

static void create() {
  spell::create();
  SetSpell("fimbulwinter");
  SetRules("");

  SetUniqueSpell(1);
  SetEnhanceSkills( ({ "ice magic" }) );
  SetSkills( ([
    "necromancy" : 800,
    "conjuring" : 800,
  ]) );
  SetDamageType(COLD);
  SetAutoDamage(0);
  SetAreaSpell(1);
  SetSpellType(SPELL_COMBAT);
  SetDifficulty(100);
  SetMessages( ({
    ({"", "$agent_possessive_noun %^BLUE%^light flurry%^RESET%^ "
      "mildly chills $target_name." }),
    ({"", "$agent_possessive_noun %^BOLD%^%^BLUE%^blizzard%^RESET%^ "
      "pelts $target_name, coating "
      "$target_objective in a fine layer of frost." }),
    ({"", "$agent_possessive_noun %^BOLD%^CYAN%^fimbulwinter%^RESET%^ "
      "screams into $target_name, freezing $target_objective to the "
      "core!" }),
    }) );
  SetHelp(
    "With this ancient sorcery, the very skilled of necromancers "
    "can conjure frost from a terrible and frigid time when even "
    "the gods knew the fear of winter. Reanimated servants know "
    "no fear of death and are unaffected by the terrible blast."
  );
}

// broadcast a message to the room
int eventCast(object who, int level, string limb, object array targets) {
   int damage = GetDamage(level);

    if( CanAttack(who, targets, GetSpellLevel() + level/5) == - 1 ) {
            who->eventPrint("Your powers fail you.");
            return 0;
          }
   send_messages( "",
     "%^BOLD%^CYAN%^A dark and terrible wave of snow and ice rolls over everything!%^RESET%^",
     who, who, environment(who));


   if (who) {
     if (environment(who)) {
       if(environment(who)->GetClimate()!="indoors" &&
         environment(who)->GetClimate()!="outdoors") {
         environment(who)->SetClimate("arctic");
         send_messages( "",
           "%^BOLD%^CYAN%^ Dark clouds blot out the sky, and a permanent-looking layer of ice and "
           "snow coat the ground around you.%^RESET%^",
           who, who, environment(who));
      }
    }
  }

   foreach(object target in targets) {
     if (!target) continue;
     if (target->GetProperty("fimbulwinter")) continue;
     call_out( (: eventGas, who, level, target, who->GetSkillLevel("ice magic")/50, 0 :), 10);
   }
   return spell::eventCast(who, level, limb, targets);
   return 1;
}


// override GetTargets to remove summoned animals from the list
// god, i do not know if this will work or randomly throw errors.
varargs object *GetTargets(object who, mixed args...) {
  object array targets = ({ });

  foreach(mixed arg in args) {
    debug(arg);
  }

  // damned spell shouldn't have args anyway
  targets = spell::GetTargets(who);
  if (!sizeof(targets)) return targets;

  // let's go ahead and not rain lightning down on the druid's pets?
  foreach(object target in targets) {
    if (!target) continue;
    if (target->GetOwner() == who->GetKeyName()) {
      targets = targets - ({target});
    }
  }
  return targets;
}


void eventGas(object who, int level, object target, int length, int i) {
   int damage = GetDamage(level)/3;

   if(!target) return 0;
   if (target->GetUndead()) {
     target->RemoveProperty("fimbulwinter");
     target->eventPrint("The undead are unharmed by the dread fimbulwinter.");
     return;
   }
   if (!who) {
     target->RemoveProperty("fimbulwinter");
     target->eventPrint("The dread grip of the fimbulwinter finally leaves you.");
     return;
   }
   if(target && (i < length)) {
      send_messages("",
        "The %^CYAN%^BOLD%^dread grip of fimbulwinter%^RESET%^ freezes $target_possessive_noun very soul!",
          who, target, environment(target));
      target->eventForce("emote shivers uncontrollably.");
      target->eventReceiveDamage(who, COLD, damage, GetAutoDamage(), 0);
      i++;
      call_out((: eventGas, who, level, target, length, i :), 20);
      return;
   } else if(target && (i >= length)) {
      target->RemoveProperty("fimbulwinter");
      send_messages("",
        "The %^CYAN%^BOLD%^thick layer of frost%^RESET%^ coating $target_name finally melts.",
          who, target, environment(target));
      return;
   }
}

