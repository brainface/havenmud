// My throne, WHERE'S YOUR CROWN KING NOTHINGGGGG?
// Special code included for us immortals.
// Still cant sit, Immortals have no bodies.

#include <lib.h>
#include <vendor_types.h>

inherit LIB_ITEM;
inherit LIB_SIT;

int DoSit();

static void create() {
  item::create();
  SetKeyName("throne");
  SetId( ({ "throne" }) );
  SetAdjectives( ({ "ancient" , "frozen"}) );
  SetShort("an ancient frozen throne" );
  SetLong( "This throne has been created with strong and sturdy metal "
           "frame and its backrest reaches roughly ten feet from the "
           "seat. Four equal sized pegs stand out from the bottom "
           "of the chair to support weight. It appears quite heavy "
           "and well crafted. On the surface of the throne is a solid "
           "layer of frost and ice which has built up from the elements. "
           "The carvings in the metal match the intricate design on the "
           "platform it currently rests on.");
  SetMass(150);
  SetMaterial( ({ "metal", "wood" }) );
  SetPreventGet("It is sealed to the floating platform!");
  SetMaxSitters(1);
//  Set( (: DoSit :), SIT_IN);
}

int DoSit() {
  if(!creatorp(this_player())) {
    message("system","Immortals can only sit on this throne, noob!",
    this_player());
    return 0;
  }
  else
  {
    send_messages( ({ "sit" }), "$agent_name $agent_verb "
    "on the throne and shudders as pure evil envelopes him!",
    this_player(), 0, environment(this_player()));
    this_player()->eventForce("shudder");
    return 1;
    }
 }

