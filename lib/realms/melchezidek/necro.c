/* 
 * Arcanith Necro leader
 * -mel 2019-01-31
 */

#include <lib.h>
#include <std.h>
inherit LIB_LEADER;

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

  SetAction(10,
     ({ "!emote straightens his robes.",
        "!emote inspects his hands inquisitively.",
        "!say Life... death... all but abstract states of being.",
        "!say Were the time right, we could bring new life to old bones.",
        "!say Should one raise a pet from a sentient being? Hmmm, tis'"
        "  an interesting question",
        "!emote inspects some vials.",
        "!cast umbral shield",
         }) );
  SetCombatAction(50, ([
    "cast pyre",
    "cast soultap",
    "cast poison explosion",
    "cast cremate",
    ]) );
  SetInventory( ([ STD_POLE  "staff" : "wield staff" ]) );
  SetLimit(1);
  SetPlayerTitles( ([
    "newbie" : "the Dirty Hand",
    "mortal" : "the Digger of Graves",
    "hm"     : "the Mortician",
    "legend" : "the Gardener of Bones",
    "avatar" : "the Osteologist",
    ]) );
  SetFreeEquipment( ([
    STD_POLE "staff" : 1,
    ]) );
  SetFirstCommands( ({
    "cast create frost armour",
    "wear all",
    "cast umbral shield",
  }) );
}