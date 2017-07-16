#include <lib.h>
#include "../dalnairn.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("citizen");
  SetId( ({ "citizen", "dalnairn_people" }) );
  SetShort("a citizen of Dalnairn");
  SetLong(
    "This citizen of Dalnairn is a Duergar, a race quite similar to "
    "the Dwarves. He seems content with his life, admiring and taking "
    "pride in his city as he strolls along."
  ); 
  SetFriends("dalnairn_people");  
  SetRace("dwarf");
  SetGender("male");  
  SetClass("warrior");
  SetLevel(random(10)+1);
  SetReligion("Soirin");
  SetMorality(-100);   
  SetCurrency("shards", random(30));  
  SetWander(5);
  SetAction(2, ({
    "!speak I love our city. The mayor goes out of his way to make it "
    "so beautiful.",
    "!speak I hear Drostan has been busy working on some new weapons.",    
    "!speak Are you new here? You must try our whisky. Best on the "
    "continent!",
    "!emote looks deep in thought."
  }) );
  SetInventory( ([
         DAL_OBJ + "pants": "wear pants",
         DAL_OBJ + "shirt" : "wield shirt",
         DAL_OBJ + "shoes" : "wear shoes",
  ]) );
}