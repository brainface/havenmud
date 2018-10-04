/* Create Frost Armour
 *
 * Literal conjured armour made of snow
 * Main purpose is quickly and easily armouring animated dead
 * but will also armour the caster.
 *
 * Armour tier and durability are level dependant--like create undead, this
 * spell is intended to scale to max level, there will be no
 * "greater frost armour" et al.
 * Mahkefel 20whothefuckknows
 * troubleshot by duuk sometimeoranother
 */

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <dirs.h>
#include <armour_class.h>
#include <armour_types.h>
#include <std.h>

inherit LIB_SPELL;

// makes the armour object and forces target to wear it
int CreateFrostArmour(object who, object target, int AC, int armour_type, string quality, string thickness, string id, int durability,
string limb );
// returns true if they have available slots to wear armour on said limb
int CanWearArmour(object target, string limb, int armour_type);

static void create() {
spell::create();
  SetSpell("create frost armour");
  SetRules("", "LIV");
  SetSpellType(SPELL_OTHER);
  SetRequiredMagic(200);
  SetSkills( ([
    "conjuring"  : 25,
    "necromancy" : 25,
  ]) );
  SetMagicCost(100, 5);
  SetStaminaCost(100, 5);
  SetDifficulty(10);
  SetMorality(0);
  SetMessages( ({
     ({ ({"bring"}), "$agent_name $agent_verb $agent_possessive hands together "
       "facing $target_name as a %^BOLD%^BLUE%^cone of frost%^RESET%^ %^BOLD%^"
       "CYAN%^erupts%^RESET%^ from them and begins coating $target_name in a "
       "fine layer of ice!" }),
  }) );
  SetHelp(
    "A somewhat subtle development by the usually more straightforward "
    "reavers of Keryth, this spell diverts otherwise quite lethal necrotic "
    "energies to the air around a target, forming a semi-permanent fascimile "
    "of armour. Very skilled ice savants can produce suits of armour that "
    "rival the finest smiths, but a novice necromancer must settle for "
    "something like chilly leathers." );
}


varargs int eventCast(object who, int level, mixed n, object *t) {
  object target = t[0];
  string quality = "frosty";
  string thickness = "light";
  int durability = 100;
  int chilliness = who->GetSkillLevel("necromancy") + who->GetSkillLevel("ice magic") * GetSpellLevel() / 100;
  int AC = ARMOUR_LEATHER;
  object armour = 0;
  int exhaust = 0;
  int weMadeAnyArmour = 0;

  // roughly equal level of mage
  chilliness /= 2;

  // half as effective on non-undead.
  if (!target->GetUndead()) chilliness /= 2;

  // decide what tier of armour we're creating
  // t7
  if (chilliness > 400 && who->GetSkillLevel("heavy plate armour") > 1) {
    quality = "glacial";
    AC = ARMOUR_HEAVY_PLATE;
  // t6
  } else if (chilliness > 250 && who->GetSkillLevel("plate armour") > 1) {
    quality = "icy";
    AC = ARMOUR_PLATE;
  // t5
  // currently impossible
  } else if (chilliness > 100 && who->GetSkillLevel("chain armour") > 1) {
    quality = "slushy";
    AC = ARMOUR_CHAIN;
  // t4
  } else if (chilliness > 50 && who->GetSkillLevel("natural armour") > 1) {
    quality = "snowy";
    AC = ARMOUR_NATURAL;
  // t3
  } else if (chilliness >  25 && who->GetSkillLevel("reinforced armour") > 1) {
    quality = "hoarfrost";
    AC = ARMOUR_REINFORCED;
  // t2
  } else {
    quality = "frosty";
    AC = ARMOUR_LEATHER;
  }

  // max 5k level 500, 10k w/ max ice magic
  durability = chilliness * 10;

  if (durability < 500) {
    thickness = "thin";
  } else if (durability < 1000) {
    thickness = "moderate";
  } else if (durability < 2500) {
    thickness = "thick";
  } else if (durability < 5000) {
    thickness = "heavy";
  } else {
    thickness = "dense";
  }

  send_messages(GetMessage()[0],GetMessage()[1],who,target,environment(who));

  foreach (string limb in target->GetLimbs()) {
    exhaust = 0;
    if (CanWearArmour(target, limb, A_HELMET)) {
      exhaust++;
      CreateFrostArmour(who, target, AC, A_HELMET, quality, thickness, "helm", durability, limb );
    } else if (CanWearArmour(target, limb, A_ARMOUR)) {
      exhaust++;
      CreateFrostArmour(who, target, AC, A_ARMOUR, quality, thickness, "cuirass", durability, limb );
    } else if (CanWearArmour(target, limb, A_GLOVE)) {
      exhaust++;
      CreateFrostArmour(who, target, AC, A_GLOVE, quality, thickness, "gauntlet", durability, limb );
    } else if (CanWearArmour(target, limb, A_PANTS)) {
      exhaust++;
      CreateFrostArmour(who, target, AC, A_PANTS, quality, thickness, "greave", durability, limb );
    } else if (CanWearArmour(target, limb, A_BOOT)) {
      exhaust++;
      CreateFrostArmour(who, target, AC, A_BOOT, quality, thickness, "boot", durability, limb );
    } else if (CanWearArmour(target, limb, A_WING)) {
      exhaust++;
      CreateFrostArmour(who, target, AC, A_WING, quality, thickness, "wing guard", durability, limb );
    } else if (CanWearArmour(target, limb, A_TAIL)) {
      exhaust++;
      CreateFrostArmour(who, target, AC, A_TAIL, quality, thickness, "tail", durability, limb );
    }

    if (exhaust) {
      // drain some stamina
      who->AddStaminaPoints(-10);
      if (who->GetStaminaPoints() < 50) {
        who->eventPrint("You are too exhausted to continue channeling!");
      break;
      } else {
        who->eventPrint("The conjuring drains you!");
      }
      weMadeAnyArmour += exhaust;
    }
  }

  if (weMadeAnyArmour) {
    // pass
  } else {
    send_messages("wring","$agent_name $agent_verb $agent_possessive hands at "
      "$target_name and mutters things, but nothing much happens.",
      who,target,environment(who));
    who->eventPrint("Your target cannot wear armour or is already wearing armour everywhere!");
  }
}

