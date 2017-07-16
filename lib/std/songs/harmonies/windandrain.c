#include <lib.h>
#include <music.h>
#include <damage_types.h>
inherit LIB_SONG;

static void create() {
   ::create();
   SetSong("the wind and rain");
   SetRules("","LIV");
   //SetMagicCost(100,100);
   SetAutoDamage(0);
   SetSongType(SONG_COMBAT);
   SetSkills( ([
       "vocal music" : 200,
       "instrumental music" : 200,
            ]) );
   SetDifficulty(75); 
   SetEnhanceSkills( ({ "ice magic" }) );
   SetDamageType(COLD|VACUUM);
   SetMessages( ({
     ({ "sing","$agent_possessive_noun singing leaves $target_name bored and "
       "angry, not to mention a little %^BOLD%^BLUE%^drenched%^RESET%^." }),
     ({ "sing","$agent_possessive_noun lament leaves $target_name "
       "%^BOLD%^BLACK%^breathless!%^RESET%^ and waterlogged!" }),
     ({ ({"sing","saw"}), "$agent_possessive_noun mournful tale leaves "
       "$target_name %^BOLD%^BLUE%^chilled to the bone%^RESET%^ and "
       "%^BOLD%^BLACK%^gasping for breath!%^RESET%^" }),
   }) );
   SetHelp("The bard sings a cursed tale of a murdered lover drowned in the "
     "river, invoking the same fate upon her audience.");
}

int eventSing(object who, int level, mixed limb, object array targets) {
   send_messages( ({"sing","saw"}),
     "$agent_name $agent_verb and $agent_verb, and a the mournful sound of "
     "a %^BOLD%^BLACK%^dreadful%^RESET%^ %^BOLD%^BLUE%^wind and "
     "rain%^RESETS%^ echoes throughout!",
     who, targets, environment(who));
   return song::eventSing(who, level, limb, targets);
}

// override GetTargets to remove summoned animals from the list
// god, i do not know if this will work or randomly throw errors.
varargs object *GetTargets(object who, mixed args...) {
  object array targets = ({ });

  foreach(mixed arg in args) {
    debug(arg);
  }

  // damned spell shouldn't have args anyway
  targets = song::GetTargets(who);
  if (!sizeof(targets)) return targets;

  // let's go ahead and not rain lightning down on the druid's pets?
  foreach(object target in targets) {
    if (!target) continue;
    if (target->GetOwner() == who->GetKeyName()) {
      targets = targets - ({target});
    }
    if (targets->GetKeyName() == "rusalka"
      || targets->GetKeyName() == "greater water elemental"
      || targets->GetKeyName() == "lesser water elemental") {
      targets = targets - ({target});
    }
  }
  return targets;
}


