/* Clone of animate dead
 *  That makes mummies.
 *
 * Mummies have "low/medium" physical resistance,
 * are fire vulnerable regardless of race,
 * and have a low frequency curse attack
 *
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
  SetSpell("mummify");
  SetSpellType(SPELL_OTHER);
  SetUniqueSpell(1);
  SetRules("OBJ");
  SetSkills( ([
    "necromancy" : 50,
  ]) );
  SetMagicCost(  100, 100);
  SetStaminaCost(100, 100);
  SetDifficulty(50);
  SetHelp(
    "This spell allows the caster to perform a necromantic ritual to "
    "preserve and animate a corpse to serve him. Xandrian necromancers "
    "prefer such servants, as the ritual leaves the corpse resistant to "
    "most weapons, if very vulnerable to fire. \n"
    "%^BLACK%^%^B_RED%^DO NOT animate a second corpse of any type if "
    "one is already active!%^RESET%^");
}

object *GetTargets(object who, mixed args...) {
  object *targets = ::GetTargets(who, args...);
  if (!targets) targets = ({ });
  filter(targets, (: $1->GetCorpseState() :) );
  return targets;
}

varargs int CanCast(object who, int level, mixed x, object *targets) {
  object ob;
  if (who->GetProperty("animate_zombie")) {
    if (find_object(who->GetProperty("animate_zombie"))) {
      who->eventPrint("%^RED%^Your attempts to dominate more than one corpse "
        "result in a hideous backlash!%^RESET%^");
      who->eventReceiveDamage(load_object(STD_DUMMY "magicshock"), MAGIC,
        (who->GetLevel() + 1) * 5, 1);
      return 0;
    }
  }
  foreach(object t in targets) {
    if (t->GetUserCorpse()) {
      who->eventPrint(t->GetShort() + " cannot be animated.");
      return 0;
    }
    // refuse to cast on i.e. torches, drums, signs.
    if (!t->GetRace()) {
      who->eventPrint(t->GetShort() + " cannot be animated.");
      return 0;
    }
  }

  return ::CanCast(who, level, x, targets);
}

varargs int eventCast(object who, int level, mixed x, object *targets) {
  object zombie;
  object t = targets[0];
  int zombielevel;

  foreach(object corpse in targets) {
    zombie = new(STD_SPELLS "obj/animate_mummy");
    if( !RACES_D->GetValidRace(corpse->GetRace()) ) {
      who->eventPrint(capitalize(corpse->GetShort())
        + " refuses to be animated.");
      zombie->eventDestruct();
      continue;
     }

    zombie->SetGender(corpse->GetGender());
    zombie->SetRace(corpse->GetRace());
    zombie->SetClass(corpse->GetOriginalClass());
    zombie->SetLong("This is a heavily bandaged corpse of " +
      add_article(corpse->GetRace()) + " that has been preserved and "
        "animated by necromatic rituals.");
    switch(level) {
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
    if (zombielevel < 1) zombielevel = 1;
    if (zombielevel > corpse->GetLevel() * 2)
      zombielevel = corpse->GetLevel() * 2;
    zombie->SetLevel(zombielevel);

    switch(corpse->GetCorpseState()) {
      case "fresh corpse" :
        zombie->SetShort("a well preserved " + corpse->GetRace() + " mummy");
         zombie->SetAdjectives( ({ corpse->GetAdjectives()..., "mummy",
           "well", "preserved", corpse->GetRace() }) );
         zombie->SetKeyName("mummified " + corpse->GetRace());
         break;
      case "rotted corpse" :
         zombie->SetShort("a tattered and shambling " + corpse->GetRace()
           + "mummy");
         zombie->SetAdjectives( ({ corpse->GetAdjectives()..., "mummy",
           "rotting", "shambling", "and" }) );

         zombie->SetKeyName("mummified " + corpse->GetRace());
         break;
      case "skeleton" :
         zombie->SetShort("a desicated skeletal " + corpse->GetRace());
         zombie->SetAdjectives( ({ corpse->GetAdjectives()..., "mummy",
           "skeletal", "desicated" }) );
         zombie->SetKeyName("mummified " + corpse->GetRace());
         break;
      }
   // make it "mummified" and not just "mummy".
   zombie->SetCapName(capitalize(zombie->GetKeyName()));
   zombie->SetId( ({ corpse->GetId()...,  "mummy",  corpse->GetRace() }) );
   zombie->SetUndead(1);
   zombie->SetUndeadType("mummy");
   foreach(object thing in all_inventory(corpse)) {
     thing->eventMove(zombie);
    }

   // some races with inate physical resist (demons?) may be made
   // *weaker* if mummified. Since resistance is all in *strings* I don't
   // care to fix this.
   zombie->SetResistance(HEAT,"weakness");
   zombie->SetResistance(ALL_PHYSICAL,"low");
   if (who->GetSkillLevel("necromancy") > 200) {
     zombie->SetResistance(ALL_PHYSICAL,"medium");
   }
   zombie->eventForce("wear all");
   send_messages( ({ "wrap", "coax" }),
     "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name "
     "in perfumed bandages and $agent_verb $target_objective "
     "back to a semblance of life.", who, corpse, environment(corpse) );
   corpse->eventDestruct();
   who->SetPermanentProperty("animate_zombie", file_name(zombie));
   zombie->SetOwner(who->GetKeyName());
   zombie->eventMove(environment(who));
   zombie->eventForce("emote blinks its eyes open.");
   zombie->eventForce("speak You... rang...?");
   zombie->SetReligion(who->GetReligion());
   zombie->eventForce("follow "+ who->GetKeyName());
   who->eventForce("lead "+ zombie->GetKeyName());
   zombie->eventForce("guard " + who->GetKeyName());
   return 1;
  }
}

