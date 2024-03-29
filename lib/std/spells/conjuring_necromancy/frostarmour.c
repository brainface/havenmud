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
 
 // from mel:
 // make it melt
 // refresh with subsequent casts?

#include <lib.h>
#include <magic.h>
#include <damage_types.h>
#include <dirs.h>
#include <armour_class.h>
#include <armour_types.h>
#include <std.h>
#include <conditions.h>
inherit LIB_SPELL;

string SPELL_CHANNEL = "Channeling Create Frost Armour";

// makes the armour object and forces target to wear it
int CreateFrostArmour(object who, object target, int AC, int armour_type, string quality, string thickness, string id, int durability, string limb );
// returns true if they have available slots to wear armour on said limb
int CanWearArmour(object target, string limb, int armour_type);
// stop the channeling cleanly
int EndChannel(object who);

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

int CanCast(object who, int level, mixed limb, object array targets) {
  object target;
  int success = 0;
  
  if (!sizeof(targets)) {
    who->eventPrint("You must target something with this spell!");
    return 0; 
  }
  target = targets[0];
  if (target == who 
   || target->GetOwner() == who->GetKeyName()
   || (member_array(target, who->GetPartyMembers()) != -1)) {
    return ::CanCast(who, level, limb, targets);
  } else {
    who->eventPrint(capitalize(target->GetName()) + " seems very uninterested in that!");
    who->eventPrint("You may only cast this spell on yourself, a creature you summoned or control, or a member of your party.");
    return 0; 
  }
}


varargs int eventCast(object who, int level, mixed n, object *t) {
  object target = t[0];
  string quality = "frosty";
  string thickness = "light";
  int durability = 100;
  int chilliness = who->GetSkillLevel("necromancy") + who->GetSkillLevel("ice magic") * GetSpellLevel() / 100;
  int AC = ARMOUR_LEATHER;
  object armour = 0;
  int channeling = 0;

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
    thickness = "moderately";
  } else if (durability < 2500) {
    thickness = "thick";
  } else if (durability < 5000) {
    thickness = "heavy";
  } else {
    thickness = "dense";
  }

  send_messages(GetMessage()[0],GetMessage()[1],who,target,environment(who));

  channeling = 0;
  who->AddCondition(SPELL_CHANNEL, CONDITION_PREVENT_MOVE|CONDITION_PREVENT_MAGIC|CONDITION_PREVENT_COMBAT, 3);
  foreach (string limb in target->GetLimbs()) {
    if (CanWearArmour(target, limb, A_HELMET)) {    
      channeling+=2;
      call_out( (: CreateFrostArmour, who, target, AC, A_HELMET, quality, thickness, "helm", durability, limb :), channeling );
    } else if (CanWearArmour(target, limb, A_ARMOUR)) {
      channeling+=2;
      call_out( (: CreateFrostArmour, who, target, AC, A_ARMOUR, quality, thickness, "cuirass", durability, limb :), channeling );
    } else if (CanWearArmour(target, limb, A_GLOVE)) {
      channeling+=2;
      call_out( (: CreateFrostArmour, who, target, AC, A_GLOVE, quality, thickness, "gauntlet", durability, limb :), channeling );
    } else if (CanWearArmour(target, limb, A_PANTS)) {
      channeling+=2;
      call_out( (: CreateFrostArmour, who, target, AC, A_PANTS, quality, thickness, "greave", durability, limb :), channeling);
    } else if (CanWearArmour(target, limb, A_BOOT)) {
      channeling+=2;
      call_out( (: CreateFrostArmour, who, target, AC, A_BOOT, quality, thickness, "boot", durability, limb :), channeling);
    } else if (CanWearArmour(target, limb, A_WING)) {
      channeling+=2;
      call_out( (: CreateFrostArmour, who, target, AC, A_WING, quality, thickness, "wing guard", durability, limb :), channeling );
    } else if (CanWearArmour(target, limb, A_TAIL)) {
      channeling+=2;
      call_out( (: CreateFrostArmour, who, target, AC, A_TAIL, quality, thickness, "tail", durability, limb :), channeling );
    }    
  }  

  if (channeling) {
    // hypothetically we should be able to time this right, in practice conditions
    // and callouts don't seem to be on the same timer, so i'm making the condition
    // longer than it should be and then making a call out end it.
    call_out( (: EndChannel, who :), channeling+1);
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
int CreateFrostArmour(object who, object target, int AC, int armour_type, string quality, string thickness, string id, int durability, string limb ) {
  object armour;                                                      

  // if we don't exist, oh god stop
  if (!who) {
    return 0;
  } 
  // if we're not channeling, stop this
  if ( !who->GetCondition(SPELL_CHANNEL) ) {
    return 0; 
  }
  // if the target doesn't exist, stop channeling
  if (!target) {
    EndChannel(who); 
    return 0;
  }
  
  // if the target isn't here, stop channeling 
  // (condition prevents caster movement but target can move)
  if (environment(target) != environment(who)) {
    EndChannel(who);
    return 0;
  }
  
  // make a new armor piece
  armour = new(STD_SPELLS "obj/fa_armour");
  armour->SetArmourClass(AC);
  armour->SetArmourType(armour_type);
  armour->SetAdjectives( ({quality, thickness}) );
  armour->SetShort("a "+ thickness + " " + quality + " " + id);
  armour->SetId( armour->GetId() + ({id}) );
  armour->SetMaxDamagePoints(durability);
  armour->SetSize(target->GetSize());

  // handle failed moves
  if (armour->eventMove(target)) {
    //debug("wear first "+id+" on "+limb);
    //debug(target->GetName());
    target->eventForce("wear first "+id+" on "+limb);
  } else {
    // if it doesn't move, assume weight is the reason. There could be other reasons,
    // so this may really need a better test/conditionals.
    send_messages("be", "$agent_possessive_noun burden is too great!", target, 0, who);
    armour->eventDestruct();
    EndChannel(who);
    return 0;
  }
  
  // handle exhaustion
  who->AddStaminaPoints(-10);
  if (who->GetStaminaPoints() < 50) {
    who->eventPrint("You are too exhausted to continue channeling!");
    EndChannel(who);
    return 0;
  } else {
    who->eventPrint("The conjuring drains you!");
  }
  who->AddCondition(SPELL_CHANNEL, CONDITION_PREVENT_MOVE|CONDITION_PREVENT_MAGIC|CONDITION_PREVENT_COMBAT, 1);
  
  return 1;
}

// force the channel to end
// note that this may be called after something ELSE has forced the channel end.
// possibly a different cast! that could be bad. or at least irritating.
int EndChannel(object who) {
  if (who->GetCondition(SPELL_CHANNEL)) {
    who->eventPrint("You stop channeling Create Frost Armour.");
    who->RemoveCondition("Channeling Create Frost Armour");
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

