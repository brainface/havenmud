// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <std.h>
#include "../karak.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("varag");
  SetId( ({ "varag", "shaman", "orc"}) );
  SetShort("Varag the Devoted Diabolist of Saahagoth");
  SetLong(
    "Varag is an usually tall orc with the bright light of zeal gleaming "
    "in his eyes. He alternates between scanning the area in front of him "
    "and looking towards the heavens, as if gather inspiration. Despite "
    "his religious fervor he seems focused on things around him when not "
    "gazing upwards. He gives off an aura of ready competence and leashed "
    "potential."
  );
  SetRace("orc");
  SetGender("male");
  SetClass("shaman");
  SetSkill("fire magic",1,2);
  SetSkill("enchantment",1,1);
  SetTown("Karak");
  SetReligion("Saahagoth", "Saahagoth");
  SetMorality(-1500);
  AddUniqueSkills( ([
    "blunt combat" : 0,
    "hack combat"  : 1,
  ]) );
  SetLevel(60);
  SetPlayerTitles( ([
    "newbie"   : "the Saahagoth Faithful",
    "mortal"   : "the Saahagoth Crusader",
    "hm"       : "the Master Weirder of Saahagoth",
    "legend"   : "the Holy Weirder of Saahagoth",
    "avatar"   : "the Zealot of the True Faith",
  	]) );
  SetInventory( ([
    KARAK_OBJ + "bflail" : "wield flail",
    KARAK_OBJ + "runea"  : "wear armour"
  	]) );
/*
  SetFreeEquip( ([
    KARAK_OBJ + "studded_leather" : 1,
    STD_HACK + "hand-axe" : 1,
  ]) );
*/
  SetSpellBook( ([
		"vampiric touch"   	 : 100,
		"wither"				   	 : 100,
		"veil from beyond" 	 : 100,
		"hellfire"				 	 : 100,
		"disintegrate"     	 : 100,
		"divine retribution" : 100,	
		"wall of souls"			 : 100,
		"cause bleeding"     : 100,	
  	]) );
  SetCombatAction(50, ({
    "!cast vampiric touch",
    "!cast hellfire",
    "!cast wither",
    "!cast veil from beyond",
    "!cast distinegrate",
    "!cast cause bleeding",
    "!cast divine retrubution",
    "!cast wall of souls",
    }) );
  SetFirstCommands( ({
  	"cast wall of souls",
  	"cast wall of souls",
  	"cast veil from beyond",
  	}) );
}
