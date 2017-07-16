// A giant, mithril bong, made for Torak and himself
// Since we can no longer be lazy stoners
// Profanity included in this wiz toy, not for mortals
// Urien@Haven   10.27.12

#define WORKROOM "/realms/urien/workroom/"

#include <lib.h>
#include <meal_types.h>

inherit LIB_ITEM;
inherit LIB_MEAL;

int DoSmoke();

static void create() {
  meal::create();
  SetKeyName("bong");
  SetId( ({ "bong" }) );
  SetAdjectives( ({ "giant", "mithril"}) );
  SetShort("a giant mithril bong");
  SetLong("This bong was made by the greater beings of our world. "
          "With unknown technology and some water, this has been "
          "deemed a great invention. The bong's bowl has a never "
          "ending supply of catnip that never burns. Attached to "
          "the side of the bong is a lighter to 'Smoke on !1!!!11!'\n "
          "  To use this bong you must 'light' it, while it is hot "
          "you then 'smoke' it. It looks so awesome, you cant wait "
          "to turn it black!");
  SetMealType(MEAL_SMOKE | MEAL_CAFFEINE);
  SetStrength(6);
  SetPortions(8);
  SetValue(20);
  SetMass(2);
  SetMealMessages( (: DoSmoke :) );
/*    
    "You grab the lighter and light the bowl inhaling slowly...\n"
    "You take a big ass hero rip off the giant mithril bong!\n\n"
    "FEELS GOOD MAN!",
    "$N lights $P bong then inhales a massive cloud of smoke from "
    "the giant mithril bong then blows it in your face!\n"
    "What an asshole! Tell $P ass to pass that shit!"
   );
*/
}

int DoSmoke() {
  if(!creatorp(this_player())) {
    message("system","Sorry, immortal fun only bud!",
    this_player());
    return 0;
  }
  else
  {
    send_messages( ({ "smoke","hit" }), "$agent_name $agent_verb "
    "test test test!",
    this_player(), 0, environment(this_player()));
    this_player()->eventForce("laugh");
    return 1;
    }
 }
