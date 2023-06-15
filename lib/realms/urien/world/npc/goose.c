// A goose, proposed by Mahkefel
// Not using modern citystate names "Canadian"
// Urien@Haven 13JUN2023

#include <lib.h>
#include <std.h>
#include "../world.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("goose");
  SetId( ({ "goose", "bird"}) );
  SetAdjectives( ({ "brown" }) );
  SetRace("bird","goose");
  SetClass("animal");
  SetGender("female");
  SetLevel(random(7) + 2);
  SetShort("a brown goose");
  SetLong("The dark brown bird has a pattern that lacks any actual "
          "symmetry in design, more to blend into a conifer setting "
          "vice blue skies or any open water. The thin brown beaks "
          "colour is flush with the head feathers down to the wingspan "
          "and neck area. An almost dried woodland leaf colour ensemble "
          "fills in the rest of feathers. Dark and muddy webbed feet "
          "match the black eyes of this almost overweight bird.");
  SetAction(2, ({
     "Goose surveys the environment, pecking the ground.",
     "The brown goose honks a noisy peal almost like a laughter.",
     "The goose goes: HONK!",
     }) );
}
