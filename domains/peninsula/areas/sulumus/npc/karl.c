// Proximo@Pax Imperialis
// 06/19/2003

#include <lib.h>
#include <std.h>
#include <vendor_types.h>
#include "../sulumus.h";

inherit LIB_BARKEEP;

void TheyEnter();

static void create() {
  ::create();
  SetKeyName("karl");
  SetId( ({ "karl", "vendor", "we_wander" }) );
  SetAdjectives( ({ "the", "vendor", "of" }) );
  SetShort("Karl the Vendor of Fruits and Vegetables");
  SetLong(
     "This strapping young fellow is the vendor of fruits and vegetables for this "
     "center of trade. He has light blonde hair and strong thick arms with a "
     "keen eye for great quality in fruits and vegetables. "
  );
  SetRace("human"); SetBaseLanguage("Imperial");
  RemoveLanguage("Human");
  SetLanguage("Imperial", 100, 1);
  SetGender("male");
  SetClass("merchant");
  SetMorality(5);
  SetMenuItems( ([
     "red apple" : S_OBJ + "rapple",
     "green apple" : S_OBJ + "gapple",
     "green cabbage" : S_OBJ + "cabbage",
     "orange carrot" : S_OBJ + "carrot",
  ]) );
  SetSkill("bargaining", 1, 2);
  SetLevel(3+random(3));
  SetInventory( ([
     S_OBJ + "overalls" : "wear overalls",
     S_OBJ + "dshirt" : "wear shirt",
  ]) );
  SetLimit(1);
  SetLocalCurrency("imperials");
  SetEncounter( (: TheyEnter :) );
}

void TheyEnter() {

  if (random(100) > 90) {
     eventForce("say Hello there! Looking for fresh and tasty fruits and vegetables?");
  }
}
