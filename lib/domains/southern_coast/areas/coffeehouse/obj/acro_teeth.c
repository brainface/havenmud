// mahkefel 2017
// broken nosferatu teeth necklace
// from acrobatics trainer
#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;

int DoWear();

static void create() {
  armour::create();
  SetKeyName("necklace made of teeth");
  SetId( ({ "necklace", "teeth" }) );
  SetAdjectives( ({ "teeth", "necklace","made","of" }) );
  SetShort("a necklace made of teeth");
  SetLong(
    "A simple bit of hemp twine strings its way through two dozen long cuspids "
    "and a pair of broken orc tusks. All the teeth show marks of violence--"
    "some are broken clean off the root, others have the point chipped away."    
  );
  SetDamagePoints(2000);
  SetValue(5000);
  SetMass(30);
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_AMULET);
  SetSize(SIZE_SMALL);
  SetMaterials( ({ "natural" }) );
  SetRepairDifficulty(50);
  SetProperty("history", 
    "Someone knocked the teeth right out of a half dozen nosferatu mouths, "
    "over a few decades. The tooth in the very center is a daemons, still "
    "radiating impotent malevolence."
  );
  SetProperty("magic", "A simple but potent fetish, used to display and "
    "enhance the wearer's durability compared to the defeated foes."
  );
  SetWear( (:DoWear:) );
}

int DoWield() {
  this_player()->AddStatBonus("durability", 10);
  send_messages( "tug",
    "Teeth%^YELLOW rattle ominously%^RESET%^ as $agent_name $agent_verb a "
    "necklace down around $agent_posessive neck.",
    this_player(), this_object(), environment(this_player())
  );
  return 1;
}

mixed eventUnequip(object who) {
  who->RemoveStatBonus("constitution", this_object());
  send_messages("pull",
    "Teeth%^YELLOW rattle discordantly%^RESET%^ as $agent_name $agent_verb a "
    "necklace off over $agent_posessive head.",
    who, this_object(), environment(who) );
  armour::eventUnequip(who);
}

