// dirty tricks dude knife
//   gives bonuses to knife combat, dirty tricks
//   note that the player cannot see skill bonuses at this time.
//   skill bonuses shouldn't fuck up leveling, etc.

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

int DoWield();
int CheckWield();

static void create() {
  item::create();
  SetKeyName("switchblade");
  SetId( ({ "knife","switchblade" }) );
  SetAdjectives( ({ "spring-loaded", "spring", "loaded" }) );
  SetShort("a spring-loaded switchblade");
  SetLong(
    "This steel knife, shorn of all decorations, has "
    "some clever mechanism allowing it to fold into the "
    "mahogany handle and spring back out with a slight motion. "
    "The blade itself looks rusted and stained, though the "
    "edge is quite sharp."
  );
  SetClass(40);
  SetDamagePoints(4000);
  SetValue(15000);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetMass(50);
  SetMaterial( ({ "metal" }) );
  SetProperty("magic",
    "You feel an intense headache as you try to analyze the dweomers "
    "on the enchanted blade, then feel all desire to "
    "scrutinize the obviously mundane weapon leave your mind."
  );
  SetProperty("history",
    "You can't seem to recall any lore or legend on this knife, even "
    "though it is obviously distinctive, and it seems like someone "
    "would have mentioned it."
  );
  SetRepairSkills( ([
     "metal working" : 75,
     "weapon smithing" : 75,
  ]) );
  SetRepairDifficulty(75);
  SetVendorType(VT_WEAPON);
  SetWield( (:DoWield:) );
}

int DoWield() {
  send_messages("",
    "$agent_possessive_noun switchblade springs open with a quick flick "
    "of $agent_possessive wrist.",
    this_player(), this_object(), environment(this_player()) );
  this_player()->AddSkillBonus("dirty tricks", (: CheckWield :) );
  return 1;
}

int CheckWield() {
  //if (previous_object()->GetSkillLevel("dirty tricks")) {
    return 20;
  //} else {
  //  return 0;
  //}
}

mixed eventUnequip(object who) {
  who->RemoveSkillBonus("dirty tricks", this_object());
  send_messages( ({"fold","store"}),
    "$agent_name calmly $agent_verb $agent_possessive switchblade and "
    "$agent_verb it out of sight.",
    who, this_object(), environment(who) );
  item::eventUnequip(who);
}

