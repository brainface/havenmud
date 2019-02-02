/* 
 * Arcanith Necro leader
 * -mel 2019-01-31
 */

#include <lib.h>
#include <std.h>
#include "../ruins.h"
inherit LIB_LEADER;
//void DoStuff();

static void create() {
  ::create();
  SetKeyName("Rocklock");
  SetId( ({ "rocklock", "necromancer", "bonecaster" })  );
  SetAdjectives( ({ "clean", "well groomed", "white", "large", }) );
  SetShort("Rocklock the Bone Caster");
  SetLong("This is a relatively large and well groomed kobold."
          " His visible fur is a bright white with shades of"
          " soft pink skin escaping in some of the thinner"
          " areas such as around his snout. In contrast to"
          " most kobolds he is clean and exhibits a"
          " fastidiousness more common with other species.");
  SetRace("kobold");
  SetBaseLanguage("Koblich");
  SetTown("Arcanith");
  SetClass("necromancer");
  SetLevel(125);  /* Why shouldn't he be a badass? Fight me. */
  SetGender("male");
  SetMorality(0);

  /* SetAction(10, (: DoStuff :)); */
  SetAction(10,  ({ 
        "!emote straightens his robes.",
        "!emote inspects his hands inquisitively.",
        "!say Life... death... all but abstract states of being.",
        "!say Were the time right, we could bring new life to old bones.",
        "!say Should one raise a pet from a sentient being? Hmmm, tis'"
        " an interesting question",
        "!emote inspects some vials.",
        "!cast umbral shield",
         }) );
  SetCombatAction(50, ({
    "cast pyre",
    "cast soultap",
    "cast poison explosion",
    "cast cremate",
    "cast umbral shield",
    }) );
  SetInventory( ([ 
    OBJ  "/necro_staff" : "wield staff in left hand and right hand",
    OBJ  "/necro_robe" : "wear robe" ]) );
  SetLimit(1);
  SetPlayerTitles( ([
    "newbie" : "the Dirty Hand",
    "mortal" : "the Digger of Graves",
    "hm"     : "the Mortician",
    "legend" : "the Gardener of Bones",
    "avatar" : "the Osteologist",
    "fighter": "the Bone Warden",
    ]) );
  SetFreeEquipment( ([
    STD_POLE "staff" : 1,
    ]) );
  SetSpellBook( ([
    "soultap": 100,
    "create frost armour": 100,
    "umbral shield": 100,
    "poison explosion": 100,
    "cremate": 100,
    "pyre": 100,
  ]) );
  SetFirstCommands( ({
    "cast umbral shield",
    "cast create frost armour",
  }) );
  SetSkill("ice magic",250,1);
  SetSkill("armour smithing", 200, 2);
  SetSkill("natural working", 200, 2);
}

/* mahk said he'd fix it so frost armour doesn't deteriorate for
 * non-players, so commenting out - mel 
 */
/*
void DoStuff() {
 array generic_options = ({
        "emote straightens his robes.",
        "emote inspects his hands inquisitively.",
        "say Life... death... all but abstract states of being.",
        "say Were the time right, we could bring new life to old bones.",
        "say Should one raise a pet from a sentient being? Hmmm, tis'"
        " an interesting question",
        "emote inspects some vials.",
        "cast umbral shield",
  });
 if (random(2)) {
   foreach(object ob in GetWorn()[1]) {
     if (ob->GetDeterioration()) {
      eventForce("repair " + ob->GetKeyName());
     }
   }
 } else {
  string result =  generic_options[random(sizeof(generic_options))];
  eventForce(result);
 }
}
*/
