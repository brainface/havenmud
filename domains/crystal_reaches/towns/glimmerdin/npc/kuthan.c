#include <lib.h>
#include <std.h>
#include "../path.h"
inherit LIB_LEADER;

static void create() {
	::create();
	SetKeyName("Kuthan OrcsBane");
	SetShort("Kuthan OrcsBane, Knight Commander of Glimmerdin");
	SetId( ({ "kuthan", "orcsbane", "knight", "commander", "glim_wander" }) );
	SetAdjectives( ({ "kuthan", "knight" }) );
	SetFriends( ({ "glim_wander", "dwarf"}) );
	SetLong(
	  "Kuthan OrcsBane is the Knight Commander of Glimmerdin. His role as "
	  "supreme military authority derives from the respect of the City and "
	  "his role as a war hero during the last large scale combat against the "
	  "orcs of Karak Varn. Anyone interested in joining the Knighthood should "
	  "<ask kuthan to join cavaliers>."
	  );
	SetRace("dwarf");
	SetGender("male");
	SetClass("cavalier");
	SetLevel(80);
	SetFreeEquipment( ([
	  STD_SLASH  "shortsword"    : 1,
	  STD_PIERCE "fencing_sword" : 1,
	  ]) );
	SetTown("Glimmerdin");
  SetMorality(2500);
	SetPlayerTitles( ([
	  "newbie" : "the Squire of Glimmerdin",
	  "mortal" : "Sir $N the Knight of Glimmerdin",
	  "hm"     : "Lord $N the Knight of Glimmerdin",
	  "legend" : "Commander $N the Knight of Glimmerdin",
	  "avatar" : "Lord Commander $N the Knight-Templar of Glimmerdin",
          "priest" : "Sir $N the Paladin of the Knights Templar of Glimmerdin",
	  ]) );
	SetInventory( ([
	  G_OBJ "chainmail"         : "wear chainmail",
	  G_OBJ "church_tabard"     : "wear tabard",
	  G_OBJ "mithril_sword"     : "wield sword",
	  G_OBJ "mithril_shield"    : "wear shield on right arm",
	  G_OBJ "mithril_gauntlets" : "wear gauntlets",
	  G_OBJ "m_boots"					  : "wear boots",
	  ]) );
	SetAction(5, ({
		"!speak For the Glory of the Faith, we defend!",
		"!speak You should <ask me to join cavaliers>!",
		"Kuthan stares into the heavens and prays.",
	}) );

}