int CanWearArmour(object target, string limb, int armour_type) {
  int canWear = 0;
  if (target->GetLimb(limb) && target->GetLimb(limb)["armours"]&armour_type) {
    canWear = 1;
      foreach (object wornArmour in target->GetWorn(limb)) {
        if (wornArmour->GetArmourType() == armour_type && wornArmour->GetArmourClass() > ARMOUR_CLOTH) {
          canWear = 0;
        }
      }
  }
  return canWear;
}


/*  Mahk code block
 * makes the armour and makes the target wear the armour--
 * this may be done exactly the wrong way in some manner or another
 * iirc also there is a setnosave function--currently this shit saves perfectly and that took forever
 * to make happen, but it's not really in theme with snowflake armour
 */
int CreateFrostArmour(object who, object target, int AC, int armour_type, string quality, string thickness, string id, int durability,
string limb ) {
  object armour;
  debug ("creating: " + limb);
  armour = new(STD_SPELLS "obj/fa_armour");
  armour->SetArmourClass(AC);
  armour->SetArmourType(armour_type);
  armour->SetAdjectives( ({quality, thickness}) );
  armour->SetShort("a "+ thickness + " " + quality + " " + id);
  armour->SetId( armour->GetId() + ({id}) );
  armour->SetMaxDamagePoints(durability);
  armour->SetSize(target->GetSize());

  debug("checking armour:");
  debug(armour->GetId()[0]);

  debug(identify(armour));
  if (armour->eventMove(target)) {
    target->eventForce("wear first "+id+" on "+limb);
  } else {
    // if it doesn't move, assume weight is the reason. There could be other reasons, 
    // so this may really need a better test/conditionals.
    send_messages("be", "$agent_possessive_noun burden is too great!", target, 0, who);
    armour->eventDestruct();
  }
  return 1;
}


// this is the code duuk said to use, which isn't working in a different way but may
// but the preferred way it should actually be handled.
// duukcode was also suffering from the "they're carrying too much for move" issue, but
// was also causing runtimes with the armour command. Not sure why.
/*
int CreateFrostArmour(object target, int AC, int armour_type, string quality, string thickness, string id, int durability,
string limb ) {
  object armour;
  debug ("creating: " + limb);
  armour = new(STD_SPELLS "obj/fa_armour");
  armour->SetArmourClass(AC);
  armour->SetArmourType(armour_type);
  armour->SetAdjectives( ({quality, thickness}) );
  armour->SetShort("a "+ thickness + " " + quality + " " + id);
  armour->SetId( armour->GetId() + ({id}) );
  armour->SetMaxDamagePoints(durability);
  armour->SetSize(target->GetSize());

  debug("armour object: " + identify(armour));
  if (armour->CanEquip(target, limb)) {
    debug("CanEquip " + limb);
    armour->eventMove(target);
    armour->eventEquip(target, ({ limb }) );
    debug("Environment of armour after eventMove:" + identify(environment(armour)));
  } else {
    debug("failed to CanEquip " + limb);
    armour->eventDestruct();
  }
  debug("CanEquip success - checking for Worn");
  if (member_array(armour, target->GetWorn(limb)) == -1) debug("Did not wear it.  No really.");
  return 1;
}
*/
